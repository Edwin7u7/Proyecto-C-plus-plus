#ifndef VIP_H
#define VIP_H
#include <iostream>
#include "boleto.h"
using namespace std;
class Vip :public Boleto{
    private:
        string beneficios;
        float precio;
    public:
        //Constructores
        Vip()
        : precio(180.0f), beneficios("Incluye asiento premium + palomitas grandes") {}

        Vip( Pelicula pelicula, string horario, Sala sala, 
                Asiento asiento)
            : Boleto(pelicula, horario, sala, asiento),
            precio(180.0f),
            beneficios("Incluye asiento premium + palomitas grandes")
        {}
        //Este metodo es el que hereda de la clase Boleto
        void mostrarBoleto() override{
             cout << "\n------ BOLETO VIP ------\n";
            cout << "Pelicula: " << pelicula.getNombre() << endl;
            cout << "Horario: " << horario << endl;
            cout << "Sala: " << sala.getSalaId() << endl;
            cout << "Asiento VIP: (" << asiento.getFila() << "," << asiento.getColumna() << ")\n";
            cout << "Beneficio: " << beneficios << endl;
            cout << "Precio VIP: $" << precio << endl;
            cout << "-------------------------\n";
        }
};
#endif