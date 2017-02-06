#include <string>

#ifndef TRIEBWERK_H
#define	TRIEBWERK_H

class Triebwerk {
public:
    std::string name;
    double schub;
    double verbrauch;
    double gewicht;
    Triebwerk( std::string n, double s, double v, double g);
    void print();
private:

};

#endif	/* TRIEBWERK_H */

