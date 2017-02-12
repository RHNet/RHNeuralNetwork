#ifndef TrainingSet_H
#define TrainingSet_H
#include <vector>

class TrainingSet
{
  public:
    std::vector<double> inputs;
    std::vector<double> outputs;

    TrainingSet(const std::vector<double> &inputs, const std::vector<double> &outputs) : inputs(inputs), outputs(outputs){};
};

#endif
