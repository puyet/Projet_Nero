#ifndef NEURON_H
#define NEURON_H

#include <iostream>

using namespace std;

typedef  vector Time_Spike; //tableau dans lequel il serait top d'avoir les temps correspondants aux spikes

class Neuron {
	
	private: 
		//variables constantes :
		double Vo; //potentiel inital 
		double R; //résistance de la membrane
		double h;//(temps/step) temporal évolution
		double t_start (0);
		double t_stop;
		double N (1); //nbr total of neurons (pour l'instant 1)
		double Ne = 0.8*N; //nbr excitated neurons 
		double Ni = 0.2 *N; //nbr inhibitated neurons
		double Ce = Cext; //nbr connection excitated
		double Ci = 0.25 * Ce; // nbr connection inhibitated
		double Cext;// nbr coonexion externals
		double VEext, //external frequencies exci
		double VIext; //external frequencies inhi
		double tE_cst; //
		double tI_cst; 
		//Variables non cst:
		double V; //potentiel => méthode
		double Iext;
		double t;
		double n; //nbr step
		
		
		
	public:
		
		Neuron(double memb_pot_, double Spikes_numb_, double t_, double T_, double Iext_);
		~Neuron() {}; 
		//type??? + attributs ???
		void update_state(double t, double T);
		//create methode V(t) qui est le membrane pot????
		void set_Iext(); // donne possibilité à l'user de chosir son Iext
		

};
	
	
#endif
