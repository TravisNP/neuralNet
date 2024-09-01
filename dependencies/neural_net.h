#ifndef NEURAL_NET
#define NEURAL_NET

#include <vector>
#include <iostream>

#include "layer.h"
#include "loss_functions.h"

class NeuralNet {
private:
    // The layers of the neural network
    std::vector<Layer*> layers;

    // The loss function of the neural network
    LossFunction lossFunction;

    // Print loss every X epochs
    int printLossEveryXEpochs;

public:
    /**
     * Constructor for the neural network
     * @param _lossFunction the loss function to use
     * @param _layers the layers of the neural network
     */
    NeuralNet(const LossFunction& _lossFunction, const int _printLossEveryXEpochs, const std::vector<Layer*>& _layers = {});

    /**
     * Adds a layer to the neural network
     * @param layer the layer to add
     */
    void add_layer(Layer* layer);

    /**
     * Inserts the layer into the ith position
     * @param layer the layer to insert
     * @param i the indx to insert layer at
     * @return true if the layer was inserted, false if indx is out of bounds
     */
    bool insert_layer(Layer* layer, const int i);

    /**
     * Sets the neural network's layers to _layers
     * @param _layers what the layers of the neural network will be set to
     */
    void set_layers(const std::vector<Layer*>& _layers);

    /**
     * Removes the top layer of the neural network
     * @return true if a layer was removed, false if empty
     */
    bool remove_top_layer();

    /**
     * Removes the layer in the ith position
     * @param i the indx to remove
     * @return true if the layer was remove, false if indx is out of bounds
     */
    bool remove_layer(const int i);

    /**
     * Removes all layers
     */
    void remove_all_layers();

    /**
     * Sets the loss function for the neural network to use
     * @param _lossFunction the loss function
     */
    void set_loss_function(const LossFunction& _lossFunction);

    /**
     * Validates the parameters
     * @param data the data
     * @param labels the labels for the data
     * @param numEpochs the number of epochs
     * @param learningRate the learning rate
     */
    void validate_params(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>>& labels, const int numEpochs, double learningRate);

    /**
     * Trains the neural network on the data and labels for the number of epochs specified with the learning rate
     * @param data the data
     * @param labels the labels for the data
     * @param numEpochs the number of epochs
     * @param learningRate the learning rate
     */
    void train(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>>& labels, const int numEpochs, double learningRate);

    /**
     * Gets info about each layer
     * @return a vector with info about each layer in it's corresponding indx
     */
    std::vector<std::string> get_info();
};

#endif