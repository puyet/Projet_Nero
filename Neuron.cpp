#include "Neuron.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

#include <random>
#include <fstream>

using namespace std; 
//////////////////////////////////////////////////////////////
//															//
//				Constructors and Destructors				//
//															//
//////////////////////////////////////////////////////////////

//Default Constructor
Neuron:: Neuron ()
{}

Neuron:: Neuron (TypeNeuron type)
: memb_pot_(Vr), localClock_(0), isRefractory_(false), RingBuffer_(D+1, 0), typeNeuron_(type), isSpiking_(false)
{}

//////////////////////////////////////////////////////////////
//															//
//						Main functions 						//
//															//
//////////////////////////////////////////////////////////////

void Neuron:: update_neuron(double Iext, double Poisson){

	double Jbuffer=0.0; 
	
	if (isRefractory_==false) {
		
		//the neuron reaches the threshold
		if(memb_pot_> Teta) {	 
			//store the time of a spike
			
			spikes_.push_back(localClock_); 		 
			//cout<<spikes_.size()<<endl; 
			//clean mem_pot value ; 
			memb_pot_ = Vr; 
			//then the neuron go to the refractory period 
			isRefractory_=true;
			//the update of the neuron return the info that the neuron is spiking 
			//isSpiking_=true; 
		
		 }
		
		 	//reset the buffer actual case to make it clean at the end each step
		if(RingBuffer_[getBufferPosey(localClock_)]!=0.0){
			
			Jbuffer = RingBuffer_[getBufferPosey(localClock_)];
			RingBuffer_[getBufferPosey(localClock_)]=0.0;
			
		}
		 
		 if (spikes_.empty() or memb_pot_<= Teta){
			
			//double lambda_ = Vext*Ce; 
     
			//static random_device rd; 
		//static mt19937 gen ( rd()); 
		//static poisson_distribution <int> Poisson(lambda_);
    
    //double RandomImput = Poisson(gen) *J;
				
				//the membrane potential evolute in depends of exteral current, spikes from neighbours and external random spikes 
				pot_calcul(dt, Iext, Jbuffer, Poisson);
				//the neuron doesn't reach the threshorld	
				//isSpiking_=false;
		}
	
	
	//the neuron enter in the refractory time 
	} else if (isRefractory_== true) {
		//and it take Tau_rp time for the refractory, its potential membrane doesn't evolute
		if (localClock_>= (spikes_.back() +Tau_rp) and !spikes_.empty()) {			 
			 
			isRefractory_ = false; 
			//isSpiking_=false;
		} 
	} 

	//increment the localClock at each end of the update
	++localClock_; 
	//the neuron isn't spiking
	 
}
/*
bool Neuron:: update_neuron(double Iext, double Poisson){

	double Jbuffer=0.0; 
	
	if (isRefractory_==false) {
		
		//the neuron reaches the threshold
		if(memb_pot_> Teta) {	 
			//store the time of a spike
			cout<<"NIque toi"<<endl; 
			spikes_.push_back(localClock_); 		 
			//clean mem_pot value ; 
			memb_pot_ = Vr; 
			//then the neuron go to the refractory period 
			isRefractory_=true;
			//the update of the neuron return the info that the neuron is spiking 
			
			return true; 
			
		 }
		 	//reset the buffer actual case to make it clean at the end each step
		if(RingBuffer_[getBufferPosey(localClock_)]!=0.0){
			Jbuffer = RingBuffer_[getBufferPosey(localClock_)];
			RingBuffer_[getBufferPosey(localClock_)]=0.0;
			
		}
		 
		 else if (spikes_.empty() or memb_pot_<= Teta){
			//double lambda_ = Vext*Ce; 
     
			//static random_device rd; 
		//static mt19937 gen ( rd()); 
		//static poisson_distribution <int> Poisson(lambda_);
    
    //double RandomImput = Poisson(gen) *J;
				
				//the membrane potential evolute in depends of exteral current, spikes from neighbours and external random spikes 
				pot_calcul(dt, Iext, Jbuffer, Poisson);
				//the neuron doesn't reach the threshorld	
		}
	
	
	//the neuron enter in the refractory time 
	} else if (isRefractory_== true) {
		//and it take Tau_rp time for the refractory, its potential membrane doesn't evolute
		if (localClock_>= (spikes_.back() +Tau_rp) and !spikes_.empty()) {			 
			cout<<"ok"<<endl; 
			isRefractory_ = false; 
		} 
	} 

	//increment the localClock at each end of the update
	++localClock_; 
	//the neuron isn't spiking
	return false; 
}*/

//calcul the evolution of the mebrame potential 
void Neuron:: pot_calcul(double dt, double Iext, double j, double Poisson) {
    
    double cst1 = exp(-(dt/Tau));
    double cst2 = (1-cst1)*R; 
    
     //the memb_pot depends of dt, Tau, R, Iext(=0.0), j due to the spiking of the others neurons and a random externalCurrent 
     memb_pot_ = (cst1*memb_pot_) + (cst2*Iext) +j + Poisson*J; 
}

//update of buffer with the j in the right place 
void Neuron::setBuffer(int t, double j) {
	int i = getBufferPosey(t); 
	RingBuffer_[i] += j;
}

//calculate with the distribution of poisson, the random distribution of external spikes	
/*double Neuron::randomExternalSpikes(){
	
//distribution of poisson 
	//double lambda = Vext*Ce;
	double lambda =2; 
	static random_device rd; 
	static mt19937 gen ( rd()); 
	static poisson_distribution <int> Poisson(lambda);
	
	return Poisson(gen); 
}

*/
//////////////////////////////////////////////////
//											 	//
//                   GETTERS                  	//
//												//
//////////////////////////////////////////////////

//get the spike	
vector <double> Neuron::getSpikes() const {
		
	return spikes_; 
}

//get the size of the vector of spikes wich correspund to the number of spikes
size_t Neuron::getNumbSpikes() const {
	
	return spikes_.size(); 	
	
}

//get the potential of the mebrane 
double Neuron::getMemb_pot() const {
	
	return memb_pot_; 
}


//get the time when a neuron spike 
double Neuron::getTimeForSpike(size_t j) const{
	
	return spikes_[j];
}

//return the place to store the J with a delay D 
int Neuron::getBufferPosey(int t) const{
	
	int i = t % (D+1);
	
	return i;
}


//get the local Clock of the neuron 
int Neuron::getLocalClock() const {
	assert(localClock_>=0);
	return localClock_; 
}

//get the bool indicate if the neuron is refractory or not 
bool Neuron::getisRefractory() const {
	
	return isRefractory_; 
}

//get the ringBuffer 
vector <double> Neuron::getRingBuffer() const{
	
	return RingBuffer_; 
}
		
//return the type of the neuron 
bool Neuron::isExcitatory(){
	if(typeNeuron_==E) {
		return true; 
	}else{
		return false; 
		}
}

bool Neuron::getIsSpiking(int step)const {
	
	if(spikes_.empty()){

		return false; 
		
	}
	if(step==spikes_.back()){
	
		return true;
		}
	return false; 
	}
