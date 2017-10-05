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

class Neuron{
    public:
//====================Constructors---Destructors==================
    Neuron();
    Neuron(double MembranePotential,int NbSpikes,double TimeSpikes,bool refractory, double RefractionTime);
    ~Neuron(){};
//====================Update================== 
    void update(double h,double tstart, double tstop, double Iext,double a, double b);
//====================Convertor==================  
    std::string double_to_string(double c)const;
    
    private:
    
//====================Attributs==================
    double MembranePotential_;
    int NbSpikes_;
    double TimeSpikes_;
    bool refractory_;
    double RefractionTime_;
    
    

};

#endif /* neuron_hpp */
