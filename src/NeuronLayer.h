#ifndef NeuronLayer_H
#define NeuronLayer_H

#include "Neuron.h"
#include <vector>

class NeuronLayer {
    public:
        NeuronLayer(int numNeurons, int inputsCount);
        std::vector<double> feedForward(const std::vector<double>& inputs);
        int size();
        Neuron* getNeuron(int i);
    private:
        std::vector<Neuron> neurons;
};

#endif
