#include <iostream>

#include "dependencies/fully_connected_layer.h"
#include "dependencies/activation_layer.h"
#include "dependencies/activation_functions.h"
#include "dependencies/loss_functions.h"
#include "dependencies/neural_net.h"

int main() {
    FullyConnectedLayer* fullyConnectedLayer = new FullyConnectedLayer(5, 5);

    ActivationLayer* activationLayer = new ActivationLayer(RELU);

    fullyConnectedLayer->printWeights();

    NeuralNet myNet(mean_squared_error, {fullyConnectedLayer, activationLayer});
    std::vector<std::string> info = myNet.get_info();
    for (std::string str : info)
        std::cout << str << std::endl;
    return 0;
}