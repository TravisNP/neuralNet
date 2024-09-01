#ifndef ACTIVATION_FUNCTIONS
#define ACTIVATION_FUNCTIONS

#include <utility>
#include <algorithm>
#include <math.h>

// Activation function, it's derivative, and name
struct ActivationFunction {
    // activation function
    double (*activationFunction)(double);

    // derivative of the activation function
    double(*activationFunctionDerivative)(double);

    // name of the activation function
    std::string name;
};

// Relu activation function
extern ActivationFunction RELU;

// Hyperbolic tangent activation function
extern ActivationFunction TANH;

#endif