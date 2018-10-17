//
// Created by tan_r on 10/16/2018.
//

#ifndef LAB03_CONNECTIVITYMATRIX_HPP
#define LAB03_CONNECTIVITYMATRIX_HPP
#include "Matrix.hpp"


/**
 * A square Matrix comprised of 0's and 1's.
 * Inherits from Matrix.
 */
class ConnectivityMatrix: public Matrix {

public:
    // Constructors
    ConnectivityMatrix();
    ConnectivityMatrix(int r, int c);
};


#endif //LAB03_CONNECTIVITYMATRIX_HPP
