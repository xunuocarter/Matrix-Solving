#ifndef MATRIX
#define MATRIX
#include <fstream>
#include <iostream>
#include "fraction.h"
using namespace std;
typedef fraction* fp;//define a fraction pointer
typedef int* ip;//define an int pointer
template<class T,class V>//create a template for int and fraction
class matrix:public fraction
{
public:
    matrix();//default
    matrix(ip a_matrix[]);//copy for int pointer
    matrix(fp a_matrix[]);//copy for fraction pointer
    ~matrix();//destructor
    void get_equations();//get the input coefficients
    void fill_matrix();//put the input into a two dimensional int pointer array
    void convert_to_fraction();//copy the numbers and put them into a two dimensional fraction pointer array
    void print_equation(T number);//output the input equation
    void print_matrix1();//print the input
    void print_matrix2();//print the rref
    void calculate();//calculate the matrix and find its rref
    void print_solutions();//print the solutions

private:
    T row, col;//the row and colum size
    ip *mat1;
    fp *mat2;
};

#endif // MATRIX

