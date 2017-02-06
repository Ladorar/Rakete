#include <iostream>
#include "Triebwerk.h"
using namespace std;

Triebwerk::Triebwerk(std::string n, double s, double v, double g) {
    name = n;
    schub = s;
    verbrauch = v;
    gewicht = g;
}
void Triebwerk::print() {
    cout << "Name: " << name << endl;
    cout << "Gewicht: " << gewicht << " kg" << endl;
    cout << "Schub: " << schub << " kN" << endl;
    cout << "Verbrauch: " << verbrauch << "kg/sec" << endl;    
}



