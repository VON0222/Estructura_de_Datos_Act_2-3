// =================================================================
//
// File: selectionSort.h
// Author: José Diego Llaca Castro
// Date: 13/09/2022
// Description: This file contains the implementation of the
//				selection sort.
// =================================================================

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "header.h"
#include "ObjBarco.h"
#include <vector>

// =================================================================
// Performs the selection sort algorithm on an array.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================

template <class T>
int operatorSort(std::vector<T> &v){
    int pos;
    int count = 0;
    for (int i = v.size() - 1; i > 0; i--){
        pos = 0;
        for (int j = 1; j <= i; j++){
            if (v[pos] < v[j]){
                pos = j;
            }
        }
        if (pos != i){
            count++;
            swap(v, i, pos);
        }
    }
    return count;
}

// =================================================================
// Performs the selection sort algorithm on a vector.
//
// @param A, a vector of T elements.
// =================================================================

int selectionSort(std::vector<ObjBarco> &v){
    int pos;
    int count = 0;
    for (int i = v.size() - 1; i > 0; i--){
        pos = 0;
        for (int j = 1; j <= i; j++){
            if (v[pos].Comp(v[j])){
                pos = j;
            }
        }
        if (pos != i){
            count++;
            swap(v, i, pos);
        }
    }
    return count;
}

#endif