#include <iostream>

#include "dependencies/fully_connected.h"

int main() {
    FullyConnectedLayer fc(5,5);
    fc.printWeights();
    fc.printBias();
}