// Tommy Yasi/toya1800
// Created by Admin on 2019-06-09.
//
#include "dataFilter.h"

template<typename T>
DataFilter<T>::DataFilter(DataFileReader<T> *aReader, T aMin, T aMax) {
    reader = aReader;
    maxRange = aMax;
    minRange = aMin;
}

template<typename T>
DataFilter<T>::~DataFilter() = default; // Konstruktor

template<typename T>
bool DataFilter<T>::getNextValue(T &aValue) {
    bool canRead = reader->readNextValue(aValue);  // Läs nästa värde

    if(aValue > maxRange || aValue < minRange) { // Om värdet är för högt eller för lågt
        throw std::range_error(std::to_string(aValue));
    }
    return canRead;
}
