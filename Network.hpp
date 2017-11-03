/**
 * @file Netwoek.hpp
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
		 *@brief collection of all the neurons in the network (size N which is 12500 neurons) 
		 */
		vector <Neuron> neurons_; 
		
		/**
		 *@brief collection of every connexions between the post/preSynaptic neurons and is ordonate to have the 10'000 first which are excitators ans the 2'500 last which ar hinibitors 
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
		
		/**
		 *@brief External current Iext 
		 */ 
		//double Iext=0.0; 
	
	public : 
		
		//-----------CONSTRUCTOR_AND_DESTRUCTOR------------//
		
		/**
		 * @brief constructor
		 * @details the Network constructor have two task: 
		 * first: generate a vector of neuron ("neurons_") (it is a collection of every neurons) 
		 * second: generate a vector of vector of int ("mapConnexion_") to generate the connexion between neurons 
		 * => by the way, the constructor specify the type of neurons (excitator or inhibitor) depends of the place in the mapConnexion_
		 */ 
		Network();
		
		/**
		 * @brief Destructor 
		 * 
		 */
		~Network();
		
		//--------------------MAIN_METHODS---------------------//
		
		/**
		 *@brief methods which use the uniform distribution to give back random value comprises in the definite boundaries
		 * 
		 * @param int a the low boundary int b the high boundary
		 * 
		 * @return int dis(gen) a random value comprise between a and b  
		 *
		 */
		int randomSelection(int a, int b, int c);
		
		/**
		 *@brief methods which fill the vector of neurons with neurons 
		 * 
		 * @param Neuron newNeuron 
		 *
		 */
		void addNeurons(Neuron newNeuron); 
		
		/**
		 *@brief methods which run the simulation of a network (ie call the update) every step and increment the realTime 
		 *
		 */
		void simulation(); 
		
		/**
		 *@brief methods which :
		 *1.fill by Jtot (sum of amplitude) the buffer of a postSynaptic neuron when the connexion between the neurons exist and if the preSynaptic neuron is spiking 
		 *=> so transmet the info of spiking/spiked to the neurons 
		 * (this method takes care of the type of the neurons)
		 *2.call the update of the neurons 
		 */
		void update_network(); 
		
		//vector<vector<unsigned int> > getRandomSpikes(int realTime, int tStop) const; 
		
		//vector<unsigned int> getCounterSpikes(int realTime, int tStop) const;
		
		//---------------DISPLAY_FUNCTIONS---------------//
		
		/**
		 *@brief print the neurons with their indexes 
		 *
		 */
		void printNeurons();
		/**
		 *@brief print the mapconnexions of the neurons to figurate the randoms connexions
		 * carefull works well with a number of neurons equal to 13 but not efficent when 12500 neurons
		 *
		 */
		void printMapConnexion();
		
		
		void printNeuronSpikes(); 
		
		void printSpikeTimes(); 
		//------------------GETTERS-------------------//
		
		/** 
		 *@brief give the acces to a neuron at a specific position in the collection of neurons 
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
		 * @param size__t i => (position - 1) of the postSynaptic neuron, size__t j => (position - 1) of the preSynaptic neuron
		 * 
		 * @return neurons_[j] the specific neuron  
		 * 
		 */
		int getMapConnexionPosey(size_t i, size_t j) const; 

		//void addConnexion(int indexNeuron, int sizeVector); 
		
		size_t getNumbNeurons() const;
};
#endif
