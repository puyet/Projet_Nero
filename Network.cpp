#include "Network.hpp"
#include "Neuron.hpp"
#include "Cst.hpp"
#include <random>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 


Network::Network ()
:neurons_(), mapConnexion_(N, vector<int>(N, 0))
{
	//étape 1: remplir un tableau avec N neurons (rappel N=12500) 
	for(int i(0); i<N; ++i){
		Neuron* ptr_neuron = new Neuron();
        addNeurons(ptr_neuron);
     
	}
	//étape 2: remplir le table de connexion
	for(unsigned long int i(0); i<neurons_.size(); ++i) {
		
		for(int E(0); E<Ne; ++E){
			//on remplis la case d'un neurone correspondant à un neurone excitateur choisir aléatoirement et on signalise 
			//la connexion effectuee par 1
			
			cout << neurons_.size() << endl;
			mapConnexion_[i][randomSelection(0,(Ne-1))] +=1; 
			
		}
		cout<<"Y"<<endl; 
		for (int I(0); I<Ni; ++I){	
			mapConnexion_[i][randomSelection(Ne,Ne+Ni-1)] +=1;
		}
	
	}
	
}
	

/* il faut que tu reflechisses bien a comment est fait ton tableau, si en horizontale tu as le neuron qui recoit ou qui envoit (le neuron
 * vertical sera alors l'autre. 
 * dans une conception ou le horizontal = emetteur, vertical = receveur: lorsque tu cree les connexions de ton
 * neurone, il faut que le neurone tiré au sort soit un neuronne qui SPIKE SUR le neurone que tu considère (i). C'est ce qui est écrit dans
 * l'énoncé, ce qui fait qu'un neurone peut etre un cul de sac et ne spiker sur personne mais recevoir les spike de tous le monde. Je pense
 * que tu n'as pas implémenter ça
 * Ton segfault vient de la ligne 35, i+Ne devient très vite plus grand que N (dès que i vaut Ni)
 * Tu devrais t'en sortir avec tout ça: envoit moi un message et j'accours <3 (je suis planqué en CM)
 * */

Network::~Network(){
		
	for (auto& i : neurons_ ){
		delete i;
		i= nullptr; 
	} 
	neurons_.clear(); 
}				

int Network::randomSelection (int a, int b) {
	
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(a, b);
    
    return dis(gen);
 
}

void Network::update_network(){
	cout<<"ciao"<<endl; 
	
	cout<<"ICI"<<endl; 
	for(int i(0); i<N; ++i){
		
		//! Jtot is the storage of the total amplitude J which will be givent to the neuron spiked
		double Jtot(0); 

		for(int E(0); E<Ne; ++E){
			
			if(mapConnexion_ [i][E] != 0 and neurons_[E]->getisSpiking()==true){
				
				Jtot= mapConnexion_[i][E]*Je; 
				
				neurons_[i]->setBuffer(neurons_[i]->getLocalClock()+D, Jtot); 
				
				}	
		}
		for (int I(Ne); I<N; ++I){
			
			if(mapConnexion_[i][I] != 0 and neurons_[I]->getisSpiking()==true){
				
				Jtot= mapConnexion_[i][I]*J; 
				
				neurons_[i]->setBuffer(neurons_[i]->getLocalClock()+D, Jtot); 
				
				}	
			}
	}
}
	
void Network::simulation(){
	 
	
	while (RealTime_< t_stop){
		update_network(); 
	
		++RealTime_; 
	}
}
		
		
void Network::printNeurons()
{
	cout << "---Neurons---" << endl << endl;
	
	for (size_t i(0); i<N; ++i)
	{
		cout << "N" << i << endl;
	}
		
	cout << endl << endl;
}

void Network::printMapConnexion()
{
	cout << "---Connection Map---" << endl << endl;
	cout << "   ";
	for (size_t j(0); j<N; ++j)
	{
		cout << "N" << j << "  ";
	}
	cout << endl;
	
	for (size_t i(0); i<N; ++i)
	{
		cout << "N" << i;
		for (size_t j(0); j<N; ++j)
		{
			cout << " " <<mapConnexion_[i][j] << "  ";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

void Network::addNeurons(Neuron* new_neuron){
	
	neurons_.push_back(new_neuron);
	
	}

