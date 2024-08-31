#ifndef FULLY_CONNECTED
#define FULLY_CONNECTED

#include <random>
#include <iostream>

#include "layer.cpp"
#include "matrix_operations.h"
#include "overload.h"

class FullyConnectedLayer : public Layer {
private:
    // The weights of the layer
    std::vector<std::vector<double>> weights;

    // the bias of the layer
    std::vector<double> bias;

public:
    FullyConnectedLayer(const int numInputs, const int numOutputs);

    /**
     * Forward propagation function - takes in input and sets the FullyConnectedLayer's input to _input and returns the output data
     * @param _input the input data
     * @return the output data, i.e. cross product plus bias
     */
    std::vector<double> forward_prop(std::vector<double> _input) override;

    /**
     * Backwards propagation function - TODO
     */
    std::vector<double> backward_prop(std::vector<double> output, const int learningRate) override;

    void printWeights();
    void printBias();
};

#endif