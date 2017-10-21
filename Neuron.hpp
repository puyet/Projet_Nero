#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
//#include <array>

using namespace std;



class Neuron {
	
	private: 
		
		
		double memb_pot_; //the membrane potential (stockage) will aways be reaffected and modify with stat of neuron through methode and formule Vi(t)
		int localClock_;//local time of own neurone
		bool isSpiking_; //spikes = true // 
		//va devoir stocker son nombre de step de simulation (=local clock)   
		//Network myNetwork; pas de network pour l'instant  
		bool isRefractory_; // = true if the neuron is refractory 
		//bool isSpiked_; //condition supplemantaire dans mon update A AJOUTER 
		
		vector <double> spikes_;
		vector <Neuron*> TargetNeighbours_; //tableau de ses voisins  
 
		vector <double> RingBuffer_; //=> mémoire des J qu'on ajoute a N2  
		
	public:
		//constructor & destructor 
		Neuron(); // pas sure des attributs de la classe
		~Neuron() {}; 
	
		
		//methods which will care about potential membrane way ==> guide the neuron state
		void update_neuron(double Iext); 
		//calcul the memb_pot
		
		/*! 
		 *@brief calcule the potential of the membrane in fuction of the time te currant ext Iext and le currant J  
		 * 
		 * @param double dt time double Iext the external current and double j the current J 
		 * 
		 * */
		
		void pot_calcul(double dt, double Iext, double j); 
		
		/*! 
		 *@brief fill the vector targetNeighbour with a specific neuron wich util now be considered as his neighbour
		 * 
		 * @param Neuron *neur is the neighbour that a neuron will know that he can spike him 
		 * 
		 * */
		void addConnexion(Neuron * neur);
		/*! 
		 *@brief set the buffer of a neuron => put the curant J in the buffer at a specific place for a neuron with 
		 * the help of getBufferposey
		 * 
		 * @param int t the time corresponding to a place in the buffer and double j the currant J 
		 * 
		 * */
		void setBuffer(int t, double j); 
		
		
		//--------------getters & setters-------------------
		
		/*! 
		 *@brief give the number of spikes 
		 * 
		 * @return spikes_.size() which is the size of the vector of spikes so it corresponds to the number of spikes 
		 * 
		 * */
		size_t getNumbSpikes() const; //the size of the vector is the #of Spikes because each time one happends it is store
		
		/*! 
		 *@brief give the time t of when a spike happens 
		 * 
		 * @param size_t date the size of the vector of spikes 
		 * 
		 * @return the time stocked in the vector spikes_
		 * 
		 * */
		double getTimeForSpike(size_t data) const; 
		
		/*! 
		 *@brief give acces to the value of mem_pot
		 * 
		 * @return double mem_pot the membran potential 
		 * 
		 * */
		double getMemb_pot() const;  
		
		/*! 
		 *@brief gives access to the vector of spikes
		 * 
		 * @return a vector<double> spikes_ 
		 * 
		 * */
		vector <double> getSpikes() const; 
		
		/*! 
		 *@brief give to a neuron the list of his neighbours 
		 * 
		 * @return vector <Neuron*> TargetNeighbours : the list of neighbours
		 * 
		 * */
		vector <Neuron*> getTargetNeighbours()const; 
		
		/*! 
		 *@brief give which position of the buffer correspond to a time t
		 * 
		 * @param double t the time
		 * 
		 * @return int i the position corresponding 
		 * 
		 * */
		int getBufferPosey(int t)const;
		
		
		
		
		
		
		
		
		
		//bool getisSpiked();
		
		//void writeInBuffer(Neuron* neur); //établis une connexion entre mes neurons ie remplis le vector de neighbours .... 
	

		
		//void pot_calculSpiked(double dt, double Iext); //calcul en ajoutant J car spiké a reecire redondance de code avec pot_calcul
		//void SpikeNeighbours(double Iext);//elle va spiker ses voisins  : - quoi comme attributs, -quoi comme type etc... (passer isSpiked de false à true mais pour l'autre neurone d'ou la complexité) 
		//void Buffer(int localClock_); // mis a jour du tableau cyclique à chaque pas de dt avec un temps de delay D (est appele dans update pour etre remplie) 
		
		
		//spikeSafe
		  

};
	
	
#endif 
