#ifndef CINE_H
#define CINE_H

#include <iostream>
#include "funcion.h"
#include "pelicula.h"
#include <vector>

using namespace std;

class Cine
{
private:
    int id;
    string nombre_cine;
    string direccion;
    vector<Funcion> funciones;
    vector<Pelicula> peliculas;
public:
    //Constructores
    Cine(){}
    Cine(
        int id, 
        string nombre_cine, 
        string direccion     
    ):

        id(id), nombre_cine(nombre_cine), direccion(direccion)
        {}
    
    // GETTERS
    int getId() const { return id; }
    string getNombre() const { return nombre_cine; }
    string getDireccion() const { return direccion; }

    //Metodos
    
    void mostrarPeliculas() {
        cout <<"====================";
        cout << "    Cartelera:\n"; 
        cout <<"====================";
        for (size_t i = 0; i < peliculas.size(); ++i) {
            peliculas[i].mostrarPelicula();
            cout << "-----------------------------\n";
        }
    }

    void mostrarFunciones() {
        cout <<"====================";
        cout << "   Funciones:\n"; 
        cout <<"====================";
        for (size_t i = 0; i < funciones.size(); ++i) {
            funciones[i].mostrarFuncion();
            cout << "-----------------------------\n";
        }
    };

    void agregarPelicula(Pelicula p) {
    peliculas.push_back(p);
    }

    void agregarFuncion(Funcion f) {
        funciones.push_back(f);
    }

    Funcion seleccionarFuncionById(int idFuncion){
        for(size_t i = 0; i < funciones.size(); i++){
            if(idFuncion == funciones[i].getId()){
                return funciones[i];
            }
        }
        return Funcion();
    }
    
};

#endif
