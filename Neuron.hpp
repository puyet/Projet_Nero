#ifndef NEURON_H
#define NEURON_H

#include <iostream>

using namespace std;

class Neuron {
	
	private: 
		
		double memb_pot; 
		double Spikes_numb; 
		double t; 
		double T; 
	
		//
		double Iext;
		
	public:
		
		Neuron(double memb_pot_, double Spikes_numb_, double t_, double T_, double Iext_);
		~Neuron() {}; 
		//type??? + attributs ???
		void update_state(double t, double T);
		//create methode V(t) qui est le membrane pot????
		void set_Iext(); 

};
	
	
#endif
