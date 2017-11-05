/**
 * @file Neuron.hpp
 * @brief file containing the statements of a Neuron class
 *
 */
#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include "Cst.hpp"

using namespace std;

/**
 * @class Neuron Neuron.hpp 
 * @brief class representing a Neuron. 
 * this class contains various attributes and methods necessary to neurons 
 * 
 */ 
class Neuron {
	
	private: 
		
		//------------ATRIBUTES-----------//
		
		/**
		 *@brief Membrane potential (V) of neuron
		 */
		double memb_pot_; //!the membrane potential (stockage) will aways be reaffected and modify with stat of neuron through methode and formule Vi(t)
		
		/**
		 *@brief local clock of a neuron (sychronisated with the realTime of the network) 
		 */
		int localClock_;
		
		
		/**
		*@brief Boolean used to determine if the neuron is refractory.
		* \a true if the neuron is refractory.
		*\a false in the other case. 
		*/
		bool isRefractory_;
		
		/**
		 *@brief collection of each time of every spikes done by the neuron 
		 */
		vector <double> spikes_;
		
		/**
		 *@brief mémory which evolute with the time of a neuron, store the Amplitudes from the neighbourhs when they spikes the neuron.   
		 */
		vector <double> RingBuffer_;
		
		/**
		 *@brief indicate the type of neurons :.
		 * Excitator (E) or Inhibitor (I)   
		 */
		TypeNeuron typeNeuron_; 

		
	public:
		
		//-----------CONSTRUCTOR_AND_DESTRUCTOR------------//
		/**
		 * @brief Default constructor
		 * 
		 */ 
		Neuron();
		
		/**
		 * @brief Constructor. initialize the potential of the membrane to 0, the localClock to 0, isRefractory at false, the ringBuffer size at D+1 (16) and full of 0 and the type of neuron 
		 * @param TypeNeuron the type of the neuron (Excitator or Inhibitor) 
		 *  
		 */ 
		Neuron(TypeNeuron type);
		
		/**
		 * @brief Destructor 
		 * 
		 */
		~Neuron() {}; 
		
		//--------------------MAIN_METHODS---------------------//
		
		
		/**
		 * @brief Update_neuron : it is the main fonction of the simulation of a neuron:.
		 * 
		 * 1. if the neuron isn't refractory :.
		 * two cases possibles:.
		 *	1.1. the neuron reaches the treshold, spikes, reset its membran and turn to refractory true. 
		 * 	1.2. the neuron doesn't reach the treshold, first check:.
		 * if its ring buffer empty or not, then calcul of its potential of its membrane .
		 * with a Iext =0, dt=0.1, Jbuffer wich comes from the buffer, and the background noise's spikes.
		 * 
		 * 2. if the neuron is refractory : .
		 * stay in this state (ie with a potential of its membrane =0) for a refractory time of 20 steps.
		 * 3. increment the localclock at each update . 
		 * 
		 * @param double Iext: the external current 0 now. 
		 * @param double Poisson which represents the spikes from the background noise. 
		 */
		void update_neuron(double Iext, double Poisson); 
		
		/**
		 *@brief calcule the potential of the membrane in fuction of the time te currant ext Iext and le currant J and also random external V  
		 * 
		 * @param double dt time (the parameter dt is optional let just more freedom for the simulation) 
		 * @param double Iext the external current 
		 * @param double j the current J 
		 * @param double Poisson the background noise's spike amplitude 
		 */
		void pot_calcul(double dt, double Iext, double j, double poisson); 
		
		/**
		 *@brief set the buffer of a neuron => put the curant J in the buffer at a specific place for a neuron with the help of getBufferposey
		 * 
		 * @param int t the time corresponding to a place in the buffer  
		 * @param double j the currant J 
		 *
		 * 
		 */
		void setBuffer(int t, double j); 
		
		
		//--------------GETTERS_&_SETTERS-------------------//
		
		/** 
		 *@brief gives the number of spikes 
		 * 
		 * @return spikes_.size() which is the size of the vector of spikes so it corresponds to the number of spikes 
		 * 
		 */
		size_t getNumbSpikes() const; //the size of the vector is the #of Spikes because each time one happends it is store
		
		/**
		 *@brief gives the time t of when a spike happens 
		 * 
		 * @param size_t data the size of the vector of spikes 
		 * 
		 * @return the time stocked in the vector spikes_
		 * 
		 */
		double getTimeForSpike(size_t data) const; 
		
		/** 
		 *@brief gives acces to the value of mem_pot
		 * 
		 * @return double mem_pot the membran potential 
		 * 
		 */
		double getMemb_pot() const;  
		
		/**
		 *@brief gives access to the vector of spikes
		 * 
		 * @return vector<double> spikes_ 
		 * 
		 */
		vector <double> getSpikes() const; 
		
		
		/**
		 *@brief gives which position of the buffer correspond to a time t
		 * 
		 * @param int t the time
		 * 
		 * @return int i the position corresponding to the time 
		 * 
		 */
		int getBufferPosey(int t)const;
		
		
		/**
		 *@brief gives the Local clock of the associated neuron  
		 * 
		 * @return int LocalClock_ the local clock of the neuron 
		 * 
		 */
		int getLocalClock() const ; 	  
		
		/**
		 *@brief gives the information of the state refractory or not
		 * principally used for testing than using 
		 * @return bool isRefractory when a neuron refractory it is true 
		 * 
		 */
		bool getisRefractory() const; 
		
		/**
		 *@brief gives the RingBuffer back 
		 * (I never use this methode but could be interessant to acces to the ring buffer from out of the neuron) 
		 * 
		 *@return vector <double> RingBuffer : the memory of a Buffer
		 * 
		 */
		vector <double> getRingBuffer() const;
		
		/**
		 *@brief gives the info about the type of a neuron (Excitator/inhibitor) 
		 * 
		 *@return bool : 
		 *-true if the neuron is excitator 
		 *-false if the neuron is inhibitor 
		 */
		bool isExcitatory(); 
		
		/**
		 *@brief gives info about if a neuron spikes or not 
		 * 
		 * @param int step the local time of the neuron 
		 * 
		 * @return bool: .
		 *-false if the neuron doesn't spike (the vector of spikes is empty). 
		 *-true if the neuron spikes (if the current time corresponds with the last time of a spike => the neuron just spikes now) . 
		 */
		bool getIsSpiking(int step)const; 
};
	
	
#endif 
