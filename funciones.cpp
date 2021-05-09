#include "funciones.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define NOTAS "archivos/estudiantes.csv"

using namespace std;

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';

    while(getline(archivo, linea)) {
        stringstream stream(linea);  //convertir cadena a stream
        string idNum, idUnico, lenguaje, ingles, mats, ciencias, historia, tecnologia, arte, edfisica;
        getline(stream, idNum, delimitador);
        getline(stream, idUnico, delimitador);
        getline(stream, lenguaje, delimitador);
        getline(stream, ingles, delimitador);
        getline(stream, mats, delimitador);
        getline(stream, ciencias, delimitador);
        getline(stream, historia, delimitador);
        getline(stream, tecnologia, delimitador);
        getline(stream, arte, delimitador);       
        getline(stream, edfisica, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "ID: " << idNum << endl;
        cout << "Nombre: " << idUnico << endl;
        cout << "Promedio Lenguaje: " << lenguaje << endl;
        cout << "Promedio Ingles: " << ingles << endl;
        cout << "Promedio Matematicas: " << mats << endl;
        cout << "Promedio Ciencias Naturales: " << ciencias  << endl;
        cout << "Promedio Historia: " << historia << endl;
        cout << "Promedio Tecnologia: " << tecnologia << endl;
        cout << "Promedio Arte: " << arte << endl;
        cout << "Promedio Edfisica: " << edfisica << endl;
    }
    archivo.close();
}