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
        gradient[i] = 2.0/predicted.size() * (predicted[i] - actual[i]);
    return gradient;
}

LossFunction mean_squared_error = LossFunction(mean_squared_error_func, mean_squared_error_gradient_func, "MSE");


std::vector<double> soft_max_func(const std::vector<double>& vec) {
    double maxElem = *std::max_element(vec.begin(), vec.end());

    double sum = 0;
    std::vector<double> softMax(vec.size(), 0);
    for (int i = 0; i < vec.size(); ++i) {
        softMax[i] = exp(vec[i] - maxElem);
        sum += softMax[i];
    }

    for (int i = 0; i < vec.size(); ++i)
        softMax[i] /= sum;

    return softMax;
}

double softMax_error_onehot_func(const std::vector<double>& predicted, const std::vector<double>& actual) {
    std::vector<double> softMaxPredicted = soft_max_func(predicted);

    for (int i = 0; i < predicted.size(); ++i) {
        if (actual[i] == 1) {
            int loss = -1 * log(softMaxPredicted[i]);
            return loss;
        }
    }

    throw CustomException("Cannot preform softMax loss on a one-hot encoded vector as there is no 1 in the vector");
}

std::vector<double> softMax_error_gradient_func(const std::vector<double>& predicted, const std::vector<double>& actual) {
    return soft_max_func(predicted) - actual;
}

extern LossFunction softMax_onehot_error = LossFunction(softMax_error_onehot_func, softMax_error_gradient_func, "SoftMax Loss");