#include "Rakete.h"
#include "Tank.h"
#include "Triebwerk.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


void tanklisteausgeben(vector<Tank>& tanks) {
    for (int i = 0; i < tanks.size(); i++) {
        cout << i+1 << endl;
        tanks[i].print();
        cout << endl;
    }
}

void triebwerklisteausgeben (vector<Triebwerk>& triebwerke) {
    for (int i = 0; i < triebwerke.size(); i++) {
        cout << i+1 << endl;
        triebwerke[i].print();
        cout << endl;
    }
}

void addtank(vector<Rakete>& rakete, vector<Tank>& tanks) {
    int inputindex;
    double inputpercent;
    cout << "Bitte Nummer des Tanks eingeben welcher hinzugefügt werden soll." << endl;
    cin >> inputindex;
    cout << "Zu wieviel Prozent soll der Tank gefüllt sein?" << endl;
    cin >> inputpercent;
    rakete[0].einfuegen(tanks[inputindex-1]);
    rakete[0].m_tank[rakete[0].m_tank.size()-1].fuellstand = inputpercent;
}

void addthruster(vector<Rakete>& rakete, vector<Triebwerk>& triebwerke) {
    int inputindex;
    cout << "Bitte Nummer des Triebwerks aeingeben welches hinzugefügt werden soll." << endl;
    cin >> inputindex;
    rakete[0].einfuegen(triebwerke[inputindex-1]);
}

int menu() {
    vector<Rakete> rakete (1);
    vector<Tank> tanks;
    vector<Triebwerk> triebwerke;
    tanks.push_back(Tank("kleiner Treibstofftank", TREIBSTOFF, 1, 20, 0 ));
    tanks.push_back(Tank("kleiner Nutzlastcontainer", NUTZLAST, 1, 10, 0 ));
    tanks.push_back(Tank("mittlerer Treibstofftank", TREIBSTOFF, 3, 80, 0 ));
    tanks.push_back(Tank("großer Nutzlastcontainer", NUTZLAST, 5, 100, 0 ));
    tanks.push_back(Tank("großer Treibstofftank", TREIBSTOFF, 5, 200, 0 ));
    triebwerke.push_back(Triebwerk("LVT-30", 2000, 0.5, 2.5));
    triebwerke.push_back(Triebwerk("LVT-80", 10000, 1.5, 10.5));
    triebwerke.push_back(Triebwerk("LVT-45", 3500, 0.75, 4));
    while (1) {
        char auswahl;
        cout << "1. Tankliste ausgeben" << endl;
        cout << "2. Triebwerksliste ausgeben" << endl;
        cout << "3. Rakete anzeigen" << endl;
        cout << "4. Tank hinzufügen" << endl;
        cout << "5. Triebwerk hinzufügen" << endl;
        cout << "x. Beenden" << endl;
        cin >> auswahl;
        switch (auswahl) {
            case '1': tanklisteausgeben(tanks);
                break;
            case '2': triebwerklisteausgeben(triebwerke);
                break;
            case '3': rakete[0].print();
                break;
            case '4': addtank(rakete, tanks);
                break;
            case '5': addthruster(rakete, triebwerke);
                break;
            case 'x': return 0;
                break;
            default: cout << "ungueltige Eingabe!" << endl;            
        }
    }
}

int main() {
    menu();
    return 0;
}

