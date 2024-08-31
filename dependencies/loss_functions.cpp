#include "loss_functions.h"

double mean_squared_error_func(const std::vector<double>& predicted, const std::vector<double>& actual) {
    if (predicted.size() != actual.size())
        throw CustomException("Cannot find mean squared error as the predicted and actual result have a different size");

    double squaredError = 0;
    for (int i = 0; i < predicted.size(); ++i)
        squaredError += pow(predicted[i] - actual[i], 2);
    return squaredError / predicted.size();
}

std::vector<double> mean_squared_error_gradient_func(const std::vector<double>& predicted, const std::vector<double>& actual) {
    if (predicted.size() != actual.size())
        throw CustomException("Cannot find the gradient of the mean squared error as the predicted and actual result have a different size");

    std::vector<double> gradient(predicted.size(), 0);
    for (int i = 0; i < predicted.size(); ++i)
        gradient[i] = 2/predicted.size() * (predicted[i] - actual[i]);
    return gradient;
}

LossFunction mean_squared_error = std::make_pair(mean_squared_error_func, mean_squared_error_gradient_func);