#ifndef LAYER
#define LAYER

#include <vector>
#include <string>

class Layer {
protected:
    std::vector<double> input;

public:
    /**
     * Constructor for layer class
     * @param _NUM_INPUT_NODES the number of input nodes, default 0
     * @param _NUM_OUTPUT_NODES the number of output nodes, default 0
     */
    Layer(const int _NUM_INPUT_NODES = 0, const int _NUM_OUTPUT_NODES = 0);

    // Virtual Desctructor
    virtual ~Layer() {}

    // Number of input nodes
    int NUM_INPUT_NODES;

    // Number of output nodes
    int NUM_OUTPUT_NODES;

    // Abstract forward propogation function
    virtual std::vector<double> forward_prop(const std::vector<double>& _input) = 0;

    // Abstract backward propogation function
    virtual std::vector<double> backward_prop(const std::vector<double>& outputError, const double learningRate) = 0;

    // Abstract method to print info
    virtual std::string get_info() = 0;
};

#endif