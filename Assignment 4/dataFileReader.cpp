// Tommy Yasi/toya1800
// Created by Admin on 2019-06-03.
//
#include "dataFileReader.h"
using namespace std;

template<typename T>
DataFileReader<T>::DataFileReader(string &aDataFileName,  string &aErrorFileName) {
    dataFileName = aDataFileName;
    errorFileName = aErrorFileName;
}

template<typename T>
DataFileReader<T>::~DataFileReader() = default;

template<typename T>
void DataFileReader<T>::openFiles() {
    errorFile.open(errorFileName); // Öppna errorfile
    if(!errorFile.is_open())
        throw runtime_error("could not open datafile");

    dataFile.open(dataFileName);
    if(!dataFile.is_open())
        throw runtime_error("could not open datafile");
}

template<typename T>
bool DataFileReader<T>::readNextValue(T &aValue) {
    ios_base::iostate mask = ios::eofbit | ios::failbit | ios::badbit;
    dataFile.exceptions(mask);

    try {
        dataFile >> aValue;
        return true;
    }
    catch (ios_base::failure &eo) {
        ios_base::iostate flags = dataFile.rdstate();

        if(flags & ios::eofbit) {
            dataFile.clear();
            return false;
        }
        else {
            string error;
            dataFile.clear();
            getline(dataFile, error);
            errorFile << error << endl;
        }
    }
}
