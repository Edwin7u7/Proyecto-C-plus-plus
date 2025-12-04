#ifndef ESTANDAR_H
#define ESTANDAR_H
#include <iostream>
#include "boleto.h"
using namespace std;
class Estandar : public Boleto{
    private:
        
        float precio;
    public:
        Estandar()
        : precio(90.0f){}

        Estandar(int idBoleto, Pelicula pelicula, string horario, Sala sala, 
                Asiento asiento)
            : Boleto(idBoleto, pelicula, horario, sala, asiento), precio(90.0f)
        {}

        void mostrarBoleto()override{
             cout << "\n------ BOLETO ESTANDAR ------\n";
            cout << "ID: " << idBoleto << endl;
            cout << "Pelicula: " << pelicula.getNombre() << endl;
            cout << "Horario: " << horario << endl;
            cout << "Sala: " << sala.getSalaId() << endl;
            cout << "Asiento Estandar: (" << asiento.getFila() << "," << asiento.getColumna() << ")\n";
            cout << "Precio: $" << precio << endl;
            cout << "-------------------------\n";
        }
};
#endif