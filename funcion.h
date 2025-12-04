#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include <vector>
#include "pelicula.h"
#include "sala.h"
class Funcion{
    private:
        int idFuncion;
        Pelicula pelicula;
        string horario;
        Sala sala;
    public:
        //Constructores
        Funcion(){}
        Funcion(
            int id_funcion,
            Pelicula pelicula,
            string horario,
            Sala sala
        ):idFuncion(idFuncion), pelicula(pelicula),horario(horario),sala(sala)
        {}
        //GETTERS
        
        string getHorario() const { return horario; }
        int getId() const {return idFuncion;}
        //Metodos
        void mostrarFuncion()  {
        cout <<"Id: " <<idFuncion<<"\n";
        cout << "Pelicula: " << pelicula.getNombre() << "\n";
        cout << "Horario : " << horario << "\n";
        cout << "Sala:" <<sala.getSalaId() << "\n";
        cout << "-----------------------------\n";
        }
};

#endif