#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <iostream>
#include <vector>

// pas de network pour l'instant 

using namespace std;


class Network {
	
	private : 
		vector <Neuron*> network; // je contient tout mes neurons  
		Neuron neur; 
		
		//tableau de tableau de bool  
		//créer array de taille 15 ou y'a chaque dt apres des qu'il y a spike je stock pour faire le ring modulo %15 (car D = 15 dt) ===> timeClock ie buffer 
		// je vais avoir besoin de savoir combien de connexion donc maybe vector<bool> NeuronsCharged 
	public : 
	
		Network(); 
		~Network();
		void addConnexion(Neuron* neur);
		
		
		
	
		/*
	
	udpade de neurone renvoie un bool 
	*/
	
	
	};
#endif
