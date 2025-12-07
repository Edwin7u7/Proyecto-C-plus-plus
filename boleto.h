#ifndef BOLETO_H
#define BOLETO_H

#include <iostream>
#include "Pelicula.h"
#include "Sala.h"
#include "Asiento.h"
using namespace std;

class Boleto {
protected:
    Pelicula pelicula;
    string horario;
    Sala sala;
    Asiento asiento;

public:
    //Constructores
    Boleto() {}

    Boleto(Pelicula pelicula, string horario, Sala sala, Asiento asiento)
        : pelicula(pelicula), horario(horario), sala(sala), asiento(asiento)
    {}
    //Metodo que heredan las clases Vip y Estandar
    virtual void mostrarBoleto() = 0;
};

#endif
