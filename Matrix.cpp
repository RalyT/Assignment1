//
// Created by tan_r on 10/4/2018.
//

#include "matrix.hpp"

/**
 * Default constructor that initializes a 1x1 matrix with a value 0.0
 */
Matrix::Matrix() {

    vector<double> newRow;
    newRow.push_back(0.0);
    matrix.push_back(newRow);
}

/**
 * Constructor that initializes a nxn matrix with values of 0.0
 * @param n
 */
Matrix::Matrix(int n) {

    // Checks if the number is greater than 0, otherwise throw an exception.
    if(n <= 0) {
        throw "Exception: Parameter int n is negative or 0.";
    } else {
        for (int i = 0; i < n; i ++) {
            vector<double> newRow;
            for (int j = 0; j < n; j ++) {
                newRow.push_back(0.0);
            }
            matrix.push_back(newRow);
        }
    }
}

/**
 * Constructor that initializes a r x c matrix with values of 0.0
 * @param n
 */
Matrix::Matrix(int r, int c) {

    if(r <= 0 || c <= 0) {
        throw "Exception: Parameter int r or c is negative or 0";
    } else {
        for (int i = 0; i < r; i ++) {
            vector<double> newRow;
            for (int j = 0; j < c; j ++) {
                newRow.push_back(0.0);
            }
            matrix.push_back(newRow);
        }
    }
}

/**
 * Accepts an array of ints, and stores the values in a square matrix.
 * @param arrSize The size of the array
 */
Matrix::Matrix(double intArr[], int arrSize) {

    int sizeSqrt = sqrt(arrSize);
    // Error handling to check if the square root of arrSize is an integer
    if(sizeSqrt - floor(sizeSqrt) == 0) {
        throw "Exception: arrSize must have an Integer square root";
    } else {
        for (int i = 0; i < sizeSqrt; i++) {
            vector<double> newRow;
            for (int j = i * sizeSqrt; j < (i * sizeSqrt + sizeSqrt); j++) {
                newRow.push_back(intArr[j]);
            }
            matrix.push_back(newRow);
        }
    }
}

/**
 * Mutator for assigning a new value to an index in the matrix
 * @param row
 * @param column
 * @param newVal
 * @return
 */
void Matrix::set_Value(int row, int column, double newVal) {

    if(row < 0 || row > matrix.size()
        || column < 0 || column > matrix[0].size()) {
        throw "Exception: Parameter Row or Column must be within matrix index";
    } else {
        matrix[row][column] = newVal;
    }
}

/**
 * Accessor for retrieving a value in the matrix.
 * @param row
 * @param column
 */
double Matrix::get_value(int row, int column) {

    if(row < 0 || row > matrix.size()
       || column < 0 || column > matrix[0].size()) {
        throw "Exception: Parameter Row or Column must be within matrix index";
    } else {
        return matrix[row][column];
    }
}

/**
 * Clears all of the values in the matrix, resetting them to 0.0
 */
void Matrix::clear() {

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = 0.0;
        }
    }
}
/**
 * Matrix Destructor
 */
Matrix::~Matrix() {

}

/**
 * Overloaded insertion operator to print the matrix to output
 * @param os
 * @param a
 * @return
 */
ostream& operator<<(std::ostream& os, const Matrix& a) {

    for (int i = 0; i < a.matrix.size(); i++) {
        for (int j = 0; j < a.matrix[i].size(); j++) {
            cout << a.matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

/**
 * Overloaded == operator for comparing matrices.
 * @param lhs Main matrix
 * @param rhs Other matrix being compared to
 * @return true if the matrices are the same size and contain the same values.
 */
bool operator==(const Matrix& lhs, const Matrix& rhs) {

    // Checks if the size of the matrices are the same
    if(lhs.matrix.size() == rhs.matrix.size()
        && lhs.matrix[0].size() == rhs.matrix[0].size()) {

        // Compare the values within the matrices
        double d_tolerance = 0.001;
        for (int i = 0; i < lhs.matrix.size(); i++) {
            for (int j = 0; j < lhs.matrix[i].size(); j++) {
                // Checks to see if the difference of the items is greater thean tolerance
                if(lhs.matrix[i][j] - rhs.matrix[i][j] > d_tolerance) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

/**
 * Overloaded != operator for comparing matrices.
 * @param lhs Main matrix
 * @param rhs Other matrix being compared to
 * @return true if the matrices are not the same size or contain the same values.
 */
bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !operator==(lhs,rhs);
}

