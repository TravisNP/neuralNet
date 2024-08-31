#include "overload.h"

std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs) {
    if (lhs.size() != rhs.size())
        throw CustomException("Cannot preform pairwise addition of two vectors as they have different sizes");

    std::vector<double> res(lhs.size(), 0);
    for (int i = 0; i < lhs.size(); ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}