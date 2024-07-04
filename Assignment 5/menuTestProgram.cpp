// Tommy Yasi/toya1800
// Created by Admin on 2019-06-21.
//
#include "menuTestProgram.h"
using namespace std;

template<typename T>
void MenuTestProgram<T>::run() {
    menu1(); // Visa första menyn

    // Välj int eller double, för att sedan skicka vidare listan till myMainFunc
    int choice;
    cin >> choice;
    cin.get();
    switch(choice) {
        case 1: {
            list<int> intList;
            myMainFunc(intList);
        }
            break;
        case 2: {
            list<double> intList;
            myMainFunc(intList);
            break;
        }
        default: cout << "Invalid input!" << endl;
    }
}


template<typename T>
void MenuTestProgram<T>::myMainFunc(list<T> &theList) {
    ListManipulator<T> mainList(theList); // Skapa listan

    // Välj vad du vill göra med listan
    menu2();
    int choice;
    cin >> choice;
    cin.get();

    bool again = true;
    do {
        switch(choice){
            case 1: mainList.fillList();
            cout << "The list has been filled" << endl;
                break;
            case 2: cout << "The sum is: " << mainList.sumList() << endl;
                break;
            case 3: cout << "Average number: " << mainList.listAverage();
                break;
            case 4:
                if(!mainList.findFirst1500_1900(num)) {
                    cout << "No number between 1500 to 1900 in the list." << endl;
                } else {
                    cout << "First number between 1500 to 1900: " << num << endl;
                }
                break;
            case 5: mainList.divideByTwo();
            cout << "The numbers has been divided by 2." << endl;
                break;
            case 6: mainList.swapPlaces();
            cout << "The places has been swapped." << endl;
                break;
            case 7: mainList.findMinMan(minNum, maxNum);
            cout << "The smallest number: " << minNum << endl;
            cout << "The largest number: " << maxNum << endl;
                break;
            case 8: mainList.sortList();
            cout << "The list has been sorted." << endl;
                break;
            case 9: mainList.clearLst();
            cout << "The list has been cleared." << endl;
                break;
            case 10: mainList.saveToFile();
            cout << "List has been saved to file." << endl;
                break;
            case 11: mainList.readFromFile();
            cout << "List has been read from file." << endl;
                break;
            case 12: mainList.printList();
            cout << endl; // Extra tom rad
                break;
            case 13: again = false;
                break;
            default: cout << "Invalid input!" << endl;
        }

    }while (again);


}

template<typename T>
void MenuTestProgram<T>::menu1() {
    cout << "Choose type of list." << endl;
    cout << "1. Int." << endl;
    cout << "2. Double." << endl;
}

template<typename T>
void MenuTestProgram<T>::menu2() {
    cout << "----MENU---" << endl;
    cout << "1. Fill list with random numbers." << endl;
    cout << "2. Summerize the values in the list." << endl;
    cout << "3. Average of numbers." << endl;
    cout << "4. Find first number between 1500 and 1900." << endl;
    cout << "5. Divide by two." << endl;
    cout << "6. Swap places." << endl;
    cout << "7.Find largest and smallest number." << endl;
    cout << "8. Sort." << endl;
    cout << "9 Clear list." << endl;
    cout << "10. Write to file." << endl;
    cout << "11. Read from file." << endl;
    cout << "11. Print numbers." << endl;
    cout << "13. Quit." << endl;
}