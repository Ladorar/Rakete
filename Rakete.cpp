#include <iostream>
#include "Rakete.h"
#include "Triebwerk.h"
#include "Tank.h"
using namespace std;


void Rakete::einfuegen(Triebwerk triebwerk) {
    m_triebwerk.push_back(triebwerk);
}

void Rakete::einfuegen(Tank tank) {
    m_tank.push_back(tank);
}

double Rakete::berechneGewicht() {
    double gewichtTank = 0;
    double gewichtTriebwerk = 0;
    for ( int i = 0; i < m_tank.size(); i++) {
        gewichtTank =+ m_tank[i].gesamtgewicht();
    }
    for (int j = 0; j < m_triebwerk.size(); j++) {
        gewichtTriebwerk =+ m_triebwerk[j].gewicht;
    }
    return (gewichtTank + gewichtTriebwerk);
}

double Rakete::berechneTWR() {
    double gesamtSchub = 0;
    for (int i = 0; i < m_triebwerk.size(); i++) {
        gesamtSchub =+ m_triebwerk[i].schub; 
    }
    gesamtSchub = gesamtSchub*1000;
    return (gesamtSchub/(berechneGewicht()*9,807));    
}

double Rakete::berechneBrenndauer() {
    double gesamtTreibstoff = 0;
    double gesamtVerbrauch = 0;
    
    for (int i = 0; i < m_tank.size(); i++) {
        gesamtTreibstoff =+ m_tank[i].treibstoff();
    }
    
    for (int j = 0; j < m_triebwerk.size(); j++) {
        gesamtVerbrauch =+ m_triebwerk[j].verbrauch;
    }
    if (gesamtVerbrauch == 0) return 0;
    else return (gesamtTreibstoff/gesamtVerbrauch);
}

void Rakete::print() {
    cout << "Gesamtgewicht: " << berechneGewicht() << " kg" << endl;
    cout << "TWR: " << berechneTWR() << endl;
    cout << "Brenndauer: " << berechneBrenndauer() << " sec" << endl << endl;
    for (int i = 0; i < m_tank.size(); i++) {
        m_tank[i].print();
        cout << endl;
    }
    for (int j = 0; j < m_triebwerk.size(); j++) {
        m_triebwerk[j].print();
        cout << endl;
    }
}


