#include "overload.h"

std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs) {
    if (lhs.size() != rhs.size())
        throw CustomException("Cannot preform pairwise addition (+) of two vectors as they have different sizes");

    std::vector<double> res(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}

std::vector<double>& operator*(const double mult, std::vector<double>& vec) {
    for (int i = 0; i < vec.size(); ++i)
        vec[i] *= mult;
    return vec;
}

std::vector<std::vector<double>>& operator*(const double mult,  std::vector<std::vector<double>>& matrix) {
    for (int row = 0; row < matrix.size(); ++row)
        mult * matrix[row];
    return matrix;
}

std::vector<double>& operator-=(std::vector<double>& lhs, const std::vector<double>& rhs) {
    if (lhs.size() != rhs.size())
        throw CustomException("Cannot preform pairwise subtraction (-=) of two vectors as they have different sizes");

    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] -= rhs[i];
    return lhs;
}

std::vector<double>& operator-=(std::vector<std::vector<double>>& lhs, const std::vector<std::vector<double>>& rhs) {
    if (lhs.size() != rhs.size())
        throw CustomException("Cannot preform pairwise subtraction (-=) of two matrices as they have a different number of rows");
    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i].size() != rhs[i].size())
            throw CustomException("Cannot preform pairwise subtraction (-=) of two matrices as one of their rows have a different number of columns");
        lhs[i] -= rhs[i];
    }
}