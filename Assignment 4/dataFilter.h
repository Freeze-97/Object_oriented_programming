// Tommy Yasi/toya1800
// Created by Admin on 2019-06-04.
//

#ifndef OB_LABB4_DATAFILTER_H
#define OB_LABB4_DATAFILTER_H

#include "dataFileReader.h"

template<typename T>
class DataFilter {
private:
    DataFileReader<T> *reader;
    T minRange;
    T maxRange;

public:
    DataFilter(DataFileReader<T> *aReader, T aMin, T aMax);
    ~DataFilter();
    bool getNextValue(T &aValue);
};

#endif //OB_LABB4_DATAFILTER_H
