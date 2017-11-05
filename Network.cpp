/**
 * @file Network.cpp
 * @brief file containing the statements of a Network class
 *
 */
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
	//1. Fill the vector of neurons with the excitatory neurons (reminder Ne=10000) 
	for(int i(0); i<Ne; ++i){

        neurons_.push_back(Neuron(E));
	}
	//2. Fill the vector of neurons with the inhibitor neurons (reminder Ni=2500) 
	for(int i(Ne); i<N; ++i) {
		
		neurons_.push_back(Neuron(I));
	}
	//3. Fill the mapConnexion with radom values (uniform distibution) for the number total of connexions   
	for(unsigned long int i(0); i<neurons_.size(); ++i){
	
		for(int E(0); E<(Ce+Ci); ++E) {
			
			static random_device rd;  //Will be used to obtain a seed for the random number engine
			static mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			static uniform_int_distribution<> dis(0, (N-1)); //calcul the random uniform distribution for the exciator neurons 
			
			mapConnexion_[i].push_back(dis(gen)); 
		}
	}
}
	
//Default destructor 
Network::~Network(){}
	
		
//////////////////////////////////////////////////////////////
//															//
//						Main functions 						//
//															//
//////////////////////////////////////////////////////////////


//method which run the simulation of a network and its neurons évolute with the RealTime 
//=> genrate the poisson distribution for the unpdate of the neurons 
//updates the network and updates the neurons with Iext=0.0. 	
void Network::simulation(){
	 
	cout<<"Preparing the simulation... "<<endl; 
	cout<<""<<endl; 
	//print some infos:
	cout<<"Network number of neurons: "<<neurons_.size()<<endl;
	cout<<""<<endl; 
	cout<<"Simulation time: "<<t_stop/10<<" ms"<<endl;
	cout<<""<<endl;  

	ofstream data; 
	data.open("spikesTable.txt"); 
	if (data.fail()) {
		
		cout<<"Error opening SpikeTable file"<<endl; 
	}
	else {	
		
		//distribution of poisson 
		static random_device rd; 
		static mt19937 gen ( rd()); 
		static poisson_distribution <int> Poisson(lambda);
		
		for(long time=0; time<=t_stop; ++time){
			
			for(size_t j(0); j<neurons_.size(); ++j){
				
				neurons_[j].update_neuron(Iext, Poisson(gen)); 
				
				if(neurons_[j].getIsSpiking(RealTime_)){
					//write in a txt files called spikesTable. print the time of when happens the spike and for wich neuron 
					data<<neurons_[j].getLocalClock()<<'\t'<<j+1<<'\n';
						
					for(size_t i(0); i<(Ci+Ce); ++i){
							
						int Connex(mapConnexion_[j][i]);
							
						if(neurons_[j].isExcitatory()){
								
							neurons_[Connex].setBuffer(neurons_[Connex].getLocalClock()+D, Je);
						}
						else{
							neurons_[Connex].setBuffer(neurons_[Connex].getLocalClock()+D, Ji);
						}
					}
				}
			} 
			RealTime_=time;
		}
	}
	data.close(); 
}

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

//print the mapConnexion of the neurons (CARREFULL DOESN'T WORK WITH BIG TOO BIG NUMBER OF NEURONS, 30 IS GOOD) 
void Network::printMapConnexion()
{
	cout << "---Connection Map---" << endl << endl;
	
	for (size_t i(0); i<N; ++i) {
		cout << "N" << i;
		for (size_t j(0); j<mapConnexion_[i].size(); ++j){
			cout << " " <<mapConnexion_[i][j] << "  ";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}


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
//get the size of the collection of neurons of the network
size_t Network::getNumbNeurons() const{
	
	return neurons_.size(); 
}
