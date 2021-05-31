#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
/* 
    - pos: La posición del promedio en el arreglo (10 = general, 11 = artistico, 12 = humanista, 13 = tecnico).
*/ 

void leerdatos(); // Función que abre estudiantes.csv y los guarda en una matriz.
void ordenarMaximos(int pos); // Funcion con un método de ordenamiento
void crearCSV(int pos); // Crea el archivo .csv correspondiente
void limpiarArreglo(); // Elimina del arreglo las primeras 100 posiciones.

#endif /* FUNCIONES_H */