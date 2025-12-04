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
        Sala(){};
        Sala(int id_sala,
        int filas,
        int columnas)
        :
        idSala(idSala),filas(filas),columnas(columnas)
        {
            //Aqui se ve efectuada la relacion de composición con la clase de Asiento
            for(int f = 1; f <= filas; f++){
                for(int c=1; c <= columnas; c++){
                    Asiento asiento(f,c,false);
                    asientos.push_back(asiento);
                }
            }
        };

        bool asientoDisponible(int fila,int columna){
            for(auto &a : asientos)
                if(a.getFila() == fila && a.getColumna() == columna){
                    return a.estaDisponible();
                }
            return false;   
            
        }

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

        void mostrarAsientos(){
            for(auto &a : asientos){
                cout << "Asiento:  (" << a.getFila()<< ":" << a.getColumna() <<")";
                cout << "->"<<(a.estaDisponible() ? "Disponible": "Ocupado") << endl; 
            }
        }

        int getSalaId() const{
            return idSala;
        }
};
#endif