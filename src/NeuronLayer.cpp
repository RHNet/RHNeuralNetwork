#include "NeuronLayer.h"
#include "Neuron.h"
#include "Utils.h"
#include <vector>
#include <stdlib.h> // abs


NeuronLayer::NeuronLayer(int numNeurons, int inputsCount) {
    double bias = Utils::random();
    // init numNeurons neurons
    this->neurons = std::vector<Neuron>(abs(numNeurons), Neuron(bias , inputsCount));
}

std::vector<double> NeuronLayer::feedForward(const std::vector<double>& inputs) {
    int s = this->neurons.size();
    std::vector<double> outputs(s); // TODO geht verloren wenn scope verlassen
    // wird, solle aber weiter existieren --> muss auf Heap mit "new" und
    // spaeter per Hand geloescht werden.
    for (int i = 0; i < s; i++) {
        outputs[i] = this->neurons[i].calculateOutput(inputs);
    }
    return outputs;
};

int NeuronLayer::size() {
    return this->neurons.size();
}

Neuron* NeuronLayer::getNeuron(int i) {
    return &this->neurons[i];
}
