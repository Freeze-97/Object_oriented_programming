// Tommy Yasi/toya1800
// Created by Admin on 2019-06-03.
//

#ifndef OB_LABB4_DATAFILEREADER_H
#define OB_LABB4_DATAFILEREADER_H

#include<exception>
#include<stdexcept>
#include <string>
#include <fstream>

template<typename T>
class DataFileReader {
private:
    std::ofstream errorFile;
    std::ifstream dataFile;
    std::string dataFileName;
    std::string errorFileName;
public:
    DataFileReader(std::string &aDataFileName, std::string &aErrorFileName);
    ~DataFileReader();
    void openFiles();
    bool readNextValue(T &aValue);
};

#endif //OB_LABB4_DATAFILEREADER_H
