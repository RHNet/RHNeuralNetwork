#include "NeuralNetwork.h"
#include "NeuronLayer.h"
#include "TrainingSet.h"
#include <iostream>
#include <vector>
#include <cmath> // abs

//NeuralNetwork::NeuralNetwork(int numInputs, int numHiddenNeurons, int numOutputNeurons) {
    //this->numInputs = numInputs;
    //this->hiddenLayer = new NeuronLayer(numHiddenNeurons, numInputs);
//    this->outputLayer = new NeuronLayer(numOutputNeurons, numHiddenNeurons);
//}

std::vector<double> NeuralNetwork::feedForward(const std::vector<double>& inputs) {
    std::vector<double> hiddenOutputs = hiddenLayer.feedForward(inputs);
    return outputLayer.feedForward(hiddenOutputs);
};

double NeuralNetwork::getAverageError(const std::vector<TrainingSet>& trainingSet) {
    double total = 0;
    for (int i = 0; i < trainingSet.size(); i++) {
        TrainingSet data = trainingSet[i];
        double setError = 0;
        std::vector<double> outputResults = this->feedForward(data.inputs);
        for (int j = 0; j < outputResults.size(); j++) {
            double error = std::abs(data.outputs[j] - outputResults[j]);
            setError += error;
        }
        total += setError / data.outputs.size();
    }
    return total / trainingSet.size();
};

void NeuralNetwork::train(const TrainingSet& trainingSet) {
    this->feedForward(trainingSet.inputs);
    // Fehler im OutputLayer berechnen und Gewichte anpassen
    for (int i = 0; i < outputLayer.size(); i++) {
        Neuron* outputNeuron = outputLayer.getNeuron(i);
        double predictedOutput = outputNeuron->getLastOutput();
        double targetOutput = trainingSet.outputs[i];
        outputNeuron->setPdErrorWrtOutput(targetOutput - predictedOutput);
        outputNeuron->updateWeights();
      }
    // HiddenLayer Gewichte anpassen
    for (int j = 0; j < hiddenLayer.size(); j++) {
        Neuron* hiddenNeuron = hiddenLayer.getNeuron(j);
        double newPdErrorWrtOutput = 0;
        for (int k = 0; k < outputLayer.size(); k++) {
            Neuron* outputNeuron = outputLayer.getNeuron(k);
            newPdErrorWrtOutput += outputNeuron->getWeight(j) * outputNeuron->getPdErrorWrtNet();
        }
        hiddenNeuron->setPdErrorWrtOutput(newPdErrorWrtOutput);
        hiddenNeuron->updateWeights();
    }
};
