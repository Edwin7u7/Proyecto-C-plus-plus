#include <iostream>   
using namespace std;
#include "funcion.h"
#include "pelicula.h"
#include "cine.h"
Cine cargarDatosPredeterminados(){
    //Cine//
    Cine cineUno(1, "Cinepolis", "Av. Principal No.123");
    //Horarios//
    vector<string> horarios_uno = {"12:00", "15:00", "18:00"};
    vector<string> horarios_dos = {"13:30", "16:00", "20:00"};
    //Peliculas//
    Pelicula peliculaUno(1, horarios_uno, "Familiar", "Zootopia 2");
    Pelicula peliculaDos(2, horarios_dos, "Terror", "Five Nights At Freddy's 2");
    Pelicula peliculaTres(3, horarios_dos, "Accion", "Los ilusionistas 3");
    Pelicula peliculaCuatro(4, horarios_uno, "Accion/Drama", "Avatar 3");
    //Salas//
    Sala salaUno(1,3,3);
    Sala salaDos(2,3,3);
    Sala salaTres(3,3,3);
    //Funciones//
    Funcion funcionUno(1, peliculaUno, horarios_uno[1],salaUno);
    Funcion funcionDos(2, peliculaUno, horarios_dos[2],salaDos);
    Funcion funcionTres(3, peliculaDos, horarios_uno[1],salaTres);
    Funcion funcionCuatro(4, peliculaDos, horarios_dos[0],salaDos);
    Funcion funcionCinco(5, peliculaTres, horarios_uno[2],salaUno);
    Funcion funcionSeis(6, peliculaTres, horarios_dos[2],salaTres);
    Funcion funcionSiete(7, peliculaCuatro, horarios_uno[0],salaUno);
    Funcion funcionOcho(8, peliculaCuatro, horarios_uno[2],salaTres);

    //Agregar funciones y peliculas al cine//
    cineUno.agregarPelicula(peliculaUno);
    cineUno.agregarPelicula(peliculaDos);
    cineUno.agregarPelicula(peliculaTres);
    cineUno.agregarPelicula(peliculaCuatro);

    cineUno.agregarFuncion(funcionUno);
    cineUno.agregarFuncion(funcionDos);
    cineUno.agregarFuncion(funcionTres);
    cineUno.agregarFuncion(funcionCuatro);
    cineUno.agregarFuncion(funcionCinco);
    cineUno.agregarFuncion(funcionSeis);
    cineUno.agregarFuncion(funcionSiete);
    cineUno.agregarFuncion(funcionOcho);
    return cineUno;

}
int main() {
    Cine cineMain = cargarDatosPredeterminados();
    bool procesoFinalizado = false;
    int opcion;
    while (procesoFinalizado == false){
        cout <<"=================================="<<endl;
        cout <<"              MENU             "<<endl;
        cout <<"=================================="<<endl;
        cout <<"       1-Ver Peliculas"<<endl;
        cout <<"       2-Ver Funciones"<<endl;
        cout <<"       3-Comprar Boleto"<<endl;
        cout <<"=================================="<<endl;
        
        cout << "Ingresa una opcion: ";
        cin >> opcion;
        if(opcion == 1){
            cineMain.mostrarPeliculas();
        }
        else if (opcion == 2)
        {
            cineMain.mostrarFunciones();
        }
        else if (opcion == 3)
        {
            bool continuar = false;
            while(continuar == false){
                int opcion;
                cineMain.mostrarFunciones();
                cout <<"Ingresa el Id de la funcion:";
                cin >> opcion;
                Funcion funcion = cineMain.seleccionarFuncionById(opcion);
                funcion.mostrarFuncion();
                cout <<"Desea continuar?"<<endl;
                cout <<"1-Si"<<endl;
                cout <<"2-Cambiar funcion"<<endl;
                cout <<"->";
                cin >> opcion;
                if(opcion == 1){
                    continuar = true;
                    cout <<"Cuantos boletos desea?"; 
                }
                //Aun esta en proceso...
                
            }
            
            

        }
        else
        {
            cout <<"Opcion Invalida";
        }
        
        
        
    }
    
    //Mostrar Pelicula individual
    /*pelicula_uno.mostrarPelicula();
    pelicula_dos.mostrarPelicula();

    //Mostrar Funcion individual
    funcion_uno.mostrarFuncion();
    funcion_dos.mostrarFuncion();
    
    //Mostrar Peliculas y Funciones disponibles
    cineUno.mostrarPeliculas();
    cineUno.mostrarFunciones();*/
    return 0;
    
}