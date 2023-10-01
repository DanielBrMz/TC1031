// Barco.h
#ifndef BARCO_H
#define BARCO_H

#include <string>

class Barco {
public:
    std::string fecha;
    std::string hora;
    std::string punto_entrada;
    std::string UBI;
    Barco* next;

    Barco(std::string fecha, std::string hora, std::string punto_entrada, std::string UBI);
};

#endif // BARCO_H
