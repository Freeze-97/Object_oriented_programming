// Tommy Yasi/toya1800
// Created by Admin on 2019-06-19.
// Funktionsdefinition för klassen ListManipulator
#include "testProgram.h"
using namespace std::placeholders; // För transform

template<typename T>
ListManipulator<T>::ListManipulator(std::list<T> *aList) {
    theList = aList;
}

template<typename T>
void ListManipulator<T>::fillList() {
    std::uniform_real_distribution<double> random(1000, 2000); // Min och Max
    std::default_random_engine generator(static_cast<unsigned>(std::time(nullptr))); // Random generator

    std::generate(theList->begin(), theList->end(), random); // Ger listan random nummer
}

template<typename T>
T ListManipulator<T>::sumList() const {
    T sum = std::accumulate(theList->begin(), theList->end(), T(0)); // räkna ut summan
    return sum;
}

template<typename T>
T ListManipulator<T>::listAverage() const {
    typename T::iterator start = theList->begin(), end = theList->end();
    T average = std::accumulate(start, end, T(0)) / theList->size();
    return average;
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const {
    auto it = std::find_if(theList->begin(), theList->end(), between1500and1900tester());
    if(it != theList->end()){
        num = *it;
        return true;
    } else return false;
}

template<typename T>
T ListManipulator<T>::between1500and1900tester() {
    for (auto e: theList) {
        if (e >= 1500 && e <= 1900) {
            return e;
        }
    }
    return false;
}

template<typename T>
void ListManipulator<T>::divideByTwo() {
    std::transform(theList->begin(), theList->end(), theList->begin(), std::bind(std::divides<T>(),_1,2));
}

template<typename T>
void ListManipulator<T>::swapPlaces() {

    auto fIt = theList->begin();
    auto bIt = theList->end();
    for (size_t i = 0; i < theList->size() / 2; i++) {
        std::iter_swap(theList->begin(), theList->end());
        fIt++; bIt--;
    }
}

template<typename T>
void ListManipulator<T>::findMinMan(T &min, T &max) const {
    min = *std::min_element(theList->begin(), theList->end());
    max = *std::max_element(theList->begin(), theList->end());
}

template<typename T>
void ListManipulator<T>::sortList() {
    theList->sort();
}

template<typename T>
void ListManipulator<T>::clearLst() {
    theList->clear();
}

template<typename T>
std::list<T> ListManipulator<T>::getList() const {
    return theList;
}

template<typename T>
void ListManipulator<T>::saveToFile() const {
    std::ofstream ofFile("list.dat");
    std::ostream_iterator<T> iit(ofFile, std::endl);
    copy(theList->begin(), theList->end(), iit);
}

template<typename T>
void ListManipulator<T>::readFromFile() const {
    std::ifstream inFile("list.dat");
    std::istream_iterator<T> eos;
    std::istream_iterator<T> iit(inFile);
    std::copy(iit, eos, std::back_inserter(*theList));
}

template<typename T>
void ListManipulator<T>::printList() {
    for(auto e : theList){
        std::cout << e << std::endl;
    }
}
