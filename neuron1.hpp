//
//  neuron.hpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#ifndef neuron_hpp
#define neuron_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

class Neuron{
    public:
//====================Constructors---Destructors==================
    Neuron();
    ~Neuron(){};
//====================Update================== 
    bool update(long steps);
    void setI_ext(double I);
    long getTimeSpike()const;
    double getMembranePotential()const;
//====================Convertor==================  
    std::string double_to_string(double c)const;
    
    private:
    
//====================Attributs==================
    double MembranePotential_;
    long NbSpikes_;
    long TimeSpikes_;
    bool refractory_;
    double RefractoryStep_;
    long tsim_;
    double Iext_;
    
    

};

#endif /* neuron_hpp */
