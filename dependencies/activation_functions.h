#ifndef ACTIVATION_FUNCTIONS
#define ACTIVATION_FUNCTIONS

#include <utility>
#include <algorithm>
#include <math.h>

// Activation function and it's derivative
typedef std::pair<double (*)(double), double(*)(double)> ActivationFunction;

// Relu activation function
extern ActivationFunction RELU;

// Hyperbolic tangent activation function
extern ActivationFunction TANH;

#endif