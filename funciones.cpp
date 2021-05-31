#include "funciones.h"

#define NOTAS "archivos/estudiantes.csv"
#define MAX 20000
#define LIMITE 50

using namespace std;

/* 
*		TO DO:
*	- Crear los .csv nuevos con sus datos correspondientes. (LISTO)
*	- Eliminar los primeros 100 espacios del arreglo principal.
*	- 
*	- 
*	-
 */

string Estudiante[MAX][15];
int length;

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';
    int i = 0;

    while(getline(archivo, linea)) { // Entran así -> "ID";"NOMBRE";"PROM_LENG"; []...
        stringstream stream(linea);  // Convertir cadena a stream
        string idNum, idUnico, lenguaje, ingles, mats, ciencias, historia, tecnologia, arte, edfisica; // Variables para los datos del .csv
        string promedioUno, promedioDos, promedioTres, promedioCuatro; // Variables para insertar los promedios en la matriz
        float promGeneral, promArtistico, promHumanista, promTecnico;
        float leng, mate, ing, ciencia, hist, tecno, art, edfis;


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
        Estudiante[i][10] = " ";
        Estudiante[i][11] = " ";
        Estudiante[i][12] = " ";
        Estudiante[i][13] = " ";

        // Calculo de promedios
        if(istringstream(lenguaje) >> leng && istringstream(mats) >> mate && istringstream(ciencias) >> ciencia && istringstream(ingles) >> ing && istringstream(arte) >> art && istringstream(historia) >> hist && istringstream(tecnologia) >> tecno && istringstream(edfisica) >> edfis) {
             promGeneral = (leng + mate + ing + art + tecno + hist + edfis + ciencia) / 8 ;
             promArtistico = (art + edfis) / 2 ;
             promHumanista = (leng + hist) / 2;
             promTecnico = (tecno + mate + ciencia) / 3;

             ostringstream(promedioUno) << promGeneral;
             promedioUno = to_string(promGeneral);
             promedioDos = to_string(promArtistico);
             promedioTres = to_string(promHumanista);
             promedioCuatro = to_string(promTecnico);
             Estudiante[i][10] = promedioUno;
             Estudiante[i][11] = promedioDos;
             Estudiante[i][12] = promedioTres;
             Estudiante[i][13] = promedioCuatro;
        }

        // Imprimir
        cout << endl << "========" << "[" << i << "]" <<"========" << endl;
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
        cout << "------ Promedios ------" << endl;
        cout << "Promedio General: " << Estudiante[i][10] << endl;
        cout << "Promedio Artistico: " << Estudiante[i][11] << endl;
        cout << "Promedio Humanista: " << Estudiante[i][12] << endl;
        cout << "Promedio Tecnico: " << Estudiante[i][13] << endl;

        i++;
    }
	length = i; // Obtener la cantidad de datos
    archivo.close();
}

void ordenarMaximos(int pos) {  // 10 = gral, 11 = artistico, 12 = humanista, 13 = tec
	float temp;
	string aux, auxDos;

	for(int i = 0; i < length; i++) {
		for(int j = i + 1; j < length; j++) {
			if(stof(Estudiante[j][pos]) > stof(Estudiante[i][pos])) {
				//cout << endl << stof(Estudiante[j][10]) << " y " << stof(Estudiante[i][10]) << endl;//DEBUG
				temp = stof(Estudiante[j][pos]);
				//cout << "temp[float]: " << temp << endl;//DEBUG
				Estudiante[j][pos] = Estudiante[i][pos];
				Estudiante[i][pos] = to_string(temp);
				//cout << "temp[string]: " << to_string(temp) << endl << endl;//DEBUG
				for(int cont = 0; cont < pos; cont++) {
                    aux = Estudiante[j][cont];
                    Estudiante[j][cont] = Estudiante[i][cont];
                    Estudiante[i][cont] = aux;
                }
				for(int contDos = pos + 1; contDos < 14; contDos++) {
                    auxDos = Estudiante[j][contDos];
                    Estudiante[j][contDos] = Estudiante[i][contDos];
                    Estudiante[i][contDos] = auxDos;
                }
			}
		}
	}
	//DEBUG
	//cout << endl << "pos: " << pos << endl;
	for(int cont = 0; cont < LIMITE; cont++) {
		cout << Estudiante[cont][0] << ": " << Estudiante[cont][pos] << endl;
	}
}

void crearCSV() {
	ofstream archivo("archivos/maximos.csv");
	for(int i = 0; i < LIMITE; i++) {
		archivo << "\"" << Estudiante[i][0] << "\"" << ";";
		archivo << "\"" << Estudiante[i][1] << "\"" << ";";
		
		if(i < LIMITE - 1) {
			archivo << "\"" << Estudiante[i][10] << "\"" << endl;
		} else {
			archivo << "\"" << Estudiante[i][10] << "\"";
		}
	}
	archivo.close();
}

void imprimirEspecifico(int i) {
    cout << endl << "========" << "[" << i << "]" <<"========" << endl;
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
        cout << "------ Promedios ------" << endl;
        cout << "Promedio General: " << Estudiante[i][10] << endl;
        cout << "Promedio Artistico: " << Estudiante[i][11] << endl;
        cout << "Promedio Humanista: " << Estudiante[i][12] << endl;
        cout << "Promedio Tecnico: " << Estudiante[i][13] << endl;
}
