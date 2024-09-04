#include <iostream>

#include "dependencies/fully_connected_layer.h"
#include "dependencies/activation_layer.h"
#include "dependencies/activation_functions.h"
#include "dependencies/loss_functions.h"
#include "dependencies/neural_net.h"
#include "dependencies/data.h"

// Number of epochs to train for
#define NUM_EPOCS 10

// Print the training error every X epcochs
#define PRINT_ERROR_EVERY_X_EPOCHS 1

// Constant learning rate
#define CONSTANT_LEARNING_RATE .1

int main() {
    try {
        // Testing on XOR with tanh as activation function and MSE as loss function
        FullyConnectedLayer* fc1 = new FullyConnectedLayer(4, 1000);
        ActivationLayer* a1 = new ActivationLayer(RELU);
        FullyConnectedLayer* fc2 = new FullyConnectedLayer(1000, 500);
        ActivationLayer* a2 = new ActivationLayer(RELU);
        FullyConnectedLayer* fc3 = new FullyConnectedLayer(500, 300);
        ActivationLayer* a3 = new ActivationLayer(RELU);
        FullyConnectedLayer* fc4 = new FullyConnectedLayer(300, 3);
        ActivationLayer* a4 = new ActivationLayer(RELU);

        // Create the neural network and print out info about it's layers
        NeuralNet myNet(softMax_onehot_error, PRINT_ERROR_EVERY_X_EPOCHS,
            {fc1, a1, fc2, a2, fc3, a3, fc4, a4});
        for (std::string str : myNet.get_info())
            std::cout << str << std::endl;

        IrisData irisData = readIrisData("data/iris.data", 80);

        // Train the network
        myNet.train(irisData.trainingData, irisData.trainingLabels, NUM_EPOCS, CONSTANT_LEARNING_RATE);

        // Predict the labels for the training dataset
        std::vector<std::vector<double>> predictedLabels = myNet.predict(irisData.testData);

        // Calculate the overall softmax loss
        double SFLoss = 0;
        for (int i = 0; i < irisData.testLabels.size(); ++i)
            SFLoss += softMax_onehot_error.activationFunction(predictedLabels[i], irisData.testLabels[i]);
        std::cout << "SoftMax loss on test dataset: " << SFLoss << std::endl;

    } catch (CustomException& e) {
        std::cout << "Error - " << e.getMessage() << std::endl;
        return -1;
    }

    return 0;
}