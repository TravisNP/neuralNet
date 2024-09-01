#ifndef DATA
#define DATA

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

#include "custom_exceptions.h"

struct IrisData {
    std::vector<std::vector<double>> trainingData;
    std::vector<std::vector<double>> trainingLabels;
    std::vector<std::vector<double>> testData;
    std::vector<std::vector<double>> testLabels;
};

IrisData readIrisData(const std::string filename, const int trainingPercent);

#endif