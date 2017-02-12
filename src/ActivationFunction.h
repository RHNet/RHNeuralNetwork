#ifndef ActivationFunction_H
#define ActivationFunction_H

class ActivationFunction {
    public:
        ActivationFunction(){};
        static double calculate(double value);
        static double derivative(double value);
};

#endif
