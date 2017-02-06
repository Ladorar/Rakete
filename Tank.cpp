#include <string>
#include <iostream>

#include "Tank.h"
using namespace std;

Tank::Tank (std::string n, Art a, double l, double v, double f) {
    name = n;
    art = a;
    leergewicht = l;
    volumen = v;
    fuellstand = f;
}

void Tank::print() {
    string type;
    if (art == 0) type = "Treibstoff";
    else type = "Nutzlast";
    cout << "Name: " << name << endl;
    cout << "Art: " << type << endl;
    cout << "Leergewicht: " << leergewicht << " kg" << endl;
    cout << "Volumen: " << volumen << endl;
    cout << "Fuellstand: " << fuellstand << " %" << endl;
    cout << "Gesamtgewicht: " << gesamtgewicht() << " kg" << endl;
}

double Tank::gesamtgewicht() {
    return (leergewicht + (volumen*(fuellstand/100)));
}

double Tank::treibstoff() {
    return (volumen*(fuellstand/100));
}