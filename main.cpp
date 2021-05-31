#include <iostream>
#include "funciones.h"

using namespace std;

/**
*   TAREA 01 - COMPUTACIÓN PARALELA Y DISTRIBUIDA
*
 */

int main()
{
    int dato = 10;
    leerdatos();
	while(dato != 14) {
		ordenarMaximos(dato);
		crearCSV(dato);
		limpiarArreglo();
		dato++;
	}
    cout << "=== Integrantes ===" << endl << endl;
    cout << "Axel Jerez" << endl;
    cout << "Sebastian Munoz" << endl;
    return 0;
}