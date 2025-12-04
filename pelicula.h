#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <vector>
using namespace std;
class Pelicula{
    private:
        int idPelicula;
        vector<string> horarios;
        string descripcion;
        string nombre;
    public:
        //Constructores
        Pelicula(){}
        Pelicula(
            int idPelicula,
            vector<string> horarios,
            string descripcion,
            string nombre
        ): idPelicula(idPelicula), horarios(horarios), descripcion(descripcion),nombre(nombre)
        {}
        
        //GETTERS
        
        string getNombre() const { return nombre; }
        vector<string> getHorarios() const { return horarios; }

        //Metodos
        void mostrarPelicula()  {
        cout <<"Id:" <<idPelicula <<"\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Descripcion: " << descripcion << "\n";
        cout << "Horarios: ";
        for (auto &h : horarios) cout << h << " ";
        cout << "\n";
        cout << "-----------------------------\n";
        }
        
};

#endif