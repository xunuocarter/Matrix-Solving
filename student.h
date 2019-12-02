#ifndef STUDENT
#define STUDENT
#include <fstream>
#include <iostream>
#include "matrix.h"
using namespace std;
struct Node//struct a linknode for student's name and id
{
    string name;
    long id;
    Node* link;
};
typedef Node* np;//define a pointer type of node

template<class T,class V>
class Student//create a student class
{
public:
    Student();//default
    ~Student();//delete
    int get_choice();//get input choice
    void calculate();//calculate the matrix
    void print_result();//print the result
    void run();//beginning interface
    void add();//add a new student
    void print();//print the student link list
    void end();//print the ending statement
private:
    np front, back;//two pointers of queue
    matrix<int, fraction> mat;//use int and fraction as the template class type
};

#endif // STUDENT
