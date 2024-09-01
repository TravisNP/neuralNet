#include "data.h"

IrisData readIrisData(const std::string filename, const int trainingPercent) {
    IrisData irisData;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw CustomException("Cannot open file: " + filename);
    }

    std::vector<std::vector<double>> allData;
    std::vector<std::vector<double>> allLabels;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::vector<double> features;
        std::string value;

        // Read the first 4 values (features)
        for (int i = 0; i < 4; ++i) {
            std::getline(stream, value, ',');
            features.push_back(std::stod(value));
        }

        // Read the label (Iris type)
        std::getline(stream, value, ',');
        std::vector<double> label(3, 0.0);  // Initialize the label vector with 3 elements (all 0)

        if (value == "Iris-setosa")
            label[0] = 1.0;
        else if (value == "Iris-versicolor")
            label[1] = 1.0;
        else if (value == "Iris-virginica")
            label[2] = 1.0;
        else
            throw CustomException("Error when reading in Iris data: label not one of three required strings");

        allData.push_back(features);
        allLabels.push_back(label);
    }

    file.close();

    int numTraining = int((trainingPercent / 100.0) * allData.size());

    for (int i = 0; i < allData.size(); ++i) {
        if (i < numTraining) {
            irisData.trainingData.push_back(allData[i]);
            irisData.trainingLabels.push_back(allLabels[i]);
        } else {
            irisData.testData.push_back(allData[i]);
            irisData.testLabels.push_back(allLabels[i]);
        }
    }

    return irisData;
}
