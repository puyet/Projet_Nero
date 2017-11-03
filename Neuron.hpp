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
		
		/** Membrane potential (V) of neuron.*/
		double memb_pot_; //!the membrane potential (stockage) will aways be reaffected and modify with stat of neuron through methode and formule Vi(t)
		
		/**
		 *@brief local clock of a neuron (sychronisated with the realTime of the network) 
		 */
		int localClock_;
		
		/**@brief Boolean used to determine if a neuron is spiking.
		* This boolean is set to : 
		*\a true if a spike was just sent.
		*\a false in the other case. 
		*/
		bool isSpiking_; //!spikes = true // 
		
		/**
		*@brief Boolean used to determine if the neuron is refractory.
		* \a true if the neuron is refractory
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
		
		TypeNeuron typeNeuron_; 

	public:
		
		//-----------CONSTRUCTOR_AND_DESTRUCTOR------------//
		/**
		 * @brief Default constructor
		 * 
		 */ 
		Neuron();
		
		Neuron(TypeNeuron type);
		/**
		 * @brief Destructor 
		 * 
		 */
		~Neuron() {}; 
		
		//--------------------MAIN_METHODS---------------------//
		
		
		/*
		 * WAIIIIIIT THE END TO EXPLAIN UPDATE CHANGE ALL THE TIME CPP AUSSI
		 */
		bool update_neuron(double Iext); 
		
		/**
		 *@brief calcule the potential of the membrane in fuction of the time te currant ext Iext and le currant J and also random external V  
		 * 
		 * @param double dt time double Iext the external current and double j the current J 
		 * 
		 */
		void pot_calcul(double dt, double Iext, double j); 
		
		/**
		 *@brief set the buffer of a neuron => put the curant J in the buffer at a specific place for a neuron with 
		 * the help of getBufferposey
		 * 
		 * @param int t the time corresponding to a place in the buffer and double j the currant J 
		 * 
		 */
		void setBuffer(int t, double j); 
		
		/** 
		 *@brief through a poisson distribution calculation of external random spikes
		 * 	
		 * @return double Jext which is the external amplitude make by random spike 
		 */
		double randomExternalSpikes(); 
		
		
		//--------------GETTERS_&_SETTERS-------------------//
		
		/** 
		 *@brief give the number of spikes 
		 * 
		 * @return spikes_.size() which is the size of the vector of spikes so it corresponds to the number of spikes 
		 * 
		 */
		size_t getNumbSpikes() const; //the size of the vector is the #of Spikes because each time one happends it is store
		
		/**
		 *@brief give the time t of when a spike happens 
		 * 
		 * @param size_t data the size of the vector of spikes 
		 * 
		 * @return the time stocked in the vector spikes_
		 * 
		 */
		double getTimeForSpike(size_t data) const; 
		
		/** 
		 *@brief give acces to the value of mem_pot
		 * 
		 * @return double mem_pot the membran potential 
		 * 
		 */
		double getMemb_pot() const;  
		
		/**
		 *@brief gives access to the vector of spikes
		 * 
		 * @return a vector<double> spikes_ 
		 * 
		 */
		vector <double> getSpikes() const; 
		
		
		/**
		 *@brief give which position of the buffer correspond to a time t
		 * 
		 * @param double t the time
		 * 
		 * @return int i the position corresponding 
		 * 
		 */
		int getBufferPosey(int t)const;
		
		/**
		 *@brief give the information of the state spiking or not of a Neuron 
		 * 
		 * @return bool isSpiking when a neuron spikes isSpiking is true 
		 * 
		 */
		bool getisSpiking() const ;
		
		/**
		 *@brief give the Local clock of the associated neuron  
		 * 
		 * @return int LocalClock_ the local clock of the neuron 
		 * 
		 */
		int getLocalClock() const ; 	  
		
		/**
		 *@brief give the information of the state refractory or not
		 * principally used for testing than using 
		 * @return bool isRefractory when a neuron refractory it is true 
		 * 
		 */
		bool getisRefractory() const; 
		
		/**
		 *@brief give the RingBuffer back
		 * 
		 * @return vector <double> RingBuffer : the memory of a Buffer
		 * 
		 */
		vector <double> getRingBuffer() const;
		
		bool isExcitatory(); 
		
};
	
	
#endif 
