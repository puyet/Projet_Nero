#ifndef CST_H
#define CST_H

#include <math.h>

//! external current 
double const Iext=0.0; 
//! The number total of nerons 
int const N = 12500; 
//! The number of neurons excitator 
int const Ne = N*0.8; 
//! The number of neurons inhibior
int const Ni = N*0.2;
//! The number of connexions with excitator neurons  
int const Ce = Ne*0.1;
//! The number of connexions with inhibitor neurons
int const Ci = Ni*0.1;
//! Treshold potential, the potential above wich the neuron will spike 
int const Teta = 20;
//! refractory period (after a spike) 
double const Tau_rp=20;
//! ETA 
double const Tau_E = 2;
//! reset of Vi(t) the membrane potential 
double const Vr = 0.0;
//! time per step 
double const dt = 0.1;
//! Capacitance 
double const C =1;
//! amplitude of a spike
double const J=0.1;
//! amplitude of an excitator spike 
double const Je =J;
//! //! amplitude of an inhibitor spike
double const Ji= -0.5*J;
//! ratio of Ji and Je
double const g=(Ji/Je);
//! Delay 
int const D = 15;
//! R=TAU/C
double const R = 20.0; 
//! Neuron time constant
double const Tau = R*C;
//! POISSON LAW: 
const double NuThr =(Teta/(0.1*0.8*N*Je*Tau));
const double NuExt =(Tau_E*0.1*0.8*N*NuThr); 
const double lambda =(NuExt*dt); 

//! Type of neurons (two types : excitator (E), inhibitor(I)
enum TypeNeuron{E, I};
#endif 
