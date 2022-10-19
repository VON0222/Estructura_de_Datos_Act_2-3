// =================================================================
//
// File: main.cpp
// Author: José Diego Llaca Castro
// Date: 18/10/2022
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

	//Se declara la lista de meses, acumuladores, contadores y listas para las entradas del mediterraneo y mar rojo.
	string meses[12]={"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	int acum_med = 0;
	int acum_red = 0;
	int boat_num = 0;
	int med_count = 0;
	int mednums[12]={};
	int red_count = 0; 
	int rednums[12]={};

	//Se declaran los vectores med y red para almacenar los IUB de los barcos de cada entrada
	vector<string> med;
	vector<string> red;

	//For loop para recorrer cada mes
	for(int i = 1; i <= 12; i++){
		med_count = 0;
		red_count = 0;
		//Comprobación para evitar un fallo en el loop
		if(boat_num > barcos.size()){
			break;
		}
		//While loop que almacena en med o red segun corresponda los IUB de los barcos si concuerda el prefijo
		while (barcos[boat_num].mes == i){
			if (barcos[boat_num].iub.substr(0, 3) == prefix)
				if (barcos[boat_num].entrada == 'M'){
					med.push_back(barcos[boat_num].iub);
					med_count++;
				}
				else {
					red.push_back(barcos[boat_num].iub);
					red_count++;
				}
				boat_num++;
		}
		//Se almacena en la lista el numero de barcos en cada entrada de acuerdo al mes
		mednums[i-1]=med_count;
		rednums[i-1]=red_count;
	}

	//For loop para recorrer todos los meses
	for (int i = 0; i < 12; i++){
		//Comprobación para determinar si mostrar o no un mes
		if (mednums[i] == 0 && rednums[i] == 0){
			continue;
		}
		else {
			//Se imprime el mes
			outputFile << meses[i] << endl;
			//Se imprimen los IUB de acuerdo al numero de barcos que entraron por mar mediterraneo
			if (mednums[i] != 0){
				outputFile << "M " << mednums[i] << ": ";
				for (int j = 0; j < mednums[i] ; j++){
					outputFile << med[acum_med] << " ";
					acum_med = acum_med + 1;
				}
				outputFile << endl;
			}
			//Se imprimen los IUB de acuerdo al numero de barcos que entraron por mar rojo
			if (rednums[i] != 0){
				outputFile << "R " << rednums[i] << ": ";
				for (int j = 0; j < rednums[i] ; j++){
					outputFile << red[acum_red] << " ";
					acum_red = acum_red + 1;
				}
				outputFile << endl;
			}
		}
	}

	//Cierra archivos
	inputFile.close();
	outputFile.close();
	return 0;
}