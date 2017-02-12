#include <iostream>
#include "NeuralNetwork.h"
#include "Utils.h"
#include "TrainingSet.h"
#include "TrainingData.h"
#include <vector>
#include <sstream>

using namespace std;

void prettyPrintResult(const vector<double> &outputs)
{
    double result = 0;
    int resultNeuron = -1;
    bool success = false;
    for (int i = 0; i < outputs.size(); i++)
    {
        resultNeuron = i;
        result = outputs[i];
        if (result > 0.5)
        {
            success = true;
            break;
        }
    }

    ostringstream sstrResult;
    sstrResult << "from neuron " << resultNeuron << ": " << result;
    string strResult = sstrResult.str();
    cout << "result " << (success
                              ? string("YES (") + strResult + string(")")
                              : string("NO (") + strResult + string(")"))
         << endl
         << endl;
}

void train(NeuralNetwork &net)
{
    cout << "Feeding the Network with training data ..." << endl;
    std::vector<TrainingSet> trainingSets = TrainingData::createTrainingSet();
    for (int epoche = 0; epoche < 10000; epoche++)
    {
        // select random training set
        double r = Utils::randomInt(0, trainingSets.size());
        net.train(trainingSets[r]);
        if (epoche % 1000 == 999)
        {
            cout << endl;
            cout << "AVG error: " << net.getAverageError(trainingSets) << "\tepoche: " << epoche << endl;
        }
    }
    cout << "Done." << endl;
}

vector<double> askNet(NeuralNetwork &net, int numInputs)
{
    cout << "Now, please provide some input." << endl;

    std::vector<double> inputs(numInputs);
    ostringstream inputStr;
    for (int i = 0; i < numInputs; i++)
    {
        cout << "input[" << i << "]: ";
        inputs[i] = Utils::getInt();
        if (i > 0)
        {
            inputStr << ", ";
        }
        inputStr << inputs[i];
        cout << endl;
    }

    cout << "Asking the network to calculate your result for input (" << inputStr.str() << ")" << endl;
    return net.feedForward(inputs);
}

int main()
{
    cout << "RH Neural Network" << endl;
    cout << "=================" << endl;

    int numInputs = 2;
    int numHidden = 2;
    int numOutputs = 1;

    NeuralNetwork net(numInputs, numHidden, numOutputs);

    train(net);

    char ch;
    do
    {
        vector<double> outputs = askNet(net, numInputs);
        prettyPrintResult(outputs);

        cout << "Another round? (y/n)";
        cin >> ch;
    } while (ch == 'y');

    cout << "Bye =)" << endl;
    cout << "=================" << endl;
    return 0;
}
