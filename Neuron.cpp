#include "Neuron.hpp"
#include "Cst.cpp"

#include <iostream>
#include <cmath>
#include <vector>


using namespace std; 

Neuron:: Neuron ()
: memb_pot_(Vr), localClock_(0.0), isRefractory_(false)
{}

//
void Neuron:: update_neuron(double RealTime, double dt, double Iext){

	//not sure of my conditions 
	if (isRefractory_==false) {
	
		if(memb_pot_>= Teta) {	 
			// not sure final aim: store each time after a spike  
			spikes_.push_back(RealTime); 		 
			memb_pot_ = Vr; //clean mem_pot value ; 
			isRefractory_=true; 
			//incrementer mon buffer (array) 
			//ajouter le J 
			//cout<<"coucou je spike"<<endl; 
		 } else if (spikes_.empty() or memb_pot_< Teta){
			
			pot_calcul(dt, Iext);
			//cout<<"coucou je ne spike ppas"<<endl; 
			//double mem_pot_dt = (exp(-dt/tau)*mem_pot+Iext/C(1-exp(-dt/tau)); // a transformer en une méthode formule pour etre plus joli 	
			//incrementer mon buffer (array) 
	}
	}
	
	else if (isRefractory_== true) {
		if (!spikes_.empty() and localClock_>= spikes_.back() +Tau_rp) {
				
		}
		cout<<"refractory"<<endl; 
		isRefractory_ = false; 
	}
	
	
	else 
		

	++localClock_; 
}
void Neuron:: pot_calcul(double dt, double Iext) {
     
     double cst1 = exp(-(dt/Tau));
     double cst2 = (1-cst1)*(Tau/C); 
     memb_pot_ = (cst1*memb_pot_) + (cst2*Iext); 
}
	
	
vector <double> Neuron::getSpikes() const {
		
	return spikes_; 
}
	
size_t Neuron::getNumbSpikes() const {
	
	return spikes_.size(); 	
	
}

double Neuron::getMemb_pot() const {
	
	return memb_pot_; 
}

double Neuron::getTimeForSpike(size_t j) const{
	
		return spikes_[j];
}
