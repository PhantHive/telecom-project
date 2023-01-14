//
// Created by Zakaria on 11/12/2022.
//

#ifndef TT_PROJECT_CHANNEL_CALC_H
#define TT_PROJECT_CHANNEL_CALC_H

#endif //TT_PROJECT_CHANNEL_CALC_H

#include <vector>
#include <cmath>

using namespace std;

// create function that calculate the channel capacity without noise
double calculateChannelCapacityWithoutNoise() {
    // calculate the channel capacity without noise using the formula -> Cbin = 1 / tsym
    double tsym = 10e-9;
    return 1 / tsym;
}

// calculate error probability for BASK modulation using Eb/N0 = 10^(SNR/10) where SNR = 8.9
double calculateErrorProbabilityForBASKModulation() {
    // calculate the error probability for BASK modulation using the formula -> Perror =  1 - 0.5 * (1 + erf(sqrt(Eb/N0) / 2))
    double EbN0 = pow(10, 8.9 / 10);
    return 1 - 0.5 * (1 + erf(sqrt(EbN0) / 2));
}

// calculate error probability for BFSK modulation using Eb/N0 = 10^(SNR/10) where SNR = 8.9
double calculateErrorProbabilityForBFSKModulation() {
    // calculate the error probability for BFSK modulation using the formula -> Perror =  1 - 0.5 * (1 + erf(sqrt((Eb/N0) / 2)))
    double EbN0 = pow(10, 8.9 / 10);
    return 1 - 0.5 * (1 + erf(sqrt(EbN0 / 2)));
}

// calculate error probability for BPSK modulation using Eb/N0 = 10^(SNR/10) where SNR = 8.9
double calculateErrorProbabilityForBPSKModulation() {
    // calculate the error probability for BPSK modulation using the formula -> Perror =  1 - 0.5 * (1 + erf(sqrt((Eb/N0))))
    double EbN0 = pow(10, 8.9 / 10);
    return 1 - 0.5 * (1 + erf(sqrt(EbN0)));
}


// calculate channel capacity with noise
double calculateChannelCapacityWithNoise(double errorProbabilityForBASKModulation) {
    // calculate the channel capacity with noise using the formula -> Cchan = (1 + Perr * log2(Perr) + (1 - Perr) * log2(1 - Perr)) / tsym
    double tsym = 10e-9;
    return (1 + errorProbabilityForBASKModulation * log2(errorProbabilityForBASKModulation) + (1 - errorProbabilityForBASKModulation) * log2(1 - errorProbabilityForBASKModulation)) / tsym;

}
