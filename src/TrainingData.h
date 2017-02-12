#ifndef TrainingData_H
#define TrainingData_H

#include "TrainingSet.h"

class TrainingData {
    public:
        static TrainingSet createSet(double x, double y, double out);
        static std::vector<TrainingSet> createTrainingSet();
};

#endif
