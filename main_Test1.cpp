#include <iostream>
#include <fstream>
#include "Neuron.hpp"
#include "Cst.hpp"
#include <cmath> 

using namespace std; 

int main ()  
{
	//Faire une vecteur de neurons 
	Neuron neuron;
	Neuron n1; 
	Neuron n2;  
	
	//double memb_pot = 0.0;  
	//double timeForSpike = 0.0; 
	double t_start=0.0; 
	double t_stop=100; 
	double Iext=0.0; 
	double a=0.0; 
	double b=79.0; 
	double It; 
	
	double RealTime(0.0);
	
	Iext = 1.01; 
	
	////ofstream (écriture des potentiels et temps de spikes dans fichier "SpikeTable") 
	ofstream data; 
	data.open("spikeTable.txt"); 
	if (data.fail()) {
		
		cout<<"Error opening SpikeTable file"<<endl; 
	}
	else 
	{	
		cout<<" file available"<<endl; 
	}
	
	data<< " MEMBRANE POTENTIALS : " <<endl;
	cout <<"---Potential---"<<endl; 
	
	while (RealTime < t_stop){
		
		if(RealTime >= a and RealTime <= b) {
			
				neuron.update_neuron(Iext);
//	
				//n1.update_neuron(RealTime, dt, Iext);
		
		}
		else {
			
				neuron.update_neuron(0.0); 
				//n1.update_neuron(RealTime, dt, 0.0);
			
		}	
		
		++RealTime;  
		
		data << "Potential = "<< neuron.getMemb_pot() << " at time : " << RealTime/10<<"ms"<<endl;
		cout << "Potential = "<< neuron.getMemb_pot() << " at time : " << RealTime/10<<"ms"<<endl;
		//cout << "Potential = "<< n1.getMemb_pot() << " at time : " << RealTime/10<<"ms"<<endl;
		
	}
	
	data << " SPIKES " <<endl;
	cout << "---SPIKES---"<<endl; 
	for(size_t i=0; i < neuron.getNumbSpikes(); i++) {
	
		data<<"Spike : "<<i<<" at time : " << neuron.getTimeForSpike(i)/10<<endl;
		cout<<"Spike : "<<i<<" at time : " << neuron.getTimeForSpike(i)/10<<endl; 
			
	}
	
	data.close(); 
	cout<<" END "<<endl; 
	return 0; 
}
