// testApp.h
// Header för testApp, testa Queue koden
// Tommy Yasi/toya1800

#ifndef OB_LABB1_TESTAPP_H
#define OB_LABB1_TESTAPP_H

#include "Queue.h"

class TestApp {
private:
    std::unique_ptr<Queue> intArr; // SMart pointer
    bool done = false; // Om Queue har skapats
// Main menu
    void showMenu();
    char getMenuOption();
// Menu-alternativ
    void createQueue(); // Skapar en kö av önskad längd
    void enqueue(); // Frågar efter tal
    void dequeue(); // deleting integer, printing out
    void isEmpty() const;
    void isFull() const;
    void nrElements() const;
    void maxElements() const;
public:
    TestApp();
    void run();
};

#endif //OB_LABB1_TESTAPP_H
