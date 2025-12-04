#ifndef ASIENTO_H
#define ASIENTO_H
class Asiento{
    private:
        int fila;
        int columna;
        bool disponible;
    public:
        Asiento(){};
        Asiento(int fila, int columna , int disponible):
        fila(fila),columna(columna),disponible(disponible)
        {};

        bool estaDisponible() const {
            return disponible;
        }

        void ocupar(){
            disponible = false;
        }

        int getFila(){
            return fila;
        };

        int getColumna(){
            return columna;
        };

};
#endif