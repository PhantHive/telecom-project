#include <iostream>
#include "data_source.h"
#include "channel_calc.h"
#include "hamming.h"
#include <random>
#include <algorithm>

int main() {

    // data source is: 0.18, 0.02, 0.02, 0.13, 0.07, 0.17, 0.01, 0.2, 0.02, 0.18
    // implement it in a vector
    vector<double> source = {0.18, 0.02, 0.02, 0.13, 0.07, 0.17, 0.01, 0.2, 0.02, 0.18};
    // sort the vector from highest to lowest
    sort(source.begin(), source.end(), greater<>());

    // code worths are: 11, 101, 100, 011, 010, 001, 00011, 00010, 00001, 00000
    // implement it in a vector string
    vector<string> codeWorths = {"11", "101", "100", "011", "010", "001", "00011", "00010", "00001", "00000"};
    vector<double> nbZero = { 0, 1, 2, 1, 2, 2, 3, 4, 4, 5 };
    vector<double> nbOne = { 2, 2, 1, 2, 1, 1, 2, 1, 1, 0 };

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
    vector<double> probabilityOfZeroAndOne = calculateProbabilityOfZeroAndOne(source, nbZero, nbOne, averageCodeLength);
    std::cout << "Probability of Zero: " << round(probabilityOfZeroAndOne[0] * 100) / 100 << std::endl;
    std::cout << "Probability of One: " << round(probabilityOfZeroAndOne[1] * 100) / 100 << std::endl;

    // calculate Binary Entropy
    double binaryEntropy = calculateBinaryEntropy(probabilityOfZeroAndOne);
    binaryEntropy = round(binaryEntropy * 100) / 100;
    std::cout << "Binary Entropy: " << binaryEntropy << std::endl;

    // calculate Data Rate
    double dataRate = calculateDataRate(entropy, averageCodeLength);
    dataRate = round(dataRate * 100) / 100;
    std::cout << "Data Rate: " << dataRate << std::endl;

    // calculate data compression ratio
    double dataCompressionRatio = calculateDataCompressionRatio(entropy, averageCodeLength);
    dataCompressionRatio = round(dataCompressionRatio * 100) / 100;
    std::cout << "Compression Ratio: " << dataCompressionRatio << std::endl;


    // calculate channel capacity without noise
    double channelCapacityWithoutNoise = calculateChannelCapacityWithoutNoise();
    channelCapacityWithoutNoise = round(channelCapacityWithoutNoise * 100) / 100;
    std::cout << "Channel Capacity Without Noise: " << channelCapacityWithoutNoise << std::endl;

    // --------------------
    // Errors probability with BASK modulation
    // --------------------

    // calculate error probability for BASK modulation
    double errorProbabilityForBASKModulation = calculateErrorProbabilityForBASKModulation();
    std::cout << "Error Probability for BASK Modulation: " << errorProbabilityForBASKModulation << std::endl;


    // --------------------
    // Channel Capacity with Noise
    // --------------------

    // calculate channel capacity with noise
    double channelCapacityWithNoise = calculateChannelCapacityWithNoise(errorProbabilityForBASKModulation);
    channelCapacityWithNoise = round(channelCapacityWithNoise * 100) / 100;
    std::cout << "Channel Capacity With Noise BASK: " << channelCapacityWithNoise << std::endl;


    // same as above using BFSK modulation
    double errorProbabilityForBFSKModulation = calculateErrorProbabilityForBFSKModulation();
    std::cout << "Error Probability for BFSK Modulation: " << errorProbabilityForBFSKModulation << std::endl;
    double channelCapacityWithNoiseBFSK = calculateChannelCapacityWithNoise(errorProbabilityForBFSKModulation);
    channelCapacityWithNoiseBFSK = round(channelCapacityWithNoiseBFSK * 100) / 100;
    std::cout << "Channel Capacity With Noise BFSK: " << channelCapacityWithNoiseBFSK << std::endl;


    // --------------------
    // Group, non-systematic
    // --------------------

    // use hamming class to setMessageVector for "ZAKARIACHAOUKIZAKARIACHAOUKI"
    HammingEncoderDecoder hamming;
    hamming.setMessageVector("ELANSGRABSELANSGRABS");
    // show message vector using getMessageVector where the output is a vector
    vector<int> messageVector = hamming.getMessageVector();
    cout << "Message Vector: ";
    for (int i : messageVector) {
        cout << i;
    }
    cout << std::endl;

    // encode message vector using encodeNonSystematic
    hamming.encodeNonSystematic();
    // show encoded message vector using getEncodedMessageVector where the output is a vector
    vector<int> encodedMessageVector = hamming.getEncodedMessageVector();
    cout << "Encoded Message Vector: ";
    for (int i : encodedMessageVector) {
        cout << i;
    }
    cout << std::endl;

    // decode encoded message vector using decodeNonSystematic
    hamming.decodeNonSystematic();
    // show decoded message vector using getDecodedMessageVector where the output is a vector
    vector<int> decodedMessageVector = hamming.getDecodedMessageVector();
    cout << "Decoded Message Vector: ";
    for (int i : decodedMessageVector) {
        cout << i;
    }
    cout << std::endl;




    return 0;
}
