//
//  mainN.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
int main (){
Neuron n;
    double h(0.1);
    double tstart(0);
    double tstop(100);
    double Iext (2.0);
    double a(20.0);
    double b(40.0);
    n.update( h,tstart, tstop, Iext,a,b);

    return 0;
}
