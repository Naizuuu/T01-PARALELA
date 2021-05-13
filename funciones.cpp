#include "funciones.h"

#define NOTAS "archivos/estudiantes.csv"
#define MAX 20000

using namespace std;

string Estudiante[MAX][10];

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';
    int i = 0;

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

        // Ingresar datos en matriz
        Estudiante[i][0] = idNum;
        Estudiante[i][1] = idUnico;
        Estudiante[i][2] = lenguaje;
        Estudiante[i][3] = ingles;
        Estudiante[i][4] = mats;
        Estudiante[i][5] = ciencias;
        Estudiante[i][6] = historia;
        Estudiante[i][7] = tecnologia;
        Estudiante[i][8] = arte;
        Estudiante[i][9] = edfisica;

        // Imprimir
        cout << "========" << "[" << i << "]" <<"========" << endl;
        cout << "Identificador: Nro. " << Estudiante[i][0] << endl;
        cout << "Nombre: " << Estudiante[i][1] << endl;
        cout << "Promedio Lenguaje: " << Estudiante[i][2] << endl;
        cout << "Promedio Ingles: " << Estudiante[i][3] << endl;
        cout << "Promedio Matematicas: " << Estudiante[i][4] << endl;
        cout << "Promedio Ciencias Naturales: " << Estudiante[i][5]  << endl;
        cout << "Promedio Historia: " << Estudiante[i][6] << endl;
        cout << "Promedio Tecnologia: " << Estudiante[i][7] << endl;
        cout << "Promedio Arte: " << Estudiante[i][8] << endl;
        cout << "Promedio Edfisica: " << Estudiante[i][9] << endl;

        // Calculo de promedios
        /*float leng, mate;
        if(istringstream(lenguaje) >> leng && istringstream(mats) >> mate){
            cout << endl << "Promedio entre Lenguaje y Matematicas: " << (leng + mate) / 2 << endl;
        }*/
        i++;
    }
    archivo.close();
}

void imprimirEspecifico(int i) {
    cout << "========" << "[" << i << "]" <<"========" << endl;
    cout << "Identificador: Nro. " << Estudiante[i][0] << endl;
    cout << "Nombre: " << Estudiante[i][1] << endl;
    cout << "Promedio Lenguaje: " << Estudiante[i][2] << endl;
    cout << "Promedio Ingles: " << Estudiante[i][3] << endl;
    cout << "Promedio Matematicas: " << Estudiante[i][4] << endl;
    cout << "Promedio Ciencias Naturales: " << Estudiante[i][5]  << endl;
    cout << "Promedio Historia: " << Estudiante[i][6] << endl;
    cout << "Promedio Tecnologia: " << Estudiante[i][7] << endl;
    cout << "Promedio Arte: " << Estudiante[i][8] << endl;
    cout << "Promedio Edfisica: " << Estudiante[i][9] << endl;
}
