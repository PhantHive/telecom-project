#include <iostream>
#include "data_source.h"
#include <random>

int main() {

    // data source is: 0.18, 0.02, 0.02, 0.13, 0.07, 0.17, 0.01, 0.2, 0.02, 0.18
    // implement it in a vector
    vector<double> source = {0.18, 0.02, 0.02, 0.13, 0.07, 0.17, 0.01, 0.2, 0.02, 0.18};

    // code worths are: 11, 101, 100, 011, 010, 001, 00011, 00010, 00001, 00000
    // implement it in a vector string
    vector<string> codeWorths = {"11", "101", "100", "011", "010", "001", "00011", "00010", "00001", "00000"};

    // calculate entropy
    double entropy = calculateSourceEntropy(source);
    entropy = round(entropy * 100) / 100;
    std::cout << "Entropy: " << entropy << std::endl;

    // calculate maximum entropy for this source
    double maxEntropy = calculateMaximumEntropy(source);
    maxEntropy = round(maxEntropy * 100) / 100;
    std::cout << "Maximum Entropy: " << maxEntropy << std::endl;

    // calculate redundancy
    double redundancy = calculateRedundancy(entropy, maxEntropy);
    redundancy  = round(redundancy * 100) / 100;
    std::cout << "Redundancy: " << redundancy << std::endl;


    // calculate average code length
    double averageCodeLength = calculateAverageCodeLength(source, codeWorths);
    averageCodeLength = round(averageCodeLength * 100) / 100;
    std::cout << "Average Code Length: " << averageCodeLength << std::endl;

    // calculate probability of zero and one
    vector<double> probabilityOfZeroAndOne = calculateProbabilityOfZeroAndOne(codeWorths);
    std::cout << "Probability of Zero: " << round(probabilityOfZeroAndOne[0] * 100) / 100 << std::endl;
    std::cout << "Probability of One: " << round(probabilityOfZeroAndOne[1] * 100) / 100 << std::endl;


    return 0;
}
