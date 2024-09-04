#ifndef LOSS_FUNCTIONS
#define LOSS_FUNCTIONS

#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "custom_exceptions.h"
#include "overload.h"

struct LossFunction {
    double (*activationFunction)(const std::vector<double>&, const std::vector<double>&);
    std::vector<double>(*activationFunctionDerivative)(const std::vector<double>&, const std::vector<double>&);
    std::string name;
};

extern LossFunction mean_squared_error;

extern LossFunction softMax_onehot_error;

#endif