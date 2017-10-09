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
#include <cassert>
 

//Constructors
Neuron:: Neuron():MembranePotential_(0.0),NbSpikes_(0.0),TimeSpikes_(0.0),refractory_(false), RefractoryStep_(0.0),tsim_(0.0),Iext_(0.0) {}


void Neuron:: setI_ext(double I){
    Iext_=I;
}

long Neuron:: getTimeSpike()const{ return TimeSpikes_;}
double Neuron:: getMembranePotential()const{return MembranePotential_;}

std::string Neuron::double_to_string(double c)const{

std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

bool Neuron:: update(long steps){
    bool spike=false;

    if(steps<=0) return false;
    
    const long t_stop =tsim_+steps;
    
    while(tsim_<t_stop){
        
        
        if(refractory_){
            MembranePotential_= 0.0;
            ++RefractoryStep_;
            
             if(RefractoryStep_ > REF_STEPS) {
               RefractoryStep_=0;
               refractory_=false;
            }
            
        }else if(MembranePotential_>THRESHOLD){
            
            ++NbSpikes_;
            TimeSpikes_= tsim_;
            refractory_= true;
            spike=true;
           
        }
        
        
     MembranePotential_= exp(-h/TAU)* MembranePotential_+ Iext_*RESISTANCE*(1-exp(-h/TAU));
      ++tsim_;
        
    }
    return spike;
    
}





