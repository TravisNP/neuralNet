#ifndef ACTIVATION_LAYER
#define ACTIVATION_LAYER

#include "layer.h"
#include "matrix_operations.h"
#include "activation_functions.h"

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
     * @param activationFuncPair the activation function and it's derivative
     */
    ActivationLayer(ActivationFunction activationFuncPair);

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