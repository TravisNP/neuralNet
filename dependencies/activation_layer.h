#ifndef ACTIVATION_LAYER
#define ACTIVATION_LAYER

#include "layer.cpp"
#include "matrix_operations.h"
#include <algorithm>

class ActivationLayer : public Layer {
private:
    // The activation function
    double (*activation_func)(double);

    // The derivative of the activation function
    double (*activation_func_derivative)(double);

public:
    /**
     * Constructor for activation layer
     * @param _activation_func the activation function
     * @param _activation_func_derivatice the derivatice of the activation function
     */
    ActivationLayer(double (*_activation_func)(double), double(*_activation_func_derivative)(double));

    /**
     * Forward propagation function - takes in input and sets the ActivationLayer's input to _input and returns the output data
     * @param _input the input data
     * @return the output data, i.e. the activation function applied elementwise to _input
     */
    std::vector<double> forward_prop(const std::vector<double>& _input) override;

    /**
     * Backwards propagation function
     * @param outputError gradient of the error with respect to the output
     * @param learningRate the learning rate (unused)
     * @return the gradient of the error with respect to the input
     */
    std::vector<double> backward_prop(const std::vector<double>& outputError, const double learningRate = 0) override;
};

#endif