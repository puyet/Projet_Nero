#include <iostream>
#include "Network.hpp"

#include "Cst.hpp"
using namespace std; 


//here is the main 
//by writing ./NetworkTest in the terminal will run the simuation of a Network and is neurons. 
//optional printNeurons() and printMapConnexion() to see in the terminal the neurons and the connexions of the networks (optimal with 50 neurons) 
int main ()  {

	Network network; 
  
	network.simulation(); 
	cout<<"End of the simulation "<<endl; 
	
	//network.printNeurons(); 

	//network.printMapConnexion(); 
	
return 0; 

}
