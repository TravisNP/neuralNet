#include "neural_net.h"

NeuralNet::NeuralNet(const LossFunction& _lossFunction, const std::vector<Layer*>& _layers) : lossFunction(_lossFunction), layers(_layers) {}

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

std::vector<std::string> NeuralNet::get_info() {
    std::vector<std::string> info(layers.size(), "");
    for (int i = 0; i < layers.size(); ++i)
        info[i] = layers[i]->get_info();
    return info;
}