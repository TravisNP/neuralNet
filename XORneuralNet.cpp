#include <iostream>

#include "dependencies/fully_connected_layer.h"
#include "dependencies/activation_layer.h"
#include "dependencies/activation_functions.h"
#include "dependencies/loss_functions.h"
#include "dependencies/neural_net.h"

// Number of epochs to train for
#define NUM_EPOCS 1000

// Print the training error every X epcochs
#define PRINT_ERROR_EVERY_X_EPOCHS 100

// Constant learning rate
#define CONSTANT_LEARNING_RATE .1

int main() {
    try {
        // Testing on XOR with tanh as activation function and MSE as loss function
        FullyConnectedLayer* fullyConnectedLayer1 = new FullyConnectedLayer(2, 3);
        ActivationLayer* activationLayer1 = new ActivationLayer(TANH);
        FullyConnectedLayer* fullyConnectedLayer2 = new FullyConnectedLayer(3, 1);
        ActivationLayer* activationLayer2 = new ActivationLayer(TANH);

        // Create the neural network and print out info about it's layers
        NeuralNet myNet(mean_squared_error, PRINT_ERROR_EVERY_X_EPOCHS, {fullyConnectedLayer1, activationLayer1, fullyConnectedLayer2, activationLayer2});
        for (std::string str : myNet.get_info())
            std::cout << str << std::endl;

        // XOR dataset and labels
        std::vector<std::vector<double>> data = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        std::vector<std::vector<double>> labels = {{0}, {1}, {1}, {0}};

        // Train the network
        myNet.train(data, labels, NUM_EPOCS, CONSTANT_LEARNING_RATE);

        // Predict the labels for the training dataset
        std::vector<std::vector<double>> predictedLabels = myNet.predict(data);

        // Calculate the overall MSE
        double MSE = 0;
        for (int i = 0; i < labels.size(); ++i)
            MSE += mean_squared_error.activationFunction(predictedLabels[i], labels[i]);
        std::cout << "Error on training dataset: " << MSE << std::endl;

    } catch (CustomException& e) {
        std::cout << "Error - " << e.getMessage() << std::endl;
        return -1;
    }

    return 0;
}