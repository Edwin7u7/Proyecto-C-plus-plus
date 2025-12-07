#include <iostream>   
using namespace std;
#include "funcion.h"
#include "pelicula.h"
#include "cine.h"
#include "estandar.h"
#include "vip.h"

// Función que carga datos predeterminados del cine (películas, funciones, salas, etc.)
Cine cargarDatosPredeterminados(){
    // Crear cine
    Cine cineUno(1, "Cinepolis", "Av. Principal No.123");

    // Horarios disponibles
    vector<string> horarios_uno = {"12:00", "15:00", "18:00"};
    vector<string> horarios_dos = {"13:30", "16:00", "20:00"};

    // Películas con sus respectivos géneros y horarios
    Pelicula peliculaUno(1, horarios_uno, "Familiar", "Zootopia 2");
    Pelicula peliculaDos(2, horarios_dos, "Terror", "Five Nights At Freddy's 2");
    Pelicula peliculaTres(3, horarios_dos, "Accion", "Los ilusionistas 3");
    Pelicula peliculaCuatro(4, horarios_uno, "Accion/Drama", "Avatar 3");

    // Salas con filas y columnas de asientos
    Sala salaUno(1,3,3);
    Sala salaDos(2,3,3);
    Sala salaTres(3,3,3);

    // Funciones (cada función relaciona película, horario y sala)
    Funcion funcionUno(1, peliculaUno, horarios_uno[1],salaUno);
    Funcion funcionDos(2, peliculaUno, horarios_dos[2],salaDos);
    Funcion funcionTres(3, peliculaDos, horarios_uno[1],salaTres);
    Funcion funcionCuatro(4, peliculaDos, horarios_dos[0],salaDos);
    Funcion funcionCinco(5, peliculaTres, horarios_uno[2],salaUno);
    Funcion funcionSeis(6, peliculaTres, horarios_dos[2],salaTres);
    Funcion funcionSiete(7, peliculaCuatro, horarios_uno[0],salaUno);
    Funcion funcionOcho(8, peliculaCuatro, horarios_uno[2],salaTres);

    // Agregar películas al cine
    cineUno.agregarPelicula(peliculaUno);
    cineUno.agregarPelicula(peliculaDos);
    cineUno.agregarPelicula(peliculaTres);
    cineUno.agregarPelicula(peliculaCuatro);

    // Agregar funciones al cine
    cineUno.agregarFuncion(funcionUno);
    cineUno.agregarFuncion(funcionDos);
    cineUno.agregarFuncion(funcionTres);
    cineUno.agregarFuncion(funcionCuatro);
    cineUno.agregarFuncion(funcionCinco);
    cineUno.agregarFuncion(funcionSeis);
    cineUno.agregarFuncion(funcionSiete);
    cineUno.agregarFuncion(funcionOcho);

    // Retornar cine con datos cargados
    return cineUno;
}

int main() {
    // Cargar datos iniciales del cine
    Cine cineMain = cargarDatosPredeterminados();

    bool procesoFinalizado = false; // Control del ciclo del menú
    int opcion; // Variable para almacenar la opción del usuario

    // Ciclo principal del menú
    while (procesoFinalizado == false){
        // Mostrar menú
        cout <<"=================================="<<endl;
        cout <<"              MENU             "<<endl;
        cout <<"=================================="<<endl;
        cout <<"       1-Ver Peliculas"<<endl;
        cout <<"       2-Ver Funciones"<<endl;
        cout <<"       3-Comprar Boleto"<<endl;
        cout <<"=================================="<<endl;
        
        cout << "Ingresa una opcion: ";
        cin >> opcion;

        // Opción 1: Mostrar películas
        if(opcion == 1){
            cineMain.mostrarPeliculas();
        }
        // Opción 2: Mostrar funciones
        else if (opcion == 2)
        {
            cineMain.mostrarFunciones();
        }
        // Opción 3: Comprar boleto
        else if (opcion == 3)
        {
            bool elegirFuncion = false; // Control para elegir función
            int idFuncion; // ID de la función seleccionada
            Funcion funcion; // Objeto función temporal
            
            // Ciclo para seleccionar función
            while(!elegirFuncion){
                
                cineMain.mostrarFunciones();

                cout <<"Ingresa el Id de la funcion: ";
                cin >> idFuncion;
                bool verificarFuncion = cineMain.verificarFuncionEnCine(idFuncion);
                if(verificarFuncion == true){
                    // Seleccionar función por ID
                    funcion = cineMain.seleccionarFuncionById(idFuncion);
                    funcion.mostrarFuncion();

                    // Confirmar selección
                    cout <<"Desea continuar?"<< endl;
                    cout <<"1 - Si" << endl;
                    cout <<"2 - Cambiar funcion" << endl;
                    cout <<"-> ";
                    cin >> opcion;

                    if(opcion == 1){
                        elegirFuncion = true;
                    }
                }else{
                    cout <<"Funcion inexistente "<<endl;
                }
                
            }

            // ************ ELEGIR ASIENTO ************
            Sala &sala = cineMain.obtenerSalaDeFuncion(idFuncion);

            cout << "\n=== ASIENTOS EN LA SALA " << sala.getSalaId() << " ===\n";
            sala.mostrarAsientos();

            int f,c; // Fila y columna del asiento
            bool asientoValido = false;

            // Ciclo para validar asiento
            while(!asientoValido){
                cout << "\nIngrese la fila del asiento: ";
                cin >> f;
                cout << "Ingrese la columna del asiento: ";
                cin >> c;

                // Verificar disponibilidad
                if(sala.asientoDisponible(f,c)){
                    sala.ocuparAsiento(f,c);
                    cout << "\nAsiento (" << f << ":" << c << ") reservado con exito.\n";
                    asientoValido = true;
                }
                else{
                    cout << "\nEse asiento esta ocupado o no existe, intente otro.\n";
                }
            }
            // Crear objeto asiento
            Asiento asiento(f,c,false);

            // ************ TIPO DE BOLETO ************
            cout << "\nSeleccione el tipo de boleto:" << endl;
            cout << "1 - VIP" << endl;
            cout << "2 - Estandar" << endl;
            cout << "-> ";
            int tipo;
            cin >> tipo;

            cout << "\n=== BOLETO GENERADO ===" << endl;

            // Generar boleto según tipo
            if(tipo == 1){
                Vip boleto(funcion.getPelicula(), funcion.getHorario(),sala,asiento);
                boleto.mostrarBoleto();
            } 
            else {
                Estandar boleto(funcion.getPelicula(), funcion.getHorario(),sala,asiento);
                boleto.mostrarBoleto();
            }

            cout << "------------------------" << endl;
            cout << "Compra finalizada.\n\n";
        }
        // Opción inválida
        else
        {
            cout <<"Opcion Invalida";
        }
    }
    
    return 0;
}