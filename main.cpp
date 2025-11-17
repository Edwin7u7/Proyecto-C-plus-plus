#include <iostream>   
using namespace std;
#include "funcion.h"
#include "pelicula.h"
#include "cine.h"

int main(){
    Cine cine_uno(1, "Cinepolis", "Av. Principal No.123");

    vector<string> horarios_uno = {"12:00", "15:00", "18:00"};
    vector<string> horarios_dos = {"13:30", "16:00", "20:00"};

    Pelicula pelicula_uno(1, horarios_uno, "Superheroes y accion.", "Avengers");
    Pelicula pelicula_dos(2, horarios_dos, "Aventura animada familiar.", "Toy Story");

    Funcion funcion_uno(1, pelicula_uno, horarios_uno[1]);
    Funcion funcion_dos(2, pelicula_dos, horarios_dos[2]);

    cine_uno.agregarPelicula(pelicula_uno);
    cine_uno.agregarPelicula(pelicula_dos);

    cine_uno.agregarFuncion(funcion_uno);
    cine_uno.agregarFuncion(funcion_dos);

    //Mostrar Pelicula individual
    pelicula_uno.mostrarPelicula();
    pelicula_dos.mostrarPelicula();

    //Mostrar Funcion individual
    funcion_uno.mostrarFuncion();
    funcion_dos.mostrarFuncion();
    
    //Mostrar Peliculas y Funciones disponibles
    cine_uno.mostrarPeliculas();
    cine_uno.mostrarFunciones();
    return 0;
    
}