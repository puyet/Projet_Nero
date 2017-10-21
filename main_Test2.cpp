#include <iostream>
#include "Neuron.hpp"
#include "Cst.hpp"

using namespace std; 

int main ()  
{
	
	Neuron n1; 
	Neuron n2;  
	
	Neuron* p_n2= &n2; 
	n1.addConnexion(p_n2);

	double t_start=0.0; 
	double t_stop=1000; 
	double Iext=1.01; 
	
	
	double RealTime(t_start);
	
	
	
	
	cout <<"---Potential---"<<endl; 
	
	while (RealTime < t_stop){
		
		
			
		n1.update_neuron(Iext); // "Spikeur 
		//cout << "Potential_n1 = "<< n1.getMemb_pot() <<"mV" << " at time : " << RealTime/10<<"ms"<<endl;
		
		n2.update_neuron(0.0); //Spiké
		cout << "Potential_n2 = "<< n2.getMemb_pot() <<"mV" << " at time : " << RealTime/10<<"ms"<<endl;
		
		++RealTime;  
		
		
	}
	
	cout << "---SPIKES---"<<endl; 
	for(size_t i=0; i < n1.getNumbSpikes(); i++) {
	
		cout<<"Spike_n1 : "<<i<<" at time : " << n1.getTimeForSpike(i)/10<<endl; 
			
	}
	
	for(size_t i=0; i < n2.getNumbSpikes(); i++) {
	
		cout<<"Spike_n2 : "<<i<<" at time : " << n2.getTimeForSpike(i)/10<<endl; 
			
	}
	
	
	
	cout<<" END "<<endl;



	return 0; 	
}
