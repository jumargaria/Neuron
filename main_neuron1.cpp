//
//  mainN.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
#include "constants.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>


int main (int argc,char*argv[]){
	
    double I_ext(1.01);
    int i_start=1000;//a
    int i_stop=4000;//b
    int t_stop=5000;
    
    
    Neuron n;
    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);

    if(argc>1){
        I_ext = atof(argv[1]);
    }
    
    std::cout << "I_ext=" << I_ext << "/n"<< std::endl;
    
    bool spike(false);
    for(int t=0; t<t_stop;++t){
        if((t>=i_start) and (t<=i_stop)){
            n.setI_ext(I_ext);
            spike = n.update(1);
         }else{
            n.setI_ext(0.0);
       
        }
        if (spike){
            std::cout << "Spike at t= " << (n.getTimeSpike()+i_start)*h << "ms" << std::endl;
               spike=false;
           
        }
        sortie<< n.double_to_string( n.getMembranePotential())<<std::endl;
    }
       sortie.close();
    return 0;
}
