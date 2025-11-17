#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include <vector>
#include "pelicula.h"
class Funcion{
    private:
        int id_funcion;
        Pelicula pelicula;
        string horario;
    public:
        //Constructores
        Funcion(){}
        Funcion(
            int id_funcion,
            Pelicula pelicula,
            string horario
        ):id_funcion(id_funcion), pelicula(pelicula),horario(horario)
        {}
        //GETTERS
        Pelicula getPelicula() const { return pelicula; }
        string getHorario() const { return horario; }

        //Metodos
        void mostrarFuncion() const {
        cout << "Pelicula: " << pelicula.getNombre() << "\n";
        cout << "Horario : " << horario << "\n";
        cout << "-----------------------------\n";
        }
};

#endif