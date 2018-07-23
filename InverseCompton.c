#include <math.h>
#include <stdio.h>
#include "InverseCompton.h"
/*
 * Follow the paper A&A 367, 809-825 (2001)
 * THe multifrequency emission of Mrk 501 from radio to TeV gamma-rays
 */ 

double c = 1.00e+10;
double h = 6.63e-27
double m_e = 9.11e-28;
double r_e = 2.818e-13;

//gamma * m_e * c**2 is the energy of electron;
//Es * m_e * c**2 is the energy of Synchrotron photon;
//Ec * m_e * c**2 is the energy of InverseCompton photon.

double Kappa(double Ec, double gamma, double Es){
    return Ec / (4 * Es * gamma * (gamma - Ec));
}

double C(double Ec, double gamma, double Es){
    double k = Kappa(Ec, gamma, Es);
    return 2 * M_PI * r_e * r_e * c / (gamma * gamma * Es)\
    * (2 * k * log(k) + (1+2*k)*(1-k) + (4*Es*gamma*k)*(4*Es*gamma*k) / (2 * (1+4*Es*gamma*k)) * (1-k));
}

double n_Es(double Es, double j, double k, double R){
    return (3./4) * (4*M_PI) / (h*c*Es) * (j/k) * (1 - exp(-k*R));
}

double Emin(double gamma, double E0){
    return E0;
}

double Emax(double gamma, double E0){
    return gamma * (4 * E0 * gamma) / (1 + 4 * E0 * gamma);
}

double q(double Ec, double gamma, double E0){
    double n_E0 = n_E0(E0, j, k, R);
    double n_gamma = PowerLaw(gamma, K, p, gamma_min, gamma_max);
    
    double C = C(gamma, E0, E);

    return ;
}

double j(double Ec){
    double q = q(Ec);
    return h / (4 * M_PI) * Ec * q;
}

double nu(double Es){
    return Es * m_e * c * c / h;
}
