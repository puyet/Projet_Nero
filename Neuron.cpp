#include "Neuron.hpp"
#include "Cst.hpp"

#include <iostream>
#include <cmath>
#include <vector>
//#include <array>

using namespace std; 

Neuron:: Neuron ()
: memb_pot_(Vr), localClock_(0.0), isRefractory_(false), RingBuffer_(D+1, 0)
{}

//
void Neuron:: update_neuron(double Iext){
//cout<<"Buffer@Position" << getBufferPosey(localClock_)<<endl;
	if (isRefractory_==false) {
	
		if(memb_pot_>= Teta) {	 
	
			spikes_.push_back(localClock_); 		 
			memb_pot_ = Vr; //clean mem_pot value ; 
			isSpiking_=true; //the neuron will spike 
			//SpikeNeighbours(Iext); //spike the neighbours
			for (size_t i(0); i<TargetNeighbours_.size(); ++i){
			//cout<<"NNN"<<endl;
			TargetNeighbours_[i]->setBuffer(localClock_+D, J); 	
			}  
			isRefractory_=true; //se refractorise
			
			cout<<"coucou je spike"<<endl; 
		 }else if (spikes_.empty() or memb_pot_< Teta){

				pot_calcul(dt, Iext, RingBuffer_[getBufferPosey(localClock_)]);
				isSpiking_=false; 
				//cout<<"coucou je ne spike ppas"<<endl; 		
		}
	
	
	
	} else if (isRefractory_== true) {
		if (localClock_>= (spikes_.back() +Tau_rp) and !spikes_.empty()) {
						 
			isRefractory_ = false; 
		}
		//cout<<"refractory"<<endl; 
		isSpiking_ = false; 
	} 

	RingBuffer_[getBufferPosey(localClock_)]=0;
///est ce que je mets bien a jour mon buffer a chaque pas de dt ?? 
	++localClock_; 
}
void Neuron:: pot_calcul(double dt, double Iext, double j) {
    
     
     double cst1 = exp(-(dt/Tau));
     double cst2 = (1-cst1)*R; 
     memb_pot_ = (cst1*memb_pot_) + (cst2*Iext) +j; 
}


//mise a jour du buffer  v
void Neuron::setBuffer(int t, double j) {
	int i = getBufferPosey(t);
	cout<<"setBuffer"<<endl; 
	RingBuffer_[i] += j;
	//cout<<"ring "<<RingBuffer_[i]<<endl; 
	
}

void Neuron::addConnexion(Neuron * neur){
	TargetNeighbours_.push_back(neur);
	
}
		

//------------------GETTERS-------------------//


	
vector <double> Neuron::getSpikes() const {
		
	return spikes_; 
}

vector <Neuron*>Neuron::getTargetNeighbours() const{
	
	return TargetNeighbours_; 
	
} 
	
size_t Neuron::getNumbSpikes() const {
	
	return spikes_.size(); 	
	
}

double Neuron::getMemb_pot() const {
	
	return memb_pot_; 
}

double Neuron::getTimeForSpike(size_t j) const{
	
	return spikes_[j];
}

int Neuron::getBufferPosey(int t) const{
	
	int i = t % (D+1);
	
	return i;
}

/*void Neuron::SpikeNeighbours(double Iext){
	
	if(isSpiking_== true) {
		for(size_t i=0; i < TargetNeighbours_.size(); i++){
			TargetNeighbours_[i]->pot_calculSpiked(dt,Iext); // mettre getisSplike dedans Je t'ai spikée de tant J a trouver dans le paper  
			
			//while (
			
			//n1 écrit dans le buffer 
			}					
	}
}
*/
/*void Neuron::Buffer(int i, int localClock_){
	
	RingBuffer_[i]=localClock_ + D % RingBuffer_.size();
}
*/
/*void Neuron:: pot_calculSpiked(double dt, double Iext) {
		 
     double cst1 = exp(-(dt/Tau));
     double cst2 = (1-cst1)*(Tau/C); 
     memb_pot_ = (cst1*memb_pot_) + (cst2*Iext) + J; //je laisse J constant car no idee  
     
     cout<<"meuha t'es spiké"<<endl; 
}	
	*/



//add J to the neighbours when n1 is spikfing and set localClock to n2 with delay 
/*void Neuron::writeInBuffer(Neuron* neur) {
	
	if(isSpiking_==true) {
		///pas sure: (je remplis mon tableau de voisins) 
		//TargetNeighbours_.push_back(neur); // a mettre dans le network 
		
		neur->setBuffer((localClock_+D)%(D+1), J); 	
	}
}*/

//incrementer mon buffer (array) -> methode qui va aller voir dans une case a chaque pas de dt.... ==> quand N1 écrit dedans array (-> (passer en argument de la méthode le localTime de n1) localtime de n1 + D(=1,5ms) % taille du buffer, N2 va le lire dans arry localtime de n2 % taille du buffer  


	
		//"ReadInBuffer"
		
			/*cout<<"ringBuffer"<<endl; 
			//ad j to his memb_pot 
			memb_pot_ += RingBuffer_[localClock_%(D+1)];
			//clear the case 
			RingBuffer_[localClock_%(D+1)]=0; 
		
	}*/


/*TO DO : 

(refaire SPikeNeighbours : 
* kill isSpiked_ 
* mettre ce que fait getisSpiked() dans SpikeNeighbours calculer J avec une formule ie leur mettre le calcul de la memebre 
* 
* faire le buffer 
*  N2 lis dans le buffer dans update )
* 
* // trouver un moyen pour que N2 sache qu'il a été spiké ............... surememnt a N1 de lui dire mais comment????????????????????????
* TROUVER COMMENT CALCULER J !!!!!!!!!!!!!!!!!!!!!!!!!
* 
* 
* 
-------------
* 
* PROBLEME URGENT " array does not name a type" AAAAAAAAAACH bon j'ai mis un vector 
* est ce que je mets bien a jour mon buffer a chaque pas de dt ??faire moi  
* faut il remplir tableau de voisins ? oui 
* //comment faire avec network : genre je decide que c'est network qui appelle des méthodes ou alors je passe ntwork en attribut de mon neuron bla bla 
* faire une fomction test MHMHMH?????:
* -CMake 
* -Google 
* //SUIS UN PEU EN GALERE AVEC POINTEURS :::::::::::REVOIR:::::::::::::
* 
* 
* 
* 
* 
* 
*/
