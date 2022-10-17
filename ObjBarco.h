// =================================================================
//
// File: main.cpp
// Author: José Diego Llaca Castro
// Date: 13/09/2022
//
// =================================================================

#ifndef OBJBARCO_H
#define OBJBARCO_H

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Se declara la clase ObjBarco en la cual se van a extraer 
// y procesar todos los registros de los barcos

class ObjBarco{         
	public:
		int dia, mes, yr, hr, min;
		char entrada;
        string iub;
		ObjBarco(int, int, int, int, int, char, string);
        ObjBarco();
		bool Comp(const ObjBarco&);
};

// Constructor

ObjBarco::ObjBarco(int mi, int h, int d, int m, int a, char entr, string code){
	min = mi;
	hr = h;
	dia = d;
	mes = m;
	yr = a;
	entrada = entr;
	iub = code;
}

// Constructor por default

ObjBarco::ObjBarco(){
	min = 0;
	hr = 0;
	dia = 0;
	mes = 0;
	yr = 0;
	entrada = 'a';
	iub = " ";
}

//Comparador de fecha

bool ObjBarco::Comp(const ObjBarco& right){
    if (yr != right.yr){
        return yr < right.yr;
    }
    else{
        if (mes != right.mes){
            return mes < right.mes;
        }
        else{
            if (dia != right.dia){
                return dia < right.dia;
            }
            else{
                if (hr != right.hr){
                    return hr < right.hr;
                }
                else{
                    if (min != right.min){
                        return min < right.min;
                    }
                }
            }
        }
    }
    return false;
}

#endif