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


vector<double> calculateProbabilityOfZeroAndOne(vector<string> &codeWorths) {
    // create vector to store the probability of zero and one
    vector<double> probabilityOfZeroAndOne;

    // create variable to store the number of zero and one
    int numberOfZero = 0;
    int numberOfOne = 0;

    // loop over the code worths to calculate the number of zero and one
    for (const string& codeWorth : codeWorths) {
        for (char c : codeWorth) {
            if (c == '0') {
                numberOfZero++;
            } else {
                numberOfOne++;
            }
        }
    }

    // calculate the probability of zero and one
    double probabilityOfZero = (double) numberOfZero / (numberOfZero + numberOfOne);
    double probabilityOfOne = (double) numberOfOne / (numberOfZero + numberOfOne);

    // push the probability of zero and one to the vector
    probabilityOfZeroAndOne.push_back(probabilityOfZero);
    probabilityOfZeroAndOne.push_back(probabilityOfOne);

    return probabilityOfZeroAndOne;
}


double calculateSourceDataGenerationRate(vector<double> &source) {
    // calculate the source data generation rate using the formula -> R = H(A)/(mean(p(x))*binary symbol duration)
    double mean = 0;
    for (double i : source) {
        mean += i;
    }
    mean /= source.size();

    return calculateMaximumEntropy(source) / (mean * 1);
}