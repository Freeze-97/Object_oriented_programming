// Tommy Yasi
// Created by Admin on 2019-06-09.
//
#include "testProgram.h"
using namespace std;

void TestProgram::run() {
    runFile();
    showResult();
}

void TestProgram::runFile() {
    string mainFile = "Values.dat", rangeErrorFile = "rangeError.dat", errorFile = "Error.dat";
    DataFileReader<double> read(mainFile, errorFile);
    DataFilter<double> filter(&read, 0.0, 10.0);
    ofstream rangeError(rangeErrorFile);

    read.openFiles();
    while(notEndOfFile) {
        try {
            notEndOfFile = (filter.getNextValue(value));
            if (notEndOfFile) {
                sum += value;
                nrOfValues++;
                average = sum / nrOfValues;
            }
        }
        catch (range_error &e) {
            outsideRange++;
            rangeError << e.what() << endl;
        }
    }
    rangeError.close();
}

void TestProgram::showResult() {
    cout << "Read values: " << nrOfValues << endl;
    cout << "Values outside of range: " << outsideRange << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}
