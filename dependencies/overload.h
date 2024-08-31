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

/**
 * Multiples a constant through a matrix, modifying the matrix
 * @param mult the constant
 * @param matrix the matrix
 * @return a reference to the multiplied matrix
 */
std::vector<std::vector<double>>& operator*(const double mult, std::vector<std::vector<double>>& matrix);

/**
 * Multiplies a constant through a vector, modifying the vector
 * @param mult the constant
 * @param vec the vector
 * @return a reference to the vmultiplied vector
 */
std::vector<double>& operator*(const double mult, std::vector<double>& vec);

/**
 * Subtracts two vectors, rhs from lhs, modifying lhs
 * @param lhs the vector being subtracted from and modified
 * @param rhs the vector being subtracted
 * @return a reference to lhs, which is now lhs - rhs
 */
std::vector<double>& operator-=(std::vector<double>& lhs, const std::vector<double>& rhs);

/**
 * Subtracts two matrices, rhs from lhs, modifying lhs
 * @param lhs the vector being subtracted from and modified
 * @param rhs the vector being subtracted
 * @return a reference to lhs, which is now lhs - rhs
 */
std::vector<double>& operator-=(std::vector<std::vector<double>>& lhs, const std::vector<std::vector<double>>& rhs);

#endif