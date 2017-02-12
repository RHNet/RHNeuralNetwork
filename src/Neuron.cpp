#include "Neuron.h"
#include "ActivationFunction.h"
#include "Utils.h"

Neuron::Neuron(double bias, const int& inputsCount) {
    this->bias = bias;
    this->weights = std::vector<double>(inputsCount);
    // init random weights
    for (int i = 0; i < weights.size(); i++) {
        weights[i] = Utils::random();
    }
    this->lastInputs = std::vector<double>(inputsCount);
    this->lastOutput = 0;
    this->pdErrorWrtNet = 0;
    this->pdErrorWrtOutput = 0;
}


void Neuron::setWeights(const std::vector<double>& weights) {
    for (int i = 0; i < this->weights.size(); i++) {
        this->weights[i] = weights[i];
    }
}

double Neuron::calculateOutput(const std::vector<double>& inputs) {
    for (int i = 0; i < inputs.size(); i++) {
        this->lastInputs[i] = inputs[i];
    }
    double output = ActivationFunction::calculate(weightedSum(inputs));
    this->lastOutput = output;
    return output;
}

double Neuron::weightedSum(const std::vector<double>& inputs) {
    double sum = 0;
    for (std::vector<double>::size_type i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * weights[i];
    }
    return sum + bias;
}

void Neuron::updateWeights() {
    double pdOutputWrtNet = ActivationFunction::derivative(this->lastOutput);
    this->pdErrorWrtNet = this->pdErrorWrtOutput * pdOutputWrtNet;

    int i = 0;
    int w = 0;
    int _ref = this->weights.size() - 1;
    
    for (;
        0 <= _ref ? i <= _ref : i >= _ref;
        w = (0 <= _ref ? ++i : --i))
    {
        double pdNetWrtInput = this->lastInputs[w];
        double pdErrorWrtWeight = this->pdErrorWrtNet * pdNetWrtInput;
        this->weights[w] += LEARNING_RATE * pdErrorWrtWeight;
    }
}

double Neuron::getLastOutput() {
    return lastOutput;
}

void Neuron::setPdErrorWrtOutput(double error) {
    this->pdErrorWrtOutput = error;
}

double Neuron::getWeight(int i) {
    return this->weights[i];
}

double Neuron::getPdErrorWrtNet() {
    return this->pdErrorWrtNet;
}
