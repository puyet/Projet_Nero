#ifndef CST_H
#define CST_H

#include <math.h>


//les unités sont en secondes 
int const N = 1; // number of neurons (will be 12500 ) and Ne = 0.8N Ni = 0.2N 
int const Teta = 20; //seuil of potential 
double const Tau_rp=0.2; // refractory period (after a spike) 
double const Tau_E = 2; //pas utile pour le moment 
double const Vr = 10.0; // reset of Vi(t) (after Tau_rp) 
double const dt = 0.1; //en secondes 
double const Tau = 20; //tau = R*C will see later ==> r= tau/C
double const C =1; // capacitance 

#endif 
