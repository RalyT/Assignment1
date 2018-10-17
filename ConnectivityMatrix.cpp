//
// Created by tan_r on 10/16/2018.
//

#include "ConnectivityMatrix.hpp"

/**
 * Default Constructor
 */
ConnectivityMatrix::ConnectivityMatrix(): Matrix() { }

/**
 * Constructor that initializes a r x c matrix with values of 0.0
 * @param r Row
 * @param c Column
 */
ConnectivityMatrix::ConnectivityMatrix(int r, int c):
                    Matrix(r, c) { }