#include "activation_functions.h"

double RELU_func(const double val) {
    return std::max(val, 0.0);
}

double RELU_derivative_func(const double val) {
    return val <= 0 ? 0 : 1;
}

ActivationFunction RELU = std::make_pair(RELU_func, RELU_derivative_func);


double tanh_func(const double val) {
    return tanh(val);
}

double tanh_derivative_func(const double val) {
    return 1 - pow(tanh(val), 2);
}

ActivationFunction TANH = std::make_pair(tanh_func, tanh_derivative_func);