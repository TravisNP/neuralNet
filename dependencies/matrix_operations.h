#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

#include <vector>

#include "custom_exceptions.h"

/**
 * Calculates the dot product of two vectors
 * @param vec1 the first vector
 * @param vec2 the second vector
 * @return their dot product
 */
double dot_product(const std::vector<double>& vec1, const std::vector<double>& vec2);

/**
 * Calculates the cross product of 1 x m and m x n matrices
 * @param vec the 1 x m vector
 * @param matrix the m x n matrix
 * @return their cross product
 */
std::vector<double> cross_product(const std::vector<double>& vec, const std::vector<std::vector<double>>& mat);

#endif