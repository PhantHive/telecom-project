#include <iostream>
#include "data_source.h"
#include "channel_calc.h"
#include "hamming.h"
#include <random>
#include <algorithm>

using namespace std;

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
    cout << "Entropy: " << entropy << endl;

    // calculate maximum entropy for this source
    double maxEntropy = calculateMaximumEntropy(source);
    maxEntropy = round(maxEntropy * 100) / 100;
    cout << "Maximum Entropy: " << maxEntropy << endl;

    // calculate redundancy
    double redundancy = calculateRedundancy(entropy, maxEntropy);
    redundancy  = round(redundancy * 100) / 100;
    cout << "Redundancy: " << redundancy << endl;


    // calculate average code length
    double averageCodeLength = calculateAverageCodeLength(source, codeWorths);
    averageCodeLength = round(averageCodeLength * 100) / 100;
    cout << "Average Code Length: " << averageCodeLength << endl;

    // calculate probability of zero and one
    vector<double> probabilityOfZeroAndOne = calculateProbabilityOfZeroAndOne(source, nbZero, nbOne, averageCodeLength);
    cout << "Probability of Zero: " << round(probabilityOfZeroAndOne[0] * 100) / 100 << endl;
    cout << "Probability of One: " << round(probabilityOfZeroAndOne[1] * 100) / 100 << endl;

    // calculate Binary Entropy
    double binaryEntropy = calculateBinaryEntropy(probabilityOfZeroAndOne);
    binaryEntropy = round(binaryEntropy * 100) / 100;
    cout << "Binary Entropy: " << binaryEntropy << endl;

    // calculate Data Rate
    double dataRate = calculateDataRate(entropy, averageCodeLength);
    dataRate = round(dataRate * 100) / 100;
    cout << "Data Rate: " << dataRate << endl;

    // calculate data compression ratio
    double dataCompressionRatio = calculateDataCompressionRatio(entropy, averageCodeLength);
    dataCompressionRatio = round(dataCompressionRatio * 100) / 100;
    cout << "Compression Ratio: " << dataCompressionRatio << endl;

    cout << "---------------------" << endl;
    cout << "Shannon conditions" << endl;
    cout << "---------------------" << endl;

    // calculate channel capacity without noise
    double channelCapacityWithoutNoise = calculateChannelCapacityWithoutNoise();
    channelCapacityWithoutNoise = round(channelCapacityWithoutNoise * 100) / 100;
    cout << "Channel Capacity Without Noise: " << channelCapacityWithoutNoise << endl;

    // --------------------
    // Errors probability with BASK modulation
    // --------------------

    // calculate error probability for BASK modulation
    double errorProbabilityForBASKModulation = calculateErrorProbabilityForBASKModulation();
    cout << "Error Probability for BASK Modulation: " << errorProbabilityForBASKModulation << endl;


    // --------------------
    // Channel Capacity with Noise
    // --------------------

    // calculate channel capacity with noise
    double channelCapacityWithNoise = calculateChannelCapacityWithNoise(errorProbabilityForBASKModulation);
    channelCapacityWithNoise = round(channelCapacityWithNoise * 100) / 100;
    cout << "Channel Capacity With Noise BASK: " << channelCapacityWithNoise << endl;


    // same as above using BFSK modulation
    double errorProbabilityForBFSKModulation = calculateErrorProbabilityForBFSKModulation();
    cout << "Error Probability for BFSK Modulation: " << errorProbabilityForBFSKModulation << endl;
    double channelCapacityWithNoiseBFSK = calculateChannelCapacityWithNoise(errorProbabilityForBFSKModulation);
    channelCapacityWithNoiseBFSK = round(channelCapacityWithNoiseBFSK * 100) / 100;
    cout << "Channel Capacity With Noise BFSK: " << channelCapacityWithNoiseBFSK << endl;


    // --------------------
    // Group, non-systematic
    // --------------------

    cout << "---------------------" << endl;
    cout << "Group, non-systematic" << endl;
    cout << "---------------------" << endl;

    // use hamming class to setMessageVector for "ZAKARIACHAOUKIZAKARIACHAOUKI"
    HammingEncoderDecoder hamming;
    hamming.setMessageVector("ZAKARIACHAOUKIZAKARIACHAOUKI");
    // show message vector using getMessageVector where the output is a vector
    vector<int> messageVector = hamming.getMessageVector();
    cout << "Message Vector: ";
    for (int i : messageVector) {
        cout << i;
    }
    cout << endl;

    // encode message vector using encodeNonSystematic
    hamming.encodeNonSystematic();
    // show encoded message vector using getEncodedMessageVector where the output is a vector
    vector<int> encodedMessageVector = hamming.getEncodedMessageVector();
    cout << "Encoded Message Vector: ";
    for (int i : encodedMessageVector) {
        cout << i;
    }
    cout << endl;

    // decode encoded message vector using decodeNonSystematic
    hamming.decodeNonSystematic();
    // show decoded message vector using getDecodedMessageVector where the output is a vector
    vector<int> decodedMessageVector = hamming.getDecodedMessageVector();
    cout << "Decoded Message Vector: ";
    for (int i : decodedMessageVector) {
        cout << i;
    }
    cout << endl;

    // --------------------
    // INTRODUCING ERRORS
    // --------------------

    cout << "---------------------" << endl;
    cout << "Introducing errors" << endl;
    cout << "---------------------" << endl;

    // introduce a single error in the encoded message vector
    hamming.introduceSingleError(3);
    // show encoded message vector using getEncodedMessageVector where the output is a vector
    vector<int> encodedMessageVectorWithError = hamming.getEncodedMessageVector();
    cout << "Encoded Message Vector With Error: ";
    for (int i : encodedMessageVectorWithError) {
        cout << i;
    }
    cout << endl;
    // decode encoded message vector using decodeNonSystematic
    hamming.decodeNonSystematic();
    // show decoded message vector using getDecodedMessageVector where the output is a vector
    vector<int> decodedMessageVectorWithError = hamming.getDecodedMessageVector();
    cout << "Decoded Message Vector With Error: ";
    for (int i : decodedMessageVectorWithError) {
        cout << i;
    }
    cout << endl;

    // remove error from encoded message vector
    hamming.removeError(3);

    // introduce two errors in the encoded message vector
    hamming.introduceTwoErrors(3, 5);
    // show encoded message vector using getEncodedMessageVector where the output is a vector
    vector<int> encodedMessageVectorWithTwoErrors = hamming.getEncodedMessageVector();
    cout << "Encoded Message Vector With Two Errors: ";
    for (int i : encodedMessageVectorWithTwoErrors) {
        cout << i;
    }
    cout << endl;
    // decode encoded message vector using decodeNonSystematic
    hamming.decodeNonSystematic();
    // show decoded message vector using getDecodedMessageVector where the output is a vector
    vector<int> decodedMessageVectorWithTwoErrors = hamming.getDecodedMessageVector();
    cout << "Decoded Message Vector With Two Errors: ";
    for (int i : decodedMessageVectorWithTwoErrors) {
        cout << i;
    }
    cout << endl;


    // ------------------
    // Probability more than 2 errors
    // ------------------
    int m = 27;
    double BER = 0.0244143;
    double prob = HammingEncoderDecoder::probMoreThan2Errors(m, BER);
    cout << "---------------------" << endl;
    cout << "Probability of more than 2 errors per codeword: " << prob << endl;

    return 0;
}
