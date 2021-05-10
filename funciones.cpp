#include "funciones.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#define NOTAS "archivos/estudiantes.csv"

using namespace std;

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';

    while(getline(archivo, linea)) { // Entran así -> "ID";"NOMBRE";"PROM_LENG"; []...
        stringstream stream(linea);  // Convertir cadena a stream
        string idNum, idUnico, lenguaje, ingles, mats, ciencias, historia, tecnologia, arte, edfisica;

        // Obtener los datos del .csv
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

        // Eliminar las comillas
        idNum.erase(remove(idNum.begin(), idNum.end(), '\"'), idNum.end()); 
        idUnico.erase(remove(idUnico.begin(), idUnico.end(), '\"'), idUnico.end());
        lenguaje.erase(remove(lenguaje.begin(), lenguaje.end(), '\"'), lenguaje.end());
        ingles.erase(remove(ingles.begin(), ingles.end(), '\"'), ingles.end());
        mats.erase(remove(mats.begin(), mats.end(), '\"'), mats.end());
        ciencias.erase(remove(ciencias.begin(), ciencias.end(), '\"'), ciencias.end());
        historia.erase(remove(historia.begin(), historia.end(), '\"'), historia.end());
        tecnologia.erase(remove(tecnologia.begin(), tecnologia.end(), '\"'), tecnologia.end());
        arte.erase(remove(arte.begin(), arte.end(), '\"'), arte.end());   
        edfisica.erase(remove(edfisica.begin(), edfisica.end(), '\"'), edfisica.end());

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
        
        // Calculo de promedios
        float leng, mate;
        if(istringstream(lenguaje) >> leng && istringstream(mats) >> mate){
            cout << endl << "Promedio entre Lenguaje y Matematicas: " << (leng + mate) / 2 << endl;
        }
        
    }
    archivo.close();
}