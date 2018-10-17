//
// Created by tan_r on 10/4/2018.
//

#ifndef LAB03_MATRIX_HPP
#define LAB03_MATRIX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

/**
 * Base Matrix Class
 */
class Matrix {

protected:
    std::vector< vector<double> > matrix;

public:

    // Constructors
    Matrix();
    Matrix(int n);
    Matrix(int r, int c);
    Matrix(double intArr[], int arrSize);

    // Destructor
    ~Matrix();

    // Accessors and Mutators
    void set_Value(int row, int column, double newVal);
    double get_Value(int row, int column) const;
    int get_Row_Size() const;
    int get_Col_Size(int row) const;
    void print_Matrix() const;
    void clear();

    // Overloading == and != operators
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    // Overloading increment and decrement operators
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);

    // Swap function
    friend void swap(Matrix& lhs, Matrix& rhs);
    Matrix& operator=(Matrix other);

    // Overloading + and += operators
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    // Overloading - and -= operators
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
    // Overloading * and *= operators
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
};
#endif //LAB03_MATRIX_HPP
