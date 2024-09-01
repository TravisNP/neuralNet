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

        std::vector<std::vector<double>> weights1 = {{-0.05711129,  0.47784239, -0.22229421},{0.08692471, 0.43129866, -0.24575793}};
        fullyConnectedLayer1->set_weights(weights1);
        std::vector<double> bias1 = {0.154379, -0.16848041, 0.32867986};
        fullyConnectedLayer1->set_bias(bias1);

        std::vector<std::vector<double>> weights2 = {{0.0658615}, {0.24389044}, {-0.22121158}};
        fullyConnectedLayer2->set_weights(weights2);
        std::vector<double> bias2 = {0.21992502};
        fullyConnectedLayer2->set_bias(bias2);

        std::cout << fullyConnectedLayer1->get_weights_bias().first << std::endl << fullyConnectedLayer1->get_weights_bias().second << std::endl;
        std::cout << std::endl;
        std::cout << fullyConnectedLayer2->get_weights_bias().first << std::endl << fullyConnectedLayer2->get_weights_bias().second << std::endl;
        std::cout << "#############################################" << std::endl;

        NeuralNet myNet(mean_squared_error, 1, {fullyConnectedLayer1, activationLayer1, fullyConnectedLayer2, activationLayer2});
        // for (std::string str : myNet.get_info())
        //     std::cout << str << std::endl;

        std::vector<std::vector<double>> data = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        std::vector<std::vector<double>> labels = {{0}, {1}, {1}, {0}};

        myNet.train(data, labels, 1, .1);

    } catch (CustomException& e) {
        std::cout << "Error - " << e.getMessage() << std::endl;
        return -1;
    }

    return 0;
}