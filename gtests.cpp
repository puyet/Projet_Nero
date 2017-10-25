#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Neuron.hpp"
#include "Cst.hpp"

using namespace std; 

int main(int argc, char **argv ){
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
	
	
	
}

TEST(NeuronTest, MembranPotential) {
	
	Neuron neuron1;
	
	neuron1.pot_calcul(1, 1.0, 0);
	EXPECT_EQ(200*(1-exp(-1.0/200)), neuron1.getMemb_pot());
  
}
TEST(NeuronTest, refractory) {
	
	Neuron neuron1; 
	if(neuron1.getisRefractory() == true){
		
		EXPECT_EQ(0, neuron1.getMemb_pot()); 
	}
	
	
}


//TEST bla vla 
