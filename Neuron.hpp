#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>


using namespace std;

//  vector <double>  Spikes; //tableau dans lequel il serait top d'avoir les temps correspondants aux spikes //mieux de mettre dans la classe ??

class Neuron {
	
	private: 
		
		
		double memb_pot_; //the membrane potential (stockage) will aways be reaffected and modify with stat of neuron through methode and formule Vi(t)
		int localClock_;//I don't use it...........  
		bool isCharged_; //spikes = true // I don't use it 
		//va devoir stocker son nombre de step de simulation (=local clock)   
		//Network myNetwork; pas de network pour l'instant  
		bool isRefractory_; // = true if the neuron is refractory 
		
		vector <double> spikes_;
		//I will have to find a way to store these two value in a thabs of paper with offstream.... /
		/**
		 * idea: maybe add a state of neuron ==> bool exited or 
		 * */
		vector <Neuron*> TargetNeighbours; //tableau de ses voisins  
		//RingBuffer: 
		//array <int, 15> buffer_;
		
	public:
		//constructor & destructor 
		Neuron(); // pas sure des attributs de la classe
		~Neuron() {}; 
	
		
		//methods which will care about potential membrane way ==> guide the neuron state
		void update_neuron(double RealTime, double dt, double Iext); 
		void pot_calcul(double dt, double Iext); 
		
		
		
		//getters 
		size_t getNumbSpikes() const; //the size of the vector is the #of Spikes because each time one happends it is store
		double getTimeForSpike(size_t data) const; 
		double getMemb_pot() const;  
		vector <double> getSpikes() const; 
		//spikeSafe
		  

};
	
	
#endif 
