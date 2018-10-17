#include <iostream>
#include "matrix.hpp"
#include "ConnectivityMatrix.hpp"

int main() {

    // Step 1 - 4
    int sizeOfWebpages = 4;

    // Creating our Initialization Matrix
    ConnectivityMatrix G(sizeOfWebpages, sizeOfWebpages);

    // Initializing the values in our connectivity matrix from .txt
    try {
        // Opening input stream to connectivity.txt
        ifstream input("connectivity.txt");
        if(!input) {
            cout << "connectivity.txt could not be opened" << endl;
        }

        for(int i = 0; i < G.get_Row_Size(); i++) {
            for(int j = 0; j < G.get_Col_Size(i); j++) {
                double currentVal;
                input >> currentVal;
                G.set_Value(i, j, currentVal);
            }
        }
        input.close();
    } catch (const char* msg) {
        cout << msg << endl;
    }

    cout << "Connectivity Matrix G:" << endl;
    G.print_Matrix();
    cout << endl;

    // Step 8
    // Creating our Probability Matrix S
    ConnectivityMatrix S(sizeOfWebpages, sizeOfWebpages);

    try {
        for(int i = 0; i < G.get_Row_Size(); i++) {
            for(int j = 0; j < G.get_Col_Size(i); j++) {
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

    cout << "Connectivity Matrix S:" << endl;
    S.print_Matrix();
    cout << endl;

    // Step 9
    try {
        // Searches for all columns of only 0's
        for(int i = 0; i < S.get_Row_Size(); i++) {
            int numOfZeros = 0;
            for(int j = 0; j < S.get_Col_Size(i); j++) {
                if(S.get_Value(j,i) == 0.0) {
                    numOfZeros++;
                }
            }
            // Found a column of all zeros, applying 1/n
            if(numOfZeros == S.get_Col_Size(i)) {
                double evenDistribution = 1.0 / S.get_Col_Size(i);
                for(int j = 0; j < S.get_Col_Size(i); j++) {
                    S.set_Value(j, i, evenDistribution);
                }
            }
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    cout << "Connectivity Matrix S:" << endl;
    S.print_Matrix();
    cout << endl;

    // Step 11 - 12
    // Random Walk Probability Factor
    double p = 0.85;

    // Matrix Q with all elemented = 1 / n
    Matrix Q(4, 4);
    try {
        for(int i = 0; i < Q.get_Row_Size(); i++) {
            double evenDistribution = 1 / S.get_Col_Size(i);
            for(int j = 0; j < Q.get_Col_Size(i); j++) {
                S.set_Value(i, j, evenDistribution);
            }
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // Transition Matrix
    // Throwing Exception here
//    try {
//        Matrix M = p * S + (1 - p) * Q;
//    } catch (const char* msg) {
//        cout << msg << endl;
//    }


//    // Step 13
//    Matrix rank(4, 1);
//    for(int i = 0; i < G.get_Row_Size(); i++) {
//        for(int j = 0; j < G.get_Col_Size(i); j++) {
//            rank.set_Value(i, j, 1);
//        }
//    }

}