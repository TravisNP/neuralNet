#include "neural_net.h"

NeuralNet::NeuralNet(const LossFunction& _lossFunction, const int _printLossEveryXEpochs, const std::vector<Layer*>& _layers) :
    lossFunction(_lossFunction),
    printLossEveryXEpochs(_printLossEveryXEpochs),
    layers(_layers)
    {
        if (printLossEveryXEpochs <= 0)
            throw CustomException("Cannot construct neural network as printLossEveryXEpochs is non-positive");
    }

void NeuralNet::add_layer(Layer* layer) {
    layers.push_back(layer);
}

void NeuralNet::set_layers(const std::vector<Layer*>& _layers) {
    layers = _layers;
}

bool NeuralNet::insert_layer(Layer* layer, const int i) {
    if (i < 0 || i > layers.size())
        return false;

    layers.insert(layers.begin() + i, layer);
    return true;
}

bool NeuralNet::remove_top_layer() {
    if (layers.size() > 0) {
        layers.pop_back();
        return true;
    }
    return false;
}

bool NeuralNet::remove_layer(const int i) {
    if (i < 0 || i > layers.size())
        return false;

    layers.erase(layers.begin() + i);
    return true;
}

void NeuralNet::remove_all_layers() {
    layers.clear();
}

void NeuralNet::set_loss_function(const LossFunction& _lossFunction) {
    lossFunction = _lossFunction;
}

void NeuralNet::validate_params(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>>& labels, const int numEpochs, double learningRate) {
    if (data.size() != labels.size())
        throw CustomException("Cannot train model because there is not the same amount of labels as there as data points");
    if (data.size() == 0)
        throw CustomException("Cannot train model because there is no data");
    if (layers.size() == 0)
        throw CustomException("Cannot train model because there are no layers");
    if (learningRate <= 0)
        throw CustomException("Cannot train model because the learning rate is non-positive");
    if (numEpochs < 0)
        throw CustomException("Cannot train model because the number of epochs is negative");

    for (int i = 0; i < data.size(); ++i) {
        if (data[i].size() != layers[0]->NUM_INPUT_NODES)
            throw CustomException("Cannot train model because the number of input nodes does not match the dimension of the data");
        if (labels[i].size() != layers[layers.size() - 2]->NUM_OUTPUT_NODES)
            throw CustomException("Cannot train model because the number of output nodes (" + std::to_string(layers.back()->NUM_OUTPUT_NODES) +") does not match the dimension of the labels (" + std::to_string(labels[i].size()) + ") at indx " + std::to_string(i));
    }
}

void NeuralNet::train(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>>& labels, const int numEpochs, double learningRate) {
    validate_params(data, labels, numEpochs, learningRate);

    // the number of data points
    const int NUM_DATA_POINTS = data.size();

    for (int epoch = 0; epoch < numEpochs; ++epoch) {

        // the error, not used in calculation, just displayed to user
        double avgError = 0;

        for (int i = 0; i < NUM_DATA_POINTS; ++i) {
            // The output for a layer
            std::vector<double> output = data[i];
            // std::cout << output << std::endl;

            // Do forward propagation
            for (Layer* layer : layers) {
                output = layer->forward_prop(output);
            }

            // Record the error for this data point
            avgError += lossFunction.activationFunction(output, labels[i]);

            // Do backwards propagation
            // errorGradient acts as both derror_over_dx and derror_over_dy
            std::vector<double> errorGradient = lossFunction.activationFunctionDerivative(output, labels[i]);
            for (std::vector<Layer*>::reverse_iterator it = layers.rbegin(); it != layers.rend(); ++it)
                errorGradient = (*it)->backward_prop(errorGradient, learningRate);
        }

        avgError /= NUM_DATA_POINTS;
        if ((epoch + 1) % printLossEveryXEpochs == 0)
            std::cout << "Epoch " + std::to_string(epoch + 1) + ": " << std::to_string(avgError) << std::endl;
    }
}

std::vector<std::string> NeuralNet::get_info() {
    std::vector<std::string> info(layers.size(), "");
    for (int i = 0; i < layers.size(); ++i)
        info[i] = layers[i]->get_info();
    return info;
}