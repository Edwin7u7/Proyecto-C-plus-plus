#ifndef BOLETO_H
#define BOLETO_H

#include <iostream>
#include "Pelicula.h"
#include "Sala.h"
#include "Asiento.h"
using namespace std;

class Boleto {
protected:
    int idBoleto;
    Pelicula pelicula;
    string horario;
    Sala sala;
    Asiento asiento;

public:
    Boleto() {}

    Boleto(int idBoleto, Pelicula pelicula, string horario, Sala sala, Asiento asiento)
        : idBoleto(idBoleto), pelicula(pelicula), horario(horario), sala(sala), asiento(asiento)
    {}

    virtual void mostrarBoleto() = 0;
};

#endif
