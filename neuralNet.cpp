#include <iostream>

#include "dependencies/fully_connected_layer.h"
#include "dependencies/activation_layer.h"
#include "dependencies/activation_functions.h"

int main() {
    FullyConnectedLayer fullyConnectedLayer(5,5);

    ActivationLayer activationLayer(RELU);

    fullyConnectedLayer.printWeights();
}