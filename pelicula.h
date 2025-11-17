#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <vector>
using namespace std;
class Pelicula{
    private:
        int id_pelicula;
        vector<string> horarios;
        string descripcion;
        string nombre;
    public:
        //Constructores
        Pelicula(){}
        Pelicula(
            int id_pelicula,
            vector<string> horarios,
            string descripcion,
            string nombre
        ): id_pelicula(id_pelicula), horarios(horarios), descripcion(descripcion),nombre(nombre)
        {}
        
        //GETTERS
        int getId() const { return id_pelicula; }
        string getNombre() const { return nombre; }
        string getDescripcion() const { return descripcion; }
        vector<string> getHorarios() const { return horarios; }

        //Metodos
        void mostrarPelicula() const {
        cout << "Nombre: " << nombre << "\n";
        cout << "Descripcion: " << descripcion << "\n";
        cout << "Horarios: ";
        for (auto &h : horarios) cout << h << " ";
        cout << "\n";
        cout << "-----------------------------\n";
        }
        
};

#endif