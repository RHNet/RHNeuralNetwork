#include "ActivationFunction.h"
#include <cmath>

double ActivationFunction::calculate(double value) {
    return 1 / (1 + std::exp(-value));
}

double ActivationFunction::derivative(double value) {
    return value * (1 - value);
}
