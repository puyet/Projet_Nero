# Projet_Neuro

#General description 

This program simulates a neural spiking network following them Leaky integrate and fire model (LIF) presented by Nicholas Brunel in "Dynamics of Sparsely Connected Networks of Excitatory and Ihnibitory Spiking Neurons" (Brrunel, N. J. Comp Neuronscience 2000). The neurons produce impulses, called "spikes" they sent to others, those spikes are characterized by their time of occurence and weigh, corresponding to the action potential of neurons. 

The network is composed of: 10 000 excitatory neurons and 2 500 inhibitory neurons. 
Each neuron receives imput form 10% of the other neurons, namly 1 250 neurons. The difference between those 2 types of neurons is their behaviour with their postsynaptic neurons. The excitatory ones enhances the potential of the neurons connected to it and the inhibitory ones reduces it. The neurons are represented by a Neuron class caracterize by a type of neuron (enum TypeNeuron: E for excitator and I for inhibitator). 

The network, represented by a Newtwork class, contains a vector of neurons that constitute it. Each neuron is characterized in the network and is randomly connected to the others ones. 
In the network class is the main methode simulation which run the global simulation, it is responsible for the evolution of the network in time (ie update the networks and the neurons manufacture the informations and print the results in a text file). 

The final output of the program is graphs representing the activity of the network. The network can be in 4 macrostates, generally defined by the microstates and interactions of the neurons composing it. So there are 4 versions of the output graphs that can be generated. The different states of the network are caracterized by some constants, g: external imput and the frenquence needed for a neuron to reach a threshold. 
Those states are : 

-A. Synchronized network and regulary firing neurons g=3, Vext/Vthr =2
-B. Fast oscillation of the global activity and irregulary firing neurons g=6, Vext/Vthr = 4
-c. Stationary global activity and irregularly firing neurons g=5, Vext/Vthr2
-D. Slow oscillations of the global activity and irregularly firing neurons g=4.5, Vext/Vthr =0.9

To draw the graphs, I used Jupyter and comands given on moodle (=> just change 2 commands s =3, rwidth = 0.3 to be more coherent with brunel's paper). 

#Repository Content 
-CMakeList.txt : contents all of what is necessary to execute the test and generate Doxygen
-Cst.hpp : contents all the constants used to simulate the network and the neurons 
-Doxyfile.in
-Network.hpp : The hpp Network class, commented on each method and parameters to explain how do they work
-Network.cpp : The cpp Network class, detailed methods with comments to explain some implementations 
-Neuron.hpp :  The hpp Neuron class, commented on each method and parameters to explain how do they work
-Neuron.cpp :The cpp Neuron class, detailed methods with comments to explain some implementations 
-gtest.cpp : Test used to verify that the differents methods from the different classes work in the right way. contains 8 tests wich work. 
-Network_Test.cpp : The main(), allowed to run the simuation of a network and its neurons. in optionnal can print the neurons and the map of the connexion (only 50 neurons) 
-README.md : Explain the project and how to deal with 
-Results of the simulation of 12500 neurons according to Brunel's Paper.pdf : pdf file wich compare my results for the 4 versions of the output graphs to the brunel's results 
-SpikesTable1.txt : version a of the output graphs generated with jupyter 
-SpikesTable2.txt : version b of the output graphs generated with jupyter
-SpikesTable3.txt : version c of the output graphs generated with jupyter
-SpikesTable4.txt : version d of the output graphs generated with jupyter

#How to compile the program: 
1. make
2. use the command ./neuron_unittest in the terminal to se the results of the gtest 
3. use the command ./NetworkTest in the terminal to run the simualtion of a network and its neurons. 

Laura Puyet SV BAIII Projet_Neuro EPFL 2017 
