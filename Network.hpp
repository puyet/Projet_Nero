/**
 * @file Network.hpp
 * @brief file containing the statements of a Network class
 *
 */
#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <iostream>
#include <vector>


using namespace std;
/**
 * @class Network Network.hpp 
 * @brief class representing tje neural newtork. 
 * this class contains various attributes and methods necessary to a network of neurons 
 * 
 */ 
class Network {
	
	private : 
		//------------ATRIBUTES-----------//
		
		/**
		 *@brief collection of all the neurons in the network (size N which is 12500 neurons) fill of 10000 excitator neurons and 2500 inhibitors 
		 */
		vector <Neuron> neurons_; 
		
		/**
		 *@brief collection of every connexions between the post/preSynaptic neurons :.
		 * create randomly connexion with the help of the uniform distribution .
		 * line : neurons index.
		 * column : postsaptic neurons pottentially spiked by the neuron from the line.
		 */
		vector<vector<int> > mapConnexion_;
		
		/**
		 *@brief realTime of the Network (time of the simulation)  
		 */
		int RealTime_= 0;
		
		/**
		 *@brief time which stop the simulation  
		*/ 
		int t_stop=1000;
		
	
	public : 
		
		//-----------CONSTRUCTOR_AND_DESTRUCTOR------------//
		
		/**
		 * @brief constructor
		 * @details the Network constructor have two task:. 
		 * first: generate a vector of neuron ("neurons_") (it is a collection of every neurons).
		 * => by the way, the constructor specify the type of neurons (excitator or inhibitor) when building of vector neurons_.
		 * 
		 * second: generate a vector of vector of int ("mapConnexion_") to generate the connexions between neurons .
		 *=> use the uniform distribtion to give back random values comprise in the definite boudaries (a low boudary, b high boundary). 
		 */ 
		Network();
		
		/**
		 * @brief Destructor 
		 * 
		 */
		~Network();
		
		//--------------------MAIN_METHODS---------------------//
		
		/**
		 *@brief it is the main methode of the classe Network, runs the simulation and updates the network every step and increment the realTime 
		 * => genrate the poisson distribution for the update of the neurons. 
		 * updates the network and updates the neurons with Iext=0. 
		 *=> When a neuron update it gives the info of if the neurons spike or not. 
		 *=> if a neuron spikes, depends of its type, the buffer of its postsynaptics neighbours will be filled.
		 *at least writes in the "spikesTable.txt".
		 */
		void simulation(); 
		
	
		//---------------DISPLAY_FUNCTIONS---------------//
		
		/**
		 *@brief print the neurons with their indexes 
		 *
		 */
		void printNeurons();
		
		/**
		 *@brief print the mapconnexions of the neurons to figurate the randoms connexions
		 * carefull works well with a number of neurons equal to 30 but not efficent when 12500 neurons.
		 *=> none of the methods calls printMapConnexion (just there to figure out the mapConnexion).
		 */
		void printMapConnexion();
	
		
		//------------------GETTERS-------------------//
		
		/** 
		 *@brief give the acces to a neuron at a specific position in the collection of neurons (I don't use this methode but could be interessant to have it) 
		 * 
		 * @param size__t j => (position - 1) of the neuron of interest 
		 * 
		 * @return neurons_[j] the specific neuron  
		 * 
		 */
		Neuron getNeuronsPosey(size_t j) const; 
		
		/** 
		 *@brief give the acces to a connection between a post and a pre synaptic neuron at a specific position in the mapCollection
		 * 
		 * @param size_t i the neuron index 
		 * 
		 * @param size_t j the postsynaptic connected to the i neuron  
		 * 
		 * => not used in the class Network (for the gtest).
		 * 
		 * @return neurons_[j] the specific postsynaptic neuron  
		 *
		 */
		int getMapConnexionPosey(size_t i, size_t j) const; 

		/** 
		 *@brief return the number of neurons from the collection of neurons of Network. (12500) 
		 * => not used in the class Network (for the gtest).
		 */
		size_t getNumbNeurons() const;
};
#endif
