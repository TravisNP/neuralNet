#include "fully_connected_layer.h"

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

        // for (int row = 0; row < NUM_INPUT_NODES; ++row)
        //     for (int col = 0; col < NUM_OUTPUT_NODES; ++col)
        //         weights[row][col] = 0;

        // for (int i = 0; i < NUM_OUTPUT_NODES; ++i)
        //     bias[i] = 0;
    }

std::vector<double> FullyConnectedLayer::forward_prop(const std::vector<double>& _input) {
    input = _input;
    return cross_product(input, weights) + bias;
}

std::vector<double> FullyConnectedLayer::backward_prop(const std::vector<double>& outputError, const double learningRate) {
    // Use derror over dweights and derror over dbias (outputError) to update weights and bias with gradient descent
    // TODO: Figure out why I need this extra variable
    std::vector<std::vector<double>> derror_over_dweights = cross_product(input, outputError);
    weights -= learningRate * derror_over_dweights;
    bias -= outputError * learningRate;

    // Return derror over dx
    return cross_product(weights, outputError);
}

std::string FullyConnectedLayer::get_info() {
    return "FullyConnected - I: " + std::to_string(NUM_INPUT_NODES) + ", O: " + std::to_string(NUM_OUTPUT_NODES);
}

std::pair<std::vector<std::vector<double>>, std::vector<double>> FullyConnectedLayer::get_weights_bias() {
    return std::make_pair(weights, bias);
}

void FullyConnectedLayer::set_weights(const std::vector<std::vector<double>>& _weights) {
    weights = _weights;
}

void FullyConnectedLayer::set_bias(const std::vector<double>& _bias) {
    bias = _bias;
}