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
            int idFuncion,
            Pelicula pelicula,
            string horario,
            Sala sala
        ):idFuncion(idFuncion), pelicula(pelicula),horario(horario),sala(sala)
        {}
        //Getters
        
        string getHorario() const { return horario; }
        Pelicula getPelicula() {return pelicula;}
        int getId() const {return idFuncion;}
        //Se agregaron dos metodos nombrados de la misma forma
        // - Versión no-const: permite modificar la sala (ocupar asientos, etc.)
        // - Versión const: permite consultar la sala sin modificarla
        Sala& getSala() { return sala; } 
        const Sala& getSala() const { return sala; }

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