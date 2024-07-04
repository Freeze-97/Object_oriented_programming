// Tommy Yasi/toya1800
// Created by Admin on 2019-06-21.
//

#ifndef OB_LABB5_MENUTESTPROGRAM_H
#define OB_LABB5_MENUTESTPROGRAM_H

#include "testProgram.h"

template <typename T>
class MenuTestProgram{
private:
    T num = 0, maxNum = 0, minNum = 0;

    void menu1(); // Endast text
    void menu2(); // Endast text
    void myMainFunc(std::list<T> &theList); // Välj double eller int
public:
    void run();
};

#endif //OB_LABB5_MENUTESTPROGRAM_H
