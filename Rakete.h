#include <vector>
#include "Tank.h"
#include "Triebwerk.h"
using namespace std;

#ifndef RAKETE_H
#define	RAKETE_H

class Rakete {
public:
    std::vector<Triebwerk> m_triebwerk;
    std::vector<Tank> m_tank;
    
    void einfuegen(Triebwerk triebwerk);
    void einfuegen(Tank tank);
    double berechneGewicht();
    double berechneTWR();
    double berechneBrenndauer();
    void print();
    
private:

};

#endif	/* RAKETE_H */

