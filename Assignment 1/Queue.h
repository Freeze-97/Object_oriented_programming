// queue.h
// Header för queue
// Tommy Yasi/toya1800

#ifndef OB_LABB1_QUEUE_H
#define OB_LABB1_QUEUE_H
#include <memory>
#include <iostream>

typedef int Type; // Make Type an alias for int
const int QSIZE = 10; // Default Queue size
class Queue {
private:
    std::unique_ptr<Type[]> intArr; // Smart pointer
    int head; // index in array for head
    int tail; // index in array for tail
    int nElem; // nr of items in queue
    int maxElem; // max capacity of queue
public:
    explicit Queue(int n = QSIZE); // n = Max kapacitet
    void enqueue (Type elem);
    void dequeue(Type &elem);
    int length() const; // Antal element
    bool full() const; // Om den är full
    bool empty() const; // Om den är tom
    int capacity() const; // Maximal antal element
    void printElement() const;
};

#endif //OB_LABB1_QUEUE_H
