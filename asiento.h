#ifndef ASIENTO_H
#define ASIENTO_H
class Asiento{
    private:
        int fila;
        int columna;
        bool disponible;
    public:
        //Constructores
        Asiento(){};
        Asiento(int fila, int columna , int disponible):
        fila(fila),columna(columna),disponible(disponible)
        {};
        //Metodos

        //Se usa para verificar si esta disponible o no al momento de mostrar los aisentos
        bool estaDisponible() const {
            return disponible;
        }
        //Se usa para cambiar el status del asiento de disponible a ocupado
        void ocupar(){
            disponible = false;
        }
        //Getters
        int getFila(){
            return fila;
        };

        int getColumna(){
            return columna;
        };

};
#endif