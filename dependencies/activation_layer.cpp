#include "activation_layer.h"

ActivationLayer::ActivationLayer(ActivationFunction activationFuncTuple) :
    activation_func(get<0>(activationFuncTuple)),
    activation_func_derivative(get<1>(activationFuncTuple)),
    activationFunctionName(get<2>(activationFuncTuple)) {}

std::vector<double> ActivationLayer::forward_prop(const std::vector<double>& _input) {
    input = _input;

    std::vector<double> output(_input.size(), 0);
    transform(_input.begin(), _input.end(), output.begin(), activation_func);
    return output;
}

std::vector<double> ActivationLayer::backward_prop(const std::vector<double>& outputError, const double learningRate) {
    std::vector<double> capitalSigmaPrime(input.size(), 0);
    transform(input.begin(), input.end(), capitalSigmaPrime.begin(), activation_func_derivative);
    return hadamard_product(outputError, capitalSigmaPrime);
}

std::string ActivationLayer::get_info() {
    return "ActivationLayer - " + activationFunctionName;
}