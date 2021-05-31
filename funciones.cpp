#include "funciones.h"

#define NOTAS "archivos/estudiantes.csv"
#define MAX 20000
#define LIMITE 100 // Datos que se agregan a los nuevos archivos .csv

using namespace std;

string Estudiante[MAX][15];
int length;

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';
    int i = 0;

    while(getline(archivo, linea)) { // Entran así -> "ID";"NOMBRE";"PROM_LENG";"[...]"
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
				temp = stof(Estudiante[j][pos]);
				Estudiante[j][pos] = Estudiante[i][pos];
				Estudiante[i][pos] = to_string(temp);
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
}

void crearCSV(int pos) { // 10 = gral, 11 = artistico, 12 = humanista, 13 = tec
	if(pos == 10) {
		ofstream archivo("archivos/maximos.csv");
		for(int i = 0; i < LIMITE; i++) {
			archivo << "\"" << Estudiante[i][0] << "\"" << ";";
			archivo << "\"" << Estudiante[i][1] << "\"" << ";";
			
			if(i < LIMITE - 1) {
				archivo << "\"" << Estudiante[i][pos] << "\"" << endl;
			} else {
				archivo << "\"" << Estudiante[i][pos] << "\"";
			}
		}
		archivo.close();
	}
  	if(pos == 11) {
		ofstream archivo("archivos/artistico.csv");
		for(int i = 0; i < LIMITE; i++) {
			archivo << "\"" << Estudiante[i][0] << "\"" << ";";
			archivo << "\"" << Estudiante[i][1] << "\"" << ";";
			
			if(i < LIMITE - 1) {
				archivo << "\"" << Estudiante[i][pos] << "\"" << endl;
			} else {
				archivo << "\"" << Estudiante[i][pos] << "\"";
			}
		}
		archivo.close();
	}
  	if(pos == 12) {
		ofstream archivo("archivos/humanismo.csv");
		for(int i = 0; i < LIMITE; i++) {
			archivo << "\"" << Estudiante[i][0] << "\"" << ";";
			archivo << "\"" << Estudiante[i][1] << "\"" << ";";
			
			if(i < LIMITE - 1) {
				archivo << "\"" << Estudiante[i][pos] << "\"" << endl;
			} else {
				archivo << "\"" << Estudiante[i][pos] << "\"";
			}
		}
		archivo.close();
	}
  	if(pos == 13) {
		ofstream archivo("archivos/tecnicos.csv");
		for(int i = 0; i < LIMITE; i++) {
			archivo << "\"" << Estudiante[i][0] << "\"" << ";";
			archivo << "\"" << Estudiante[i][1] << "\"" << ";";
			
			if(i < LIMITE - 1) {
				archivo << "\"" << Estudiante[i][pos] << "\"" << endl;
			} else {
				archivo << "\"" << Estudiante[i][pos] << "\"";
			}
		}
		archivo.close();
	}
}

void limpiarArreglo() {
	for(int i = 0; i < LIMITE; i++) {
		for(int j = 0; j < 14; j++) {
			Estudiante[i][j] = Estudiante[length - i - 1][j];
		}
	}
	length = length - LIMITE;
}