#include <iostream>

#include "dependencies/fully_connected_layer.h"
#include "dependencies/activation_layer.h"
#include "dependencies/activation_functions.h"
#include "dependencies/loss_functions.h"
#include "dependencies/neural_net.h"

int main() {
    try {
        FullyConnectedLayer* fullyConnectedLayer1 = new FullyConnectedLayer(2, 3);
        ActivationLayer* activationLayer1 = new ActivationLayer(TANH);
        FullyConnectedLayer* fullyConnectedLayer2 = new FullyConnectedLayer(3, 1);
        ActivationLayer* activationLayer2 = new ActivationLayer(TANH);

        NeuralNet myNet(mean_squared_error, 1, {fullyConnectedLayer1, activationLayer1, fullyConnectedLayer2, activationLayer2});
        for (std::string str : myNet.get_info())
            std::cout << str << std::endl;

        std::vector<std::vector<double>> data = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        std::vector<std::vector<double>> labels = {{0}, {1}, {1}, {0}};
        myNet.train(data, labels, 10, .1);

    } catch (CustomException& e) {
        std::cout << "Error - " << e.getMessage() << std::endl;
        return -1;
    }

    return 0;
}