#include <iostream>
#include "matrix.hpp"

int main() {

    // Step 1 - 4
    int sizeOfWebpages = 4;

    // Creating our Initialization Matrix
    Matrix G(sizeOfWebpages, sizeOfWebpages);

    // Initializing the values in our connectivity matrix
    try {
        ifstream input("connectivity.txt");

        for(int i = 0; i < G.matrix.size(); i++) {
            for(int j = 0; j < G.matrix[i].size(); j++) {
                input>> G.matrix[i][j];
            }
        }
        input.close();
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // Step 8
    // Creating our Initialization Matrix
    Matrix S(sizeOfWebpages, sizeOfWebpages);

    try {
        for(int i = 0; i < G.matrix.size(); i++) {
            for(int j = 0; j < G.matrix[i].size(); j++) {
                double valueOfG = G.get_Value(i, j);
                if (valueOfG == 1) {
                    valueOfG /= 2.0;
                    S.set_Value(i, j, valueOfG);
                } else {
                    S.set_Value(i, j, 0.0);
                }
            }
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // Step 9
    try {
        for(int i = 0; i < S.matrix.size(); i++) {
            int numOfZeros = 0;
            for(int j = 0; j < S.matrix[i].size(); j++) {
                if(S.get_Value(i,j) == 0.0) {
                    numOfZeros++;
                }
            }
            // Found the column of all zeros
            if(numOfZeros == S.matrix[i].size()) {
                double evenDistribution = 1 / S.matrix[i].size();
                for(int j = 0; j < S.matrix[i].size(); j++) {
                    S.set_Value(i, j, evenDistribution);
                }
            }
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // Step 11 - 12
    // Random Walk Probability Factor
    double p = 0.85;

    // Matrix Q with all elemented = 1 / n
    Matrix Q(4, 4);
    try {
        for(int i = 0; i < Q.matrix.size(); i++) {
            double evenDistribution = 1 / S.matrix[i].size();
            for(int j = 0; j < Q.matrix[i].size(); j++) {
                S.set_Value(i, j, evenDistribution);
            }
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // Transition Matrix
    // Throwing Exception here
    try {
        Matrix M = p * S + (1 - p) * Q;
    } catch (const char* msg) {
        cout << msg << endl;
    }


//    // Step 13
//    Matrix rank(4, 1);
//    for(int i = 0; i < G.matrix.size(); i++) {
//        for(int j = 0; j < G.matrix[i].size(); j++) {
//            rank.set_Value(i, j, 1);
//        }
//    }

}