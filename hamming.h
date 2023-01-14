//
// Created by Zakaria on 31/12/2022.
//

#ifndef TT_PROJECT_MATRIX_H
#define TT_PROJECT_MATRIX_H

#endif //TT_PROJECT_MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class HammingEncoderDecoder {

private:
    // Private member variable to store the message vector
    vector<int> message_vector_;
    // Private member variable to store the encoded message vector
    vector<int> encoded_message_vector_;
    // Private member variable to store the decoded message vector
    vector<int> decoded_message_vector_;

    // Encoded matrix
    const vector<vector<int>> encoded_matrix_ = {
            {1, 1, 1, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 0, 1}
    };

    // Syndrom matrix
    const vector<vector<int>> syndrom_matrix_ = {
//            {0, 0, 0, 0, 1},
//            {0, 0, 0, 1, 0},
//            {0, 0, 0, 1, 1},
//            {0, 0, 1, 0, 0},
//            {0, 0, 1, 0, 1},
//            {0, 0, 1, 1, 0},
//            {0, 0, 1, 1, 1},
//            {0, 1, 0, 0, 0},
//            {0, 1, 0, 0, 1},
//            {0, 1, 0, 1, 0},
//            {0, 1, 0, 1, 1},
//            {0, 1, 1, 0, 0},
//            {0, 1, 1, 0, 1},
//            {0, 1, 1, 1, 0},
//            {0, 1, 1, 1, 1},
//            {1, 0, 0, 0, 0},
//            {1, 0, 0, 0, 1},
//            {1, 0, 0, 1, 0},
//            {1, 0, 0, 1, 1},
//            {1, 0, 1, 0, 0},
//            {1, 0, 1, 0, 1},
//            {1, 0, 1, 1, 0},
//            {1, 0, 1, 1, 1},
//            {1, 1, 0, 0, 0},
//            {1, 1, 0, 0, 1},
//            {1, 1, 0, 1, 0},
//            {1, 1, 0, 1, 1}
            {0, 0, 1},
            {0, 1, 0},
            {0, 1, 1},
            {1, 0, 0},
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 1}
    };


public:
    // Constructor for the HammingEncoderDecoder class
    HammingEncoderDecoder() = default;


    // Function to get the message vector
    vector<int> getMessageVector() {
        // Insert code to return the message vector here
        return message_vector_;
    }

    // Function to get the codeword vector (encoded_message_vector_)
    vector<int> getEncodedMessageVector() {
        // Insert code to return the codeword vector here
        return encoded_message_vector_;
    }

    // Function to get the decoded message vector
    vector<int> getDecodedMessageVector() {
        // Insert code to return the decoded message vector here
        return decoded_message_vector_;
    }


    // Function to set the message vector based on the string:
    // if "A" or "R" then set "1"s otherwise set "0"s
    void setMessageVector(string message) {
        // Insert code to set the message vector here
        for (char i : message) {
            if (i == 'E' || i == 'A') {
                message_vector_.push_back(1);
            } else {
                message_vector_.push_back(0);
            }
        }
    }


    // Function to encode the message and write the codeword to the encoded_message_vector_
    void encodeNonSystematic() {
        // Insert code to encode the message here
        for (int i = 0; i < encoded_matrix_[0].size(); i++) {
            int sum = 0;
            for (int j = 0; j < encoded_matrix_.size(); j++) {
                sum += encoded_matrix_[j][i] * message_vector_[j];
            }
            encoded_message_vector_.push_back(sum % 2);
        }
    }

    // Decode the codeword and write the message to the decoded_message_vector_
    void decodeNonSystematic() {
        // Insert code to decode the codeword here
        vector<int> syndrom_vector;
        for (int i = 0; i < syndrom_matrix_[0].size(); i++) {
            int sum = 0;
            for (int j = 0; j < syndrom_matrix_.size(); j++) {
                sum += syndrom_matrix_[j][i] * encoded_message_vector_[j];
            }
            syndrom_vector.push_back(sum % 2);
        }

        int syndrom_index = 0;
        for (int i = 0; i < syndrom_matrix_.size(); i++) {
            if (syndrom_matrix_[i] == syndrom_vector) {
                syndrom_index = i;
                break;
            }
        }

        if (syndrom_index == 0) {
            decoded_message_vector_ = message_vector_;
        } else {
            encoded_message_vector_[syndrom_index - 1] = (encoded_message_vector_[syndrom_index - 1] + 1) % 2;
            for (int i = 0; i < encoded_matrix_[0].size(); i++) {
                int sum = 0;
                for (int j = 0; j < encoded_matrix_.size(); j++) {
                    sum += encoded_matrix_[j][i] * encoded_message_vector_[j];
                }
                decoded_message_vector_.push_back(sum % 2);
            }
        }
    }




};