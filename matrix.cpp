#include "matrix.h"
#include <iostream>
using namespace std;
template <class T, class V>
matrix<T,V>::matrix():row(3),col(4)
{

}
template <class T, class V>
matrix<T,V>::matrix(ip a_matrix[])
{
    for(int i=0; i<row; i++)
    {
        a_matrix[i] = new int[col];
        for(int j=0; j<col; j++)
        {
            a_matrix[i][j] = mat1[i][j];
        }
    }
}
template <class T, class V>
matrix<T,V>::matrix(fp a_matrix[])
{
    for(int i=0; i<row; i++)
    {
        a_matrix[i] = new fraction[col];
        for(int j=0; j<col; j++)
        {
            a_matrix[i][j] = mat2[i][j];
        }
    }
}
template <class T, class V>
matrix<T,V>::~matrix()
{
    delete []mat1;
    delete []mat2;
}
template <class T, class V>
void matrix<T,V>::get_equations()
{
    cout << "If the equation is 2x + 3y - z = 5"<<endl;
    cout << "You just have to enter the coefficients: 2 3 -1 5"<<endl;
}
template <class T, class V>
void matrix<T,V>::fill_matrix()
{
    mat1 = new ip[row];
    for(int i=0; i<row; i++)//build matrix 1
    {
        mat1[i] = new T[col];
        for(int j=0; j<col; j++)
        {
            mat1[i][j] = 0;
        }
    }
    T next;
    for(int i=0; i<row; i++)
    {
        if(i==0)
        {
            cout <<"Enter your first equation's coefficients: ";
        }
        if(i==1)
        {
            cout <<"Enter your second equation's coefficients: ";
        }
        if(i==2)
        {
            cout <<"Enter your third equation's coefficients: ";
        }
        for(int j=0; j<col; j++)//fill matrix 1
        {
            cin >> next;
            mat1[i][j]= next;
        }
        cout <<"equation "<<i+1<<" is ";
        print_equation(i);
    }
}
template <class T, class V>
void matrix<T,V>::convert_to_fraction()
{
    mat2 = new fp[row];
    for(int i=0; i<row; i++)//build matrix 2
    {
        mat2[i] = new V[col];
        for(int j=0; j<col; j++)
        {
            mat2[i][j] = 0;
        }
    }
    for(int i=0; i <row; i++)//fill matrix 2
    {
        for(int j=0; j<col; j++)
        {
            mat2[i][j]=mat1[i][j];
        }
    }
}
template <class T, class V>
void matrix<T,V>::print_equation(T number)
{
    char variable = 'a';//defien the first variable as 'a'
    T i = number;
    for(int j=0; j<col; j++)
    {
        if(mat1[i][0]!=0&&j==0)//if 0, no output
        {
            if(mat1[i][j]<0)
            {
                if(mat1[i][0]==-1)//negative -
                {
                    cout <<"-"<<static_cast<char>(variable+j);
                }
                else
                {
                    cout <<mat1[i][0]<<static_cast<char>(variable+j);
                }
            }
            else
            {
                if(mat1[i][0]==1)//positive
                {
                    cout <<static_cast<char>(variable+j);
                }
                else
                {
                    cout <<mat1[i][0]<<static_cast<char>(variable+j);
                }
            }
        }

        if(mat1[i][j]!=0&&j!=0&&j!=col-1)
        {
            if(mat1[i][j]<0)
            {
                if(mat1[i][j]==-1)//get rid of '1' as coef
                {
                    cout <<"-"<<static_cast<char>(variable+j);
                }
                else
                {
                    cout <<mat1[i][j]<<static_cast<char>(variable+j);
                }
            }
            else
            {
                if(mat1[i][j]==1)
                {
                    cout <<"+"<<static_cast<char>(variable+j);
                }
                else
                {
                    cout <<"+"<<mat1[i][j]<<static_cast<char>(variable+j);
                }
            }
        }
        if(j==col-1)
        {
            if(mat1[i][j]!=0)
            {
                if(mat1[i][j]<0)
                {
                    if(mat1[i][j]==-1)//get rid of '1' as coef
                    {
                        cout <<" = -"<<static_cast<char>(variable+j);
                    }
                    else
                    {
                        cout <<mat1[i][j]<<static_cast<char>(variable+j);
                    }
                }
                else
                {
                    if(mat1[i][j]==1)
                    {
                        cout <<" = 1";
                    }
                    else
                    {
                        cout <<" = "<<mat1[i][j];
                    }
                }
            }
            else
            {
                cout <<" = 0";
            }
        }
    }
    cout <<endl;
}
template <class T, class V>
void matrix<T,V>::print_matrix1()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
template <class T, class V>
void matrix<T,V>::print_matrix2()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
template <class T, class V>
void matrix<T,V>::calculate()

{
    T j;
    V temp;
    temp = mat2[0][0];
    for(j =0; j< col; j++)
    {
        mat2[0][j] = mat2[0][j] / temp;
    }
    temp = mat2[1][0];
    for(j = 0;j < col;j++)
    {
        mat2[1][j] = mat2[1][j] - mat2[0][j] * temp;
    }
    temp = mat2[2][0];
    for(j = 0;j < col; j++)
    {
        mat2[2][j] = mat2[2][j] - mat2[0][j] * temp;
        // 1 x x x
        // 0 x x x
        // 0 x x x
    }
    temp = mat2[1][1];
    for(j = 0;j < col; j++)
    {
        mat2[1][j] = mat2[1][j] / temp;
        // 1 x x x
        // 0 1 x x
        // 0 x x x
    }
    temp = mat2[2][1];
    for(j = 0;j < col; j++)
    {
        mat2[2][j] = mat2[2][j] - mat2[1][1] * temp * mat2[1][j];
        // 1 x x x
        // 0 1 x x
        // 0 0 x x
    }
    temp = mat2[2][2];
    for(j = 0;j < col; j++)
    {
        mat2[2][j] = mat2[2][j] / temp;
        // 1 x x x
        // 0 1 x x
        // 0 0 1 x
    }
    temp = mat2[1][2];
    for(j = 0;j < col; j++)
    {
        mat2[1][j] = mat2[1][j] - mat2[2][2] * temp * mat2[2][j];
        // 1 x x x
        // 0 1 0 x
        // 0 0 1 x
    }
    temp = mat2[0][1];
    for(j = 0;j < col; j++)
    {
        mat2[0][j] = mat2[0][j] - mat2[1][1] * temp * mat2[1][j];
        // 1 0 x x
        // 0 1 0 x
        // 0 0 1 x
    }
    temp = mat2[0][2];
    for(j = 0;j < col; j++)
    {
        mat2[0][j] = mat2[0][j] - mat2[2][2] * temp * mat2[2][j];
        // 1 0 0 x
        // 0 1 0 x
        // 0 0 1 x
    }
}
template <class T, class V>
void matrix<T,V>::print_solutions()
{
    cout <<"The solutions are: "<<endl;
    cout <<"a = "<<mat2[0][3]<<endl;
    cout <<"b = "<<mat2[1][3]<<endl;
    cout <<"c = "<<mat2[2][3]<<endl;
}
