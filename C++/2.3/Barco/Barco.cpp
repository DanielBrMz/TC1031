#include "Barco.h"

// Constructor
Barco::Barco(std::string fecha, std::string hora, std::string punto_entrada, std::string UBI)
    : fecha(fecha), hora(hora), punto_entrada(punto_entrada), UBI(UBI), next(nullptr) {}