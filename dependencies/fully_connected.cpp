#include "fully_connected.h"

FullyConnectedLayer::FullyConnectedLayer(const int _NUM_INPUT_NODES, const int _NUM_OUTPUT_NODES) :
    Layer(_NUM_INPUT_NODES, _NUM_OUTPUT_NODES),
    weights(std::vector<std::vector<double>>(NUM_INPUT_NODES, std::vector<double>(NUM_OUTPUT_NODES, -0.5))),
    bias(std::vector<double>(NUM_OUTPUT_NODES, -0.5))
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0, 1);

        for (int row = 0; row < NUM_INPUT_NODES; ++row)
            for (int col = 0; col < NUM_OUTPUT_NODES; ++col)
                weights[row][col] += dis(gen);

        for (int i = 0; i < NUM_OUTPUT_NODES; ++i)
            bias[i] += dis(gen);
    }

std::vector<double> FullyConnectedLayer::forward_prop(std::vector<double> _input) {
    input = _input;
    return cross_product(input, weights) + bias;
}

std::vector<double> FullyConnectedLayer::backward_prop(std::vector<double> output, const int learningRate) {
    return {};
}

void FullyConnectedLayer::printWeights() {
    for (int row = 0; row < weights.size(); ++row) {
        for (int col = 0; col < weights[0].size(); ++col)
            std::cout << weights[row][col] << " ";
        std::cout << std::endl;
    }
}

void FullyConnectedLayer::printBias() {
    for (int i = 0; i < bias.size(); ++i)
        std::cout << bias[i] << " ";
    std::cout << std::endl;
}