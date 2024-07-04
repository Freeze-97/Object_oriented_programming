// queue.cpp
// Funktionsfil för testApp.cpp
// Tommy Yasi/toya1800
#include "testApp.h"
using namespace std;

TestApp::TestApp() = default;

void TestApp::run() {
    showMenu();
}
void TestApp::showMenu() {
    bool again = true;
    do {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "NOTE: Options 2-7 only available after queue is created!" << endl;
        cout << "1. Create Queue" << endl;
        cout << "2. Add element to queue" << endl;
        cout << "3. Deque queue" << endl;
        cout << "4. See if queue is empty" << endl;
        cout << "5. See if queue is full" << endl;
        cout << "6. See how many element there are" << endl;
        cout << "7. See maximum capacity of array" << endl;
        cout << "q. Quit" << endl;

        if(done) {
            switch (getMenuOption()) {
                case '1':
                    createQueue();
                    break;
                case '2':
                    enqueue();
                    break;
                case '3':
                    dequeue();
                    break;
                case '4':
                    isEmpty();
                    break;
                case '5':
                    isFull();
                    break;
                case '6':
                    nrElements();
                    break;
                case '7':
                    maxElements();
                    break;
                case 'q':
                    again = false;
                    break;
                default:
                    cout << "Invalid input" << endl;
            }
        }
        else {
            switch (getMenuOption()) {
                case '1': createQueue();
                    break;
                case 'q': again = false;
                    break;
                default: cout << "Invalid input" << endl;
            }
        }
    }while(again);
}
char TestApp::getMenuOption() {
    cout << "Choice: " << endl;
    char userChoice;
    cin >> userChoice;
    cin.get();
    return  userChoice;
}

void TestApp::createQueue() {
    cout << "Input max size: " << endl;
    int n;
    cin >> n;
    cin.get();
    intArr.reset(new Queue(n));
    cout << "The Queue has been created" << endl;
    done = true;
}
void TestApp::enqueue() {
    if(intArr->full()) {
        cout << "Queue is full" << endl;
        return;
    }
    cout << "Insert number to put in the queue: " << endl;
    int num;
    cin >> num;
    intArr->enqueue(num);
    cout << "Number has been added to the queue" << endl;
}
void TestApp::dequeue() {
    if(intArr->empty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Removing element: ";
    intArr->printElement(); // Funktion som skriver ut första elementet
    cout << endl;
    Type elem;
    intArr->dequeue(elem);
    cout << "First element has been removed in the queue" << endl;
}
void TestApp::isEmpty() const {
    if(intArr->empty()) {
        cout << "The list is empty" << endl;
    }
    else {
        cout << "The list is not empty" << endl;
    }
}
void TestApp::isFull() const {
    if(intArr->full()) {
        cout << "The list is full" << endl;
    }
    else {
        cout << "The list is not full" << endl;
    }
}
void TestApp::nrElements() const {
    cout << "Amount of elements in queue: " << intArr->length() << endl;
}
void TestApp::maxElements() const {
    cout << "Maximum capacity of array: " << intArr->capacity() << endl;
}



