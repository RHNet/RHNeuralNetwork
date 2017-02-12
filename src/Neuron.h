#ifndef Neuron_H
#define Neuron_H
#define LEARNING_RATE 0.5

#include <vector>

class Neuron {
    public:
        Neuron(double bias, const int& inputsCount);
        void setWeights(const std::vector<double>& weights);
        double calculateOutput(const std::vector<double>& inputs);
        void updateWeights();
        void setPdErrorWrtOutput(double error);
        double getLastOutput();
        double getWeight(int i);
        double getPdErrorWrtNet();
    private:
        double bias;
        std::vector<double> weights;
        std::vector<double> lastInputs;
        double lastOutput;
        double pdErrorWrtNet;
        double pdErrorWrtOutput;
        
        double weightedSum(const std::vector<double>& inputs);
};

#endif
