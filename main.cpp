#include <iostream>
#include "funciones.h"

using namespace std;

/**
*   TAREA 01 - COMPUTACIÓN PARALELA Y DISTRIBUIDA
*
 */

int main()
{
    cout << "=== Integrantes ===" << endl << endl;
    cout << "Axel Jerez" << endl;
    cout << "Sebastian Munoz" << endl;
    leerdatos();
    cout << endl << endl;
	
    //imprimirEspecifico(18);

    cout << endl << endl << "=== DEBUG ===" << endl;
    ordenarMaximos(10);
	crearCSV();

	/* for(int i = 0; i < 50; i++) {
		imprimirEspecifico(i);
	} */

    return 0;
}