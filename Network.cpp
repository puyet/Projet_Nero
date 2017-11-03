#include "Network.hpp"
#include <cassert>
#include <random>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std; 

//////////////////////////////////////////////////////////////
//															//
//				Constructors and Destructors				//
//															//
//////////////////////////////////////////////////////////////

//Constructor : initialise the collection of neurons and the map of connexions between the neurons 
Network::Network ()
:neurons_(), mapConnexion_(N,vector<int>())
{
	cout<<"constructor"<<endl; 
	//table qui affiche les neurons spikeurs (1ere colone) qui affiche les neurons qu'il spike 
	//1. Fill the vector of neurons (reminder N=12500) 
	for(int i(0); i<Ne; ++i){
		//Neuron neuron; 
        //addNeurons(neuron);
        cout<<"neuronavant"<<neurons_.size()<<endl; 
        neurons_.push_back(Neuron(E));
		cout<<"apres"<<neurons_.size()<<endl; 
	}
	for(int i(0); i<Ni; ++i) {
		
		neurons_.push_back(Neuron(I));
		cout<<"n"<<neurons_.size()<<endl; 
		}
		
	int bla(0); 
	for(unsigned long int i(0); i<neurons_.size(); ++i){
		for(unsigned long int E(0); E<Ce; ++E) {
			
			static random_device rd;  //Will be used to obtain a seed for the random number engine
			static mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			static uniform_int_distribution<> dis(0, (Ne-1)); //calcul the random uniform distribution 
			//int r = 0;
			//do {
				//r = dis(gen);
			//}while (r == c);
	  //return r;
	  
			mapConnexion_[dis(gen)].push_back(i); 
			}
		for (unsigned long int I(0); I<Ci; ++I){
			
			static random_device rd;  //Will be used to obtain a seed for the random number engine
			static mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			static uniform_int_distribution<> dis(Ne, ((Ne+Ni)-1)); //calcul the random uniform distribution 
			
			mapConnexion_[dis(gen)].push_back(i); 	
		}
	
	++ bla; 
	cout<<bla<<endl; 
	}
	
	//2. Fill the map of Connexions 
	/*for(unsigned long int i(0); i<neurons_.size(); ++i) {
		
		//Connexions with excitator neurons (random choice) (reminder Ce=Ne/10 and Ne=0.8*N) 
		for(int E(0); E<Ce; ++E){ 
			mapConnexion_[i][randomSelection(0,(Ne-1))] +=1; 	
		}
		//Connexions with inhibitor neurons (random choice) (reminder Ci=Ni/10 and Ni=0.2*N)
		for (int I(0); I<Ci; ++I){	
			mapConnexion_[i][randomSelection(Ne,Ne+Ni-1)] +=1;
		}
		* }
	*/
}

	
//Default destructor 
Network::~Network(){}
	
		
//////////////////////////////////////////////////////////////
//															//
//						Main functions 						//
//															//
//////////////////////////////////////////////////////////////

int Network::randomSelection (int a, int b, int c) {
	
	static random_device rd;  //Will be used to obtain a seed for the random number engine
    static mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    static uniform_int_distribution<> dis(a, b); //calcul the random uniform distribution 
    int r = 0;
	do {
		r = dis(gen);
	}while (r == c);
	  return r;
}
//update the network by fill the buffers of neurons with Jtot and call the update method for the neuron 
void Network::update_network(){
	//cout<<"UPDATE"<<endl; 
	//yolo ca marhce
	//neurons_[3].update_neuron(Iext); 
	/*ofstream data; 
	data.open("spikesTable.txt"); 
	if (data.fail()) {
		
		cout<<"Error opening SpikeTable file"<<endl; 
	}
	else {	
		cout<<"YES"<<endl; 
		*/
	//cout<<"networkupdate"<<endl; 
	for(size_t j(0); j<neurons_.size(); ++j){
		//cout<<j<<endl;
		//Jtot is the storage of the total amplitude J (sum of every connexion and specified for excitator or inhibitor) which will be givent to the neuron spiked
		//double Jtot(0); 
		//neurons_[j].update_neuron(Iext);
		//
		if(neurons_[j].update_neuron(Iext)){
		
		//data<<(neurons_[j].getSpikes()[j]) <<"\t"<<j<<"\n";
		//for(int E(0); E<Ne; ++E){
			//if(neurons_[E].getisSpiking()==true){
				for(size_t i(0); i<mapConnexion_[j].size(); ++i){
					
					int Connex(mapConnexion_[j][i]);
					//cout<<mapConnexion_[j].size()<<endl; 
					if(neurons_[j].isExcitatory()){
						//cout<<"spike"<<endl; 
						neurons_[Connex].setBuffer(neurons_[Connex].getLocalClock()+D, Je);
						//cout<<"NIQUE"<<endl; 
						
					}
					else{
						neurons_[Connex].setBuffer(neurons_[Connex].getLocalClock()+D, Ji);
						//cout<<neurons_.size()<<endl;
						}
						
				
				}
		}
		
	}
	
	printSpikeTimes(); 
	
}			/*neurons_[mapConnexion_[E][i]].setBuffer(neurons_.at(mapConnexion_[E][i]).getLocalClock()+D, Je); 
					}
				//neurons_[i].setBuffer(neurons_[i].getLocalClock()+D, Jtot); 
			}
				
		for (int I(Ne); I<N; ++I){
			
			//if(neurons_[I].getisSpiking()==true){
				for(size_t i(0); i<mapConnexion_[I].size(); ++i){
					neurons_[mapConnexion_[I][i]].setBuffer(neurons_[mapConnexion_[I][i]].getLocalClock()+D, Ji); 
				}	
			}/	
		}
		//if(neurons_[j].update_neuron(Iext)){}
		//cout<<"update of "<<j<<endl; 
		//printNeuronSpikes(); 
	}
}
*/
//method which run the simulation of a network and its neurons évolute with the RealTime	
void Network::simulation(){
	 
	
	/*cout<<"Preparing the simulation... "<<endl; 
	cout<<""<<endl; 
	//print some infos:
	cout<<"Network number of neurons: "<<neurons_.size()<<endl;
	cout<<""<<endl; 
	cout<<"Simulation time: "<<t_stop/10<<" ms"<<endl;
	cout<<""<<endl; 
	cout<<"Step time: "<<RealTime_/10<<" ms"<<endl;
	cout<<""<<endl; */ 
	
	while (RealTime_< t_stop){
		//cout<<"simu"<<endl;
		update_network(); 
		//printNeuronSpikes(); 
		++RealTime_; 
	}
}
//add neurons in the collection of neurons 
void Network::addNeurons(Neuron newNeuron){
	
	neurons_.push_back(newNeuron);
}

