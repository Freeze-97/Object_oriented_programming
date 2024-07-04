// Main-program
// Tommy yasi/toya1800
#include "menuTestProgram.h"


void run();

int main() {
    run();
    return 0;
}

template <typename T>
void run() {
    MenuTestProgram<T> program;
    program.run();
}