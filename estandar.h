#ifndef ESTANDAR_H
#define ESTANDAR_H
#include <iostream>
#include "boleto.h"
using namespace std;
class Estandar : public Boleto{
    private:
        
        float precio;
    public:
        //Constructores
        Estandar()
        : precio(90.0f){}

        Estandar(Pelicula pelicula, string horario, Sala sala, 
                Asiento asiento)
            : Boleto(pelicula, horario, sala, asiento), precio(90.0f)
        {}
        //Este metodo es el que hereda de la clase Boleto
        void mostrarBoleto()override{
             cout << "\n------ BOLETO ESTANDAR ------\n";
            cout << "Pelicula: " << pelicula.getNombre() << endl;
            cout << "Horario: " << horario << endl;
            cout << "Sala: " << sala.getSalaId() << endl;
            cout << "Asiento Estandar: (" << asiento.getFila() << "," << asiento.getColumna() << ")\n";
            cout << "Precio: $" << precio << endl;
            cout << "-------------------------\n";
        }
};
#endif