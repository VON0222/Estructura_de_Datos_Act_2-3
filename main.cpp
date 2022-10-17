// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "ObjBarco.h"
#include "selectionSort.h"

using namespace std;

int main(int argc, char* argv[]){

	ifstream inputFile;			//Se abre el archivo
	ofstream outputFile;		//Se cierra el archivo

	//Leer el archivo
	if(argc != 3){
		cout << "usage: " << argv[0] << " input_file output_file" << endl;
		return -1;
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()){
		cout << argv[0] << ": File \"" << argv[1] << "\" not found" << endl;
		return -1;
	}

	outputFile.open(argv[2]);
	if (outputFile.fail()){
		cout << "No se pudo abrir archivo de salida" << endl;
		return -1;
	}

	//Declaración de variables a usar
	int n, minute, hour, day, month, year;
	string prefix, date, time, UBI;
	char entry;

	//Se recorre el archivo
	inputFile >> n >> prefix;			//Lee la primera linea para saber numero de registros y prefijo
	
	//Declaración de vectores que almacenan los registros de los barcos
	vector<ObjBarco>barcos(n);			//Donde se almacena los objetos barcos

	//Lee el archivo para llenar el vector
	for (int i = 0; i < n; i++){
		inputFile >> date >> time >> entry >> UBI;

		day = (date[0]-'0')*10 + (date[1]-'0');
		month = (date[3]-'0')*10 + (date[4]-'0');
		year = (date[6]-'0')*10 + (date[7]-'0');

		hour = (time[0]-'0')*10 + (time[1]-'0');
		minute = (time[3]-'0')*10 + (time[4]-'0');

		barcos[i] = ObjBarco(minute, hour, day, month, year, entry, UBI);
	}

	//Se aplica algoritmo de ordenamiento selectionSort
	selectionSort(barcos);

	//Despliega en archivo y guarda los datos en formato y orden que encajen con el prefijo.
	for (int i = 0; i < n; i++){
		if (barcos[i].iub.substr(0, 3) == prefix){
			outputFile << setfill('0');
			outputFile << setw(2) << barcos[i].dia << "-";
			outputFile << setw(2) << barcos[i].mes << "-";
			outputFile << setw(2) << barcos[i].yr << " ";
			outputFile << setw(2) << barcos[i].hr << ":";
			outputFile << setw(2) << barcos[i].min << " ";
			outputFile << barcos[i].entrada << " " << barcos[i].iub << endl;
		}
	}

	//Cierra archivos
	inputFile.close();
	outputFile.close();
	return 0;
}