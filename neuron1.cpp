//
//  neuron.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "constants.hpp"
 

//Constructors
Neuron:: Neuron():MembranePotential_(0),NbSpikes_(0),TimeSpikes_(0),refractory_(false), RefractionTime_(0){}
Neuron:: Neuron(double MembranePotential,int NbSpikes,double TimeSpikes,bool refractory, double RefractionTime):
MembranePotential_(MembranePotential),NbSpikes_(NbSpikes),TimeSpikes_(TimeSpikes),
refractory_(refractory),RefractionTime_(RefractionTime){}


std::string Neuron::double_to_string(double c)const{

std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

void Neuron:: update(double h, double tstart, double tstop, double Iext,double a, double b){
    
    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);
    
    double Input_current;
    double tsim(tstart);

    
    while(tsim<tstop){
		   
        if((tsim>=a) and (tsim<=b)){
            Input_current = Iext;
        }else{
            Input_current = 0.0;
         }
        
        if(refractory_){
            MembranePotential_= 0.0;
            RefractionTime_+=h;
            
             if(RefractionTime_ > TAU) {
               RefractionTime_=0;
               refractory_=false;
            }
            
        }else if(MembranePotential_>THRESHOLD){
			//TAU est une constante qui correspond au temps ou neurone est refractory
            TimeSpikes_= tsim;
            refractory_= true;
        }
        
     sortie<<double_to_string( MembranePotential_)<<std::endl;
        
     MembranePotential_= exp(-h/TAU)* MembranePotential_+ Iext*RESISTANCE*(1-exp(-h/TAU));

        
    }
    
    tsim+=h;
    
    sortie.close();
    
}





