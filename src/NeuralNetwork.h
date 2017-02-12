#ifndef NeuralNetwork_H
#define NeuralNetwork_H
#include "NeuronLayer.h"
#include "TrainingSet.h"
#include <vector>

class NeuralNetwork {
    public:
        NeuralNetwork(int numInputs, int numHiddenNeurons, int numOutputNeurons) :
            numInputs(numInputs),
            hiddenLayer(numHiddenNeurons, numInputs),
            outputLayer(numOutputNeurons, numHiddenNeurons) {}
        std::vector<double> feedForward(const std::vector<double>& inputs);
        double getAverageError(const std::vector<TrainingSet>& trainingSet);
        void train(const TrainingSet& trainingSet);
    private:
        int numInputs;
        NeuronLayer hiddenLayer;
        NeuronLayer outputLayer;
};

#endif
