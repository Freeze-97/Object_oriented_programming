// queue.cpp
// Funktionsfil för queue.cpp
// Tommy Yasi/toya1800
#include "Queue.h"

Queue::Queue(int n) {
    intArr.reset(new Type[n]);
    head = 0;
    tail = 0;
    nElem = 0;
    maxElem = n;
}
void Queue::enqueue (Type elem) {
    intArr[tail] = elem;
    nElem++;
    tail = (tail + 1) % maxElem; // Cirkulär
}
void Queue::dequeue(Type &elem) {
    intArr[head] = elem;
    nElem--;
    head = (head + 1) % maxElem; // Ciruklär
}
int Queue::length() const {
    return nElem;
}
bool Queue::full() const {
    return nElem == maxElem;
}
bool Queue::empty() const {
    return nElem == 0;
}
int Queue::capacity() const {
    return maxElem;
}
void Queue::printElement() const {
    std::cout << intArr[head];
}

