#ifndef FULLY_CONNECTED
#define FULLY_CONNECTED

#include <random>
#include <iostream>

#include "layer.h"
#include "matrix_operations.h"
#include "overload.h"

class FullyConnectedLayer : public Layer {
private:
    // The weights of the layer
    std::vector<std::vector<double>> weights;

    // the bias of the layer
    std::vector<double> bias;

public:
    /**
     * Constructor for Fully Connected Layer
     * @param _NUM_INPUT_NODES the number of input nodes
     * @param _NUM_OUTPUT_NODES the number of output nodes
     */
    FullyConnectedLayer(const int _NUM_INPUT_NODES, const int _NUM_OUTPUT_NODES);

    /**
     * Forward propagation function - takes in input and sets the FullyConnectedLayer's input to _input and returns the output data
     * @param _input the input data
     * @return the output data, i.e. cross product plus bias
     */
    std::vector<double> forward_prop(const std::vector<double>& _input) override;

    /**
     * Backwards propagation function
     * Calculates the gradient of the error with respect to the input, weights, and bias from the gradient of the error with respect to the output
     * Updates the weights and bias with the respective gradients
     * @param outputError gradient of the error with respect to the output
     * @param learningRate the learning rate
     * @return the gradient of the error with respect to the input
     */
    std::vector<double> backward_prop(const std::vector<double>& outputError, const double learningRate) override;

    // Prints the weights for each layer
    void printWeights();

    // Prints the bias for each layer
    void printBias();
};

#endif