#ifndef LOSS_FUNCTIONS
#define LOSS_FUNCTIONS

#include <utility>
#include <vector>
#include <math.h>

#include "custom_exceptions.h"

struct LossFunction {
    double (*activationFunction)(const std::vector<double>&, const std::vector<double>&);
    std::vector<double>(*activationFunctionDerivative)(const std::vector<double>&, const std::vector<double>&);
    std::string name;
};

extern LossFunction mean_squared_error;

#endif