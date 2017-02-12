#include "TrainingData.h"

TrainingSet TrainingData::createSet(double x, double y, double out) {
    std::vector<double> inputs(2);
    inputs[0] = x;
    inputs[1] = y;

    std::vector<double> outputs(1);
    outputs[0] = out;

    return TrainingSet(inputs, outputs);   
}

std::vector<TrainingSet> TrainingData::createTrainingSet() {
    std::vector<TrainingSet> trainingData;
    trainingData.push_back(createSet(0,0,0));
    trainingData.push_back(createSet(0,1,1));
    trainingData.push_back(createSet(1,0,1));
    trainingData.push_back(createSet(1,1,1));
    return trainingData;
}
