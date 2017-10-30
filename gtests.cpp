#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <cmath>
//#include "Neuron.hpp"
#include "Cst.hpp"
#include "Network.hpp"

using namespace std; 

int main(int argc, char **argv ){
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
		
}
//test la valeur du potentiel membranaire 
TEST(NeuronTest, MembranPotential) {
	
	Neuron neuron1;
	
	neuron1.pot_calcul(1, 1.0, 0);
	EXPECT_EQ(200*(1-exp(-1.0/200)), neuron1.getMemb_pot());
  
}
//test que le potentiel se reinitialise bien 
TEST(NeuronTest, refractoryPotClean) {
	
	Neuron neuron1; 
	if(neuron1.getisRefractory() == true){
		
		EXPECT_EQ(0, neuron1.getMemb_pot()); 
	}
	
}

//test le #de spikes apres un certain temps (on sait qu'il y en aura 2 => un a 2.1 et un a 6.3 apres 100 pas ) 
/*TEST(NeuronTest, NumberOfSpikes){
	
	Neuron neuron1; 
	double Iext = 1.01; 
	
	for (auto i=0; i<20; ++i){
		neuron1.update_neuron(Iext);
		EXPECT_EQ(0, neuron1.getNumbSpikes()); 	
	}
	
	for (auto i=22; i<62; ++i){
		neuron1.update_neuron(Iext);
		EXPECT_EQ(1, neuron1.getNumbSpikes()); 	
	}	
	
	for (auto i=64; i<100; ++i){
		neuron1.update_neuron(Iext);
		EXPECT_EQ(2, neuron1.getNumbSpikes()); 	
	}	
}
*/
//test que le neuron 2 avec un Iext de 0 ne spike toujous pas malgres les autres neurons 
TEST(TwoNeuronTestWithNetwork, NoPSSpike) {
	
	Network network; 
	for(auto i=0; i<100; ++i){
			network.simulation(); 
			network.getNeuronsPosey(1).pot_calcul(dt, 0, network.getNeuronsPosey(1).getBufferPosey(network.getNeuronsPosey(1).getLocalClock()));
	}
	EXPECT_EQ(0, network.getNeuronsPosey(1).getNumbSpikes());
}

//test qui affiche mes connexion entre neurons et vérifie qu'il y a bien le bon #de connexions pour chaque neurone
TEST(NetworkTest, printConnexionGlobal) {
	
	Network network; 
	network.simulation();
	network.printMapConnexion(); 
	
	int total=0; 
	
		for (size_t i(0); i<N; ++i){
			for (size_t j(0); j<N; ++j){
			 
			total += network.getMapConnexionPosey(i, j);
			}
		}
	EXPECT_EQ(N*(Ce+Ci), total); 
}

TEST(NetworkTest, excitatoryConnexionNumber) {
	Network network; 
	network.simulation();
	
	for(size_t i(0); i<Ne; ++i){
		for(size_t j(0);j<Ne; ++j){
					
		}
	}
	
}

