#include <iostream>
#include <fstream>
#include "Neuron.hpp"
#include "Cst.cpp"
#include <cmath> 

using namespace std; 

int main ()  
{
	Neuron neuron; 

	//double memb_pot = 0.0;  
	//double timeForSpike = 0.0; 
	double t_start=0.0; 
	double t_stop=100; 
	double Iext=0.0; 
	double a=0.0; 
	double b=0.0; 
	double It; 
	
	double RealTime(0.0);
	
	// do while demander a l'user d'entrer Iext, a et b 
	do{
		cout<<"enter a value for Iext"<<endl; 
		cin>>Iext; 
			
	} while (Iext == 0); 		
	do {
		cout<<"enter a value for the time a"<<endl; 
		cin>>a;
	} while (a <= t_start); 
	do {
		cout<<"enter a value for the time b"<<endl; 
		cin>>b;
	} while (b <= a); 
	
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
			
				neuron.update_neuron(RealTime, dt, Iext);
		}
		else {
			
				neuron.update_neuron(RealTime, dt, 0.0); 
		}	
		
		RealTime+=dt;  
		
		data << "Potential = "<< neuron.getMemb_pot() << " at time : " << RealTime/10<<"ms"<<endl;
		cout << "Potential = "<< neuron.getMemb_pot() << " at time : " << RealTime/10<<"ms"<<endl;
		
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
