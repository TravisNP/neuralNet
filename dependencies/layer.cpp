#include <vector>

class Layer {
protected:
    std::vector<double> input;

public:
    Layer(const int _NUM_INPUT_NODES, const int _NUM_OUTPUT_NODES) : NUM_INPUT_NODES(_NUM_INPUT_NODES), NUM_OUTPUT_NODES(_NUM_INPUT_NODES) {}

    // Virtual Desctructor
    virtual ~Layer() {}

    // Number of input nodes
    int NUM_INPUT_NODES;

    // Number of output nodes
    int NUM_OUTPUT_NODES;

    // Abstract forward propogation function
    virtual std::vector<double> forward_prop(std::vector<double> _input) = 0;

    // Abstract backward propogation function
    virtual std::vector<double> backward_prop(std::vector<double> output, const int learningRate) = 0;
};