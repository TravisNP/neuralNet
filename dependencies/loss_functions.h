#ifndef LOSS_FUNCTIONS
#define LOSS_FUNCTIONS

#include <utility>
#include <vector>
#include <math.h>

#include "custom_exceptions.h"

typedef std::pair<double (*)(const std::vector<double>&, const std::vector<double>&), std::vector<double>(*)(const std::vector<double>&, const std::vector<double>&)> LossFunction;

extern LossFunction mean_squared_error;

#endif