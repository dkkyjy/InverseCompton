#include <math.h>
#include <stdio.h>
#include "InverseCompton.h"

double c = 1.00e+10;
double h = 6.63e-27
double m_e = 9.11e-28;
double r_e = 2.818e-13;

//gamma * m_e * c**2 is the energy of electron;
//E0 * m_e * c**2 is the energy of soft photon;
//E * m_e * c**2 is the energy of scattered photon.

double Kappa(double gamma, double E0, double E){
    return E / (4 * E0 * gamma * (gamma - E));
}

double C(double gamma, double E0, double E){
    double k = Kappa(gamma, E, E0);
    return 2 * M_PI * r_e * r_e * c / (gamma * gamma * E0)\
    * (2 * k * log(k) + (1+2*k)*(1-k) + (4*E0*gamma*k)*(4*E0*gamma*k)*(1-k) / (2 * (1+4*E0*gamma*k)));
}

double n_E0(double E0, double j, double k, double R){
    double C_corr = 0.75;
    return 4 * M_PI / (h * c * E0) * C_corr * j / k * (1 - exp(-k * R));
}

double q(double gamma, double E0, double E){
    double n = n_E0(E0, j, k, R);
    return ;
}

double Emin(double gamma, double E0){
    return E0;
}

double Emax(double gamma, double E0){
    return gamma * (4 * E0 * gamma) / (1 + 4 * E0 * gamma);
}

double j(double E){
    return h / (4 * M_PI) * E * q;
}

double nu(double E){
    return E * m_e * c * c / h;
}