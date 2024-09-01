#include "matrix_operations.h"

double dot_product(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    if (vec1.size() != vec2.size())
        throw CustomException("Cannot take the dot product between two vectors as their sizes are not the same");

    double dotProduct = 0;
    for (int i = 0; i < vec1.size(); ++i)
        dotProduct += vec1[i] * vec2[i];

    return dotProduct;
}

std::vector<double> cross_product(const std::vector<double>& vec, const std::vector<std::vector<double>>& mat) {
    if (vec.size() != mat.size())
        throw CustomException("Cannot take the cross product between the vector and matrix as their sizes are not the same");

    std::vector<double> crossProduct(mat[0].size(), 0);
    for (int col = 0; col < mat.size(); ++col)
        for (int row = 0; row < vec.size(); ++row)
            crossProduct[col] += vec[row] * mat[col][row];

    return crossProduct;
}

std::vector<double> cross_product(const std::vector<std::vector<double>>& mat, const std::vector<double>& vec) {
    if (mat[0].size() != vec.size())
        throw CustomException("Cannot take the cross product between the matrix and vector as their sizes are not the same");

    std::vector<double> crossProduct(mat.size(), 0);
    for (int row = 0; row < mat.size(); ++row)
        for (int col = 0; col < mat[0].size(); ++col)
            crossProduct[row] += mat[row][col] * vec[col];

    return crossProduct;
}

std::vector<std::vector<double>> cross_product(const std::vector<double>& lhs, const std::vector<double>& rhs) {
    std::vector<std::vector<double>> crossProduct(lhs.size(), std::vector<double>(rhs.size(), 0));
    for (int row = 0; row < lhs.size(); ++row)
        for (int col = 0; col < lhs.size(); ++col)
            crossProduct[row][col] = lhs[row] * rhs[col];

    return crossProduct;
}

std::vector<double> hadamard_product(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    if (vec1.size() != vec2.size())
        throw CustomException("Cannot take the hadamard product between the two vectors as their sizes are not the same");

    std::vector<double> hadamardProduct(vec1.size(), 0);
    for (int i = 0; i < vec1.size(); ++i)
        hadamardProduct[i] = vec1[i] * vec2[i];
    return hadamardProduct;
}