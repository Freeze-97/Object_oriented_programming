// Tommy Yasi/toya1800
// Created by Admin on 2019-06-19.
// TestProgram för STL

#ifndef OB_LABB5_TESTPROGRAM_H
#define OB_LABB5_TESTPROGRAM_H

#include <list>
#include <random>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <fstream>
#include <iostream>

template <typename T>
class ListManipulator {
private:
    std::list<T> *theList; // Listan
public:
    explicit ListManipulator(std::list<T> *aList);
    ~ListManipulator() = default;

    // Funktioner
    void fillList();
    T sumList() const;
    T listAverage() const;
    bool findFirst1500_1900(T &num) const;
    T between1500and1900tester();
    void divideByTwo();
    void swapPlaces();
    void findMinMan(T &min, T &max) const;
    void sortList();
    void clearLst();
    std::list<T> getList()const;
    void saveToFile() const;
    void readFromFile() const;

    void printList();
};

#endif //OB_LABB5_TESTPROGRAM_H
