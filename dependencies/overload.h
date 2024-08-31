#ifndef OVERLOAD
#define OVERLOAD

#include <vector>
#include <algorithm>
#include <functional>

#include "custom_exceptions.h"

/**
 * Pairwise addition of two vectors
 * @param lhs the lefthand side
 * @param rhs the righthand size
 * @return the pairwise addition
 */
std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs);

#endif