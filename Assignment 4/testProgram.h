// Tommy Yasi/toya1800
// Created by Admin on 2019-06-09.
//

#ifndef OB_LABB4_TESTPROGRAM_H
#define OB_LABB4_TESTPROGRAM_H

#include <iostream>
#include "dataFilter.h"

class TestProgram {
private:
    // Värden
    bool notEndOfFile = true;
    double sum = 0, average = 0, value = 0;
    int nrOfValues = 0, outsideRange = 0;

    // Funktioner
    void runFile();
    void showResult();

public:
    void run();
};

#endif //OB_LABB4_TESTPROGRAM_H
