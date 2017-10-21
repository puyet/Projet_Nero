#include "Network.hpp"
#include "Cst.cpp"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 


Network::Network ()
{
	
	network.push_back(new Neuron()); 
	
	}

	Network::~Network(){
		for (size_t i(0); i<neur.getTargetNeighbours_.size(); ++i){
	
		delete i;
	
	}				
}

Network::void addConnexion(Neuron * neur){
	neur.getTargetNeighbours_.push_back(neur)
	
}
		

/* simulation en faire plusieur genre qui seront appelles dans le main => (simulate; printdata;)
 * 
 * va faire ce que fait le main pour l'instant 
 * methode qui pointe sur neurons :
 * TargetNeighbours_.push_back(neur); // a mettre dans le network a mettre dans connexion avant de lancer ma simulation addConnexion
 * 
 * */
