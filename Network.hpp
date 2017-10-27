#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <iostream>
#include <vector>

// pas de network pour l'instant 

using namespace std;


class Network {
	
	private : 
		vector <Neuron*> neurons_; // je contient tout mes neurons de taille N
		vector<vector<int> > mapConnexion_;
		int RealTime_= 0;
		int t_stop=100; 
		
	public : 
	
		Network(); //ou N est notre nombre total de neurons  
		~Network();
		//méthode qui renvoit une valeur aléatoire parmis des bornes définies
		int randomSelection(int a, int b);
		//remplis le vecteurs de neurons 
		void addNeurons(Neuron* new_neuron); 
		//update the network et incéremente le realtime 
		void simulation(); 
		//remplis le buffer des J quand neurons spikent et transmet l'info au neurons
		void update_network(); 
		//imprime la map connexion pour ettre sure que ca marche 
		void printMapConnexion();
		void printNeurons();

	
	};
#endif
