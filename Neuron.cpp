#include "Neuron.hpp"

#include <iostream>
#include <cmath>

using namespace std; 

Neuron:: Neuron (double memb_pot_, double Spikes_numb_, double t_, double T_, double Iext_)
: memb_pot(memb_pot_), Spikes_numb(Spikes_numb_), t(t_), T(T_), Iext(Iext_)
{}


void Neuron:: update_state(double t, double T){
	
	}
 

