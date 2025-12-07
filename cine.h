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
    string nombre;
    string direccion;
    vector<Funcion> funciones;
    vector<Pelicula> peliculas;
public:
    //Constructores
    Cine(){}
    Cine(
        int id, 
        string nombre, 
        string direccion     
    ):

        id(id), nombre(nombre), direccion(direccion)
        {}
    
    //Getters
    
    string getNombre() const { return nombre; }
    

    //Metodos
    //Este metodo muestra las peliculas que estan en el vector 
    void mostrarPeliculas() {
        cout <<"====================";
        cout << "    Cartelera:\n"; 
        cout <<"====================";
        for (size_t i = 0; i < peliculas.size(); ++i) {
            peliculas[i].mostrarPelicula();
            cout << "-----------------------------\n";
        }
    }
    //Este metodo muestra las funciones que estan en el vector 
    void mostrarFunciones() {
        cout <<"====================\n";
        cout << "   Funciones:\n"; 
        cout <<"====================\n";
        for (size_t i = 0; i < funciones.size(); ++i) {
            funciones[i].mostrarFuncion();
            cout << "-----------------------------\n";
        }
    };
    //Se agrega la pelicula al vector
    void agregarPelicula(Pelicula p) {
    peliculas.push_back(p);
    }
    //Se agrega la Funcion al vector
    void agregarFuncion(Funcion f) {
        funciones.push_back(f);
    }
    //Se obtiene el objeto Funcion a partir de un id
    Funcion seleccionarFuncionById(int idFuncion){
        for(size_t i = 0; i < funciones.size(); i++){
            if(idFuncion == funciones[i].getId()){
                return funciones[i];
            }
        }
        return Funcion();
    }
    //Se obtiene el objeto Sala original
    Sala& obtenerSalaDeFuncion(int idFuncion){
        for(auto &f : funciones){
            if(f.getId() == idFuncion){
                return f.getSala();
            }
            
        }
        throw runtime_error("Funcion no encontrada");
    }

    bool verificarFuncionEnCine(int idFuncion){
        for(size_t i = 0; i < funciones.size(); i++){
            if(idFuncion == funciones[i].getId()){
                return true;
            }
        }
        return false;
    }
    
};

#endif
