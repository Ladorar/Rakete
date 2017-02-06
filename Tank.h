#include <iostream>

#ifndef TANK_H
#define	TANK_H

enum Art {
    TREIBSTOFF, NUTZLAST
};
class Tank {
public:
    std::string name;
    Art art;
    double leergewicht;
    double volumen;
    double fuellstand;
    
    Tank(std::string n, Art a, double l, double v, double f);
    void print();
    double gesamtgewicht();
    double treibstoff();
    
private:

};

#endif	/* TANK_H */

