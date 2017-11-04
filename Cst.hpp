#ifndef CST_H
#define CST_H

#include <math.h>


//les unités sont en secondes 
//int const N = 12500; // number of neurons (will be 12500 ) and Ne = 0.8N Ni = 0.2N
int const N = 12500;
int const Ne = N*0.8; //Ne est le # de neurons excitator
int const Ni = N*0.2; //Ni est le # of neuron inibitor 
int const Ce = Ne*0.1; // Ce est le # de connexions faites avec des neurons excitator
int const Ci = Ni*0.1; //Ci est le # de connexions fait avec des neurons inh
int const Teta = 20; //seuil of potential 
double const Tau_rp=20; // refractory period (after a spike) 
double const Tau_E = 2; // ETA
double const Vr = 0.0; // reset of Vi(t) (after Tau_rp) 
double const dt = 0.1; //en 0.1 ms 
double const Tau = 20.0; //tau = R*C
double const C =1; // capacitance 
double const J=0.1; //amplitude du spike 
double const Je =J; //J apporté par un neuron excitator 
double const Ji= -0.5*J; //J apporté par un neuron inhibitor 
double const g=(Ji/Je); //ration of de 
int const D = 15; //Delay
double const R = 20.0; //r = TAU/C 
double const Vext=0.2; //used for the random external spikes (not shure of value) //MOI 
const double h =0.1; 
const double NuExt =(Tau_E*0.1*0.8*N*J*Tau);
const double NuThr =(Teta/(0.1*0.8*N*Je*Tau)); 
//const double lambda =(NuExt*dt); 
const double Iext=0.0; 

enum TypeNeuron{E, I};
#endif 