/*vector<vector<unsigned int> > Network::getRandomSpikes(int realTime, int tStop) const{
	
	unsigned int size_counter(realTime/tStop); 
	
	vector<unsigned int> counter(size_counter); 
	//Loop for all the neurons
	for(auto neur: neurons_){
		
		//Loop on all the spikes sent by the neuron 
		
		}
	
	}
		
vector<unsigned int> Network::getCounterSpikes(int realTime, int tStop) const{}
		
*/
//////////////////////////////////////////////////////////////
//															//
//						Display fuctions	 				//
//															//
//////////////////////////////////////////////////////////////	

//print the neurons with their indexes 		
void Network::printNeurons()
{
	cout << "---Neurons---" << endl << endl;
	
	for (size_t i(0); i<N; ++i){
		cout << "N" << i << endl;
	}		
	cout << endl << endl;
}

//print the mapConnexion of the neurons (CARREFULL DOESN'T WORK WITH BIG TOO BIG NUMBER OF NEURONS, 13 IS GOOD) 
void Network::printMapConnexion()
{
	cout << "---Connection Map---" << endl << endl;
	cout << "   ";
	for (size_t j(0); j<N; ++j){
		cout << "N" << j << "  ";
	}
	cout << endl;
 
	for (size_t i(0); i<N; ++i) {
		cout << "N" << i;
		for (size_t j(0); j<mapConnexion_[i].size(); ++j){
			cout << " " <<mapConnexion_[i][j] << "  ";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

void Network::printNeuronSpikes(){
		for (size_t i(0); i<neurons_.size(); ++i) {
			//cout<<"cia1"<<endl;
			//cout << "PotentialOf "<<i<<" = "<< neurons_[i].getMemb_pot() << " at time : " << RealTime_<<"ms"<<endl;
		
		for(size_t j=0; j< neurons_[i].getNumbSpikes(); j++) {
			//cout<<"cia"<<endl; 
			cout<<"spike from N"<<i;
			cout<<"at "<<neurons_[i].getTimeForSpike(j)/10<<" s"<<endl; 
			//cout << "Potential = "<< neurons_[i].getMemb_pot() << " at time : " << RealTime_/10<<"ms"<<endl;
			//cout<<"numberofSpikes"<<neurons_[i].getNumbSpikes()<<endl; 
			} 
	}
}

void Network::printSpikeTimes(){
	
	ofstream data; 
	data.open("spikesTable.txt"); 
	if (data.fail()) {
		
		cout<<"Error opening SpikeTable file"<<endl; 
	}
	else {	
		//cout<<"YES"<<endl; 
		for(int i(0); i<N; ++i){
			for(size_t j(0); j<neurons_[i].getSpikes().size(); ++j) {
				//cout<<"FUCK"<<endl; 
				data<<(neurons_[i].getSpikes()[j])/10 <<"\t"<<i<<"\n";
				}
		}
	
	data.close();
	}
}
/*void Network::addConexions (vector<int> index, int random){
//rempli la ligne par pushback de valeur aléatoires (taille des colones est index) 

	
	//mapConnexion_[index].push_back(random); 	
}
*/
//////////////////////////////////////////////////
//											 	//
//                   GETTERS                  	//
//												//
//////////////////////////////////////////////////

//get a neuron at a specific place in the collection of neurons
Neuron Network::getNeuronsPosey(size_t j) const{
	
	return neurons_[j];
}

//get a connexion between neurons at a specific place in the mapConnexion
int Network::getMapConnexionPosey(size_t i, size_t j) const{
	
	return mapConnexion_[i][j];
}

size_t Network::getNumbNeurons() const{
	
	return neurons_.size(); 
}
