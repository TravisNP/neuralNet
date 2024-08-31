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

    std::vector<double> crossProduct(vec.size(), 0);
    for (int i = 0; i < vec.size(); ++i)
        crossProduct[i] = dot_product(vec, mat[i]);

    return crossProduct;
}