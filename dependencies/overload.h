#ifndef OVERLOAD
#define OVERLOAD

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

#include "custom_exceptions.h"

/**
 * Pairwise addition of two vectors
 * @param lhs the lefthand side
 * @param rhs the righthand size
 * @return the pairwise addition
 */
std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs);

/**
 * Multiplies a constant through a vector
 * @param mult the constant
 * @param vec the vector
 * @return the new vector with each element multiplied by the constant
 */
std::vector<double> operator*(const std::vector<double>& vec, const double mult);

/**
 * Multiplies a constant through a vector, modifying the vector
 * @param mult the constant
 * @param vec the vector
 * @return a reference to the vmultiplied vector
 */
std::vector<double>& operator*(const double mult, std::vector<double>& vec);

/**
 * Multiples a constant through a matrix, modifying the matrix
 * @param mult the constant
 * @param matrix the matrix
 * @return a reference to the multiplied matrix
 */
std::vector<std::vector<double>>& operator*(const double mult, std::vector<std::vector<double>>& matrix);

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

/**
 * Subtracts two vectors, rhs from lhs, and returns the rest
 * @param lhs the vector being subtracted from
 * @param rhs the vector being subtracted
 * @return their subtraction
 */
std::vector<double> operator-(const std::vector<double>& lhs, const std::vector<double>& rhs);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<double>>& mat);

#endif