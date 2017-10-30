#include "Network.hpp"
#include "Neuron.hpp"
#include "Cst.hpp"
#include <cassert>
#include <random>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

//////////////////////////////////////////////////////////////
//															//
//				Constructors and Destructors				//
//															//
//////////////////////////////////////////////////////////////

//Constructor : initialise the collection of neurons and the map of connexions between the neurons 
Network::Network ()
:neurons_(), mapConnexion_(N, vector<int>(N, 0))
{
	//1. Fill the vector of neurons (reminder N=12500) 
	for(int i(0); i<N; ++i){
		Neuron neuron; 
        addNeurons(neuron);
	}
	//2. Fill the map of Connexions 
	for(unsigned long int i(0); i<neurons_.size(); ++i) {
		
		//Connexions with excitator neurons (random choice) (reminder Ce=Ne/10 and Ne=0.8*N) 
		for(int E(0); E<Ce; ++E){ 
			mapConnexion_[i][randomSelection(0,(Ne-1))] +=1; 	
		}
		//Connexions with inhibitor neurons (random choice) (reminder Ci=Ni/10 and Ni=0.2*N)
		for (int I(0); I<Ci; ++I){	
			mapConnexion_[i][randomSelection(Ne,Ne+Ni-1)] +=1;
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

int Network::randomSelection (int a, int b) {
	
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(a, b); //calcul the random uniform distribution 
    
    return dis(gen);
}
//update the network by fill the buffers of neurons with Jtot and call the update method for the neuron 
void Network::update_network(){

	for(int i(0); i<N; ++i){
		
		//Jtot is the storage of the total amplitude J (sum of every connexion and specified for excitator or inhibitor) which will be givent to the neuron spiked
		double Jtot(0); 

		for(int E(0); E<Ne; ++E){
			
			if(mapConnexion_ [i][E] != 0 and neurons_[E].getisSpiking()==true){
				
				Jtot= mapConnexion_[i][E]*Je; 
				
				neurons_[i].setBuffer(neurons_[i].getLocalClock()+D, Jtot); 
				
			}	
		}
		for (int I(Ne); I<N; ++I){
			
			if(mapConnexion_[i][I] != 0 and neurons_[I].getisSpiking()==true){
				
				Jtot= mapConnexion_[i][I]*J; 
				
				neurons_[i].setBuffer(neurons_[i].getLocalClock()+D, Jtot); 
				
			}	
		}
		neurons_[i].update_neuron(Iext); 
	}
}
//method which run the simulation of a network and its neurons évolute with the RealTime	
void Network::simulation(){
	 
	while (RealTime_< t_stop){
		update_network(); 
		
		++RealTime_; 
	}
}
//add neurons in the collection of neurons 
void Network::addNeurons(Neuron newNeuron){
	
	neurons_.push_back(newNeuron);
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
		for (size_t j(0); j<N; ++j){
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
