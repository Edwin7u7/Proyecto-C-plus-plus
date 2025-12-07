#ifndef SALA_H
#define SALA_H
#include <iostream>
#include <vector>
#include "asiento.h"
using namespace std;
class Sala{
    private:
        int idSala;
        int filas;
        int columnas;
        vector<Asiento> asientos;
    public:
        //Constructores
        Sala(){};
        Sala(int idSala,
        int filas,
        int columnas)
        :
        idSala(idSala),filas(filas),columnas(columnas)
        {
            //Aqui se ve efectuada la relacion de composición con la clase de Asiento
            for(int f = 1; f <= filas; f++){
                for(int c=1; c <= columnas; c++){
                    Asiento asiento(f,c,true);
                    asientos.push_back(asiento);
                }
            }
        };
        //Verifica si el asiento elegido por el usuario esta disponible
        bool asientoDisponible(int fila,int columna){
            for(auto &a : asientos)
                if(a.getFila() == fila && a.getColumna() == columna){
                    return a.estaDisponible();
                }
            return false;   
            
        }
        //Ocupa el asiento elegido por el usuario si este esta disponible
        bool ocuparAsiento(int fila, int columna){
            for(auto &a : asientos)
                if(a.getFila() == fila && a.getColumna() == columna){
                  if(a.estaDisponible() == true){
                    a.ocupar();
                    return true;
                  } 
                  return false;
                } 
            return false;
        }
        //Muestra la lista de los asientos y su respectivo status
        void mostrarAsientos(){
            for(auto &a : asientos){
                cout << "Asiento:  (" << a.getFila()<< ":" << a.getColumna() <<")";
                cout << "->"<<(a.estaDisponible() ? "Disponible": "Ocupado") << endl; 
            }
        }
        //Getters
        int getSalaId() {
            return idSala;
        }
};
#endif