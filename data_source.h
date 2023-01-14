//
// Created by Zakaria on 10/12/2022.
//

#ifndef TT_PROJECT_DATA_SOURCE_H
#define TT_PROJECT_DATA_SOURCE_H

#endif //TT_PROJECT_DATA_SOURCE_H

#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

// create function that calculate the source entropy

double calculateSourceEntropy(vector<double> &source) {

    // calculate the entropy using sourc entropy formula -> H(X) = -sum(p(x) * log2(p(x))) and source contain all probabilities
    double entropy = 0;
    for (double i : source) {
        entropy += i * log2(i);
    }

    return -entropy;
}

double calculateMaximumEntropy(vector<double> &source) {
    // calculate the maximum entropy using the formula -> Hmax = log2(n)
    return log2(source.size());
}

double calculateRedundancy(double entropy, double maxEntropy) {
    // calculate the redundancy using the formula -> R = 1 - (H(X) / Hmax)
    return 1 - (entropy / maxEntropy);
}

double calculateAverageCodeLength(vector<double> &source, vector<string> &codeWorths) {
    // calculate the average code length using the formula -> L = sum(p(x) * l(x))
    double averageCodeLength = 0;
    for (int i = 0; i < source.size(); i++) {
        averageCodeLength += source[i] * codeWorths[i].size();
    }

    return averageCodeLength;
}



vector<double> calculateProbabilityOfZeroAndOne(vector<double> &source, vector<double>nbZero, vector<double>nbOne, double averageCodeLength) {
    // calculate the probability of zero and one using the formula -> P0 = sum(p(x) * nbZero(x)) / averageCodeLength  and P1 = sum(p(x) * nbOne(x)) / averageCodeLength
    double probabilityOfZero = 0;
    double probabilityOfOne = 0;
    for (int i = 0; i < source.size(); i++) {
        probabilityOfZero += source[i] * nbZero[i];
        probabilityOfOne += source[i] * nbOne[i];
    }

    probabilityOfZero /= averageCodeLength;
    probabilityOfOne /= averageCodeLength;

    return {probabilityOfZero, probabilityOfOne};
}


double calculateBinaryEntropy(vector<double> probabilityOfZeroAndOne) {
    // calculate the binary entropy using the formula -> H(X) = -p(0) * log2(p(0)) - p(1) * log2(p(1))
    return -probabilityOfZeroAndOne[0] * log2(probabilityOfZeroAndOne[0]) - probabilityOfZeroAndOne[1] * log2(probabilityOfZeroAndOne[1]);
}

double calculateDataRate(double sourceEntropy, double averageCodeLength) {
    // symbol duration = 10
    double Sd = 10e-9;
    // calculate the data rate using the formula -> R = H(X) / (L * Sd)
    cout << sourceEntropy << endl;
    return sourceEntropy / (averageCodeLength * Sd);
}

double calculateDataCompressionRatio(double sourceEntropy, double averageCodeLength) {
    // calculate the data compression ratio using the formula -> C = L / H(X)
    return averageCodeLength / sourceEntropy;
}