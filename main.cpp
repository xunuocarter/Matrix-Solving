#include <iostream>
#include <string>
#include "fraction.h"
#include "matrix.h"
#include "matrix.cpp"
#include "student.h"
#include "student.cpp"
using namespace std;

int main()
{
    Student<int, fraction> user;
    user.run();
    int choice;
    do
    {
        choice = user.get_choice();
        switch(choice)
        {
        case 1:
            user.calculate();
            break;
        case 2:
            user.print_result();
            break;
        case 3:
            cin.ignore();//clean up the input
            user.add();
            break;
        case 4:
            user.print();
            break;
        }
    }while(choice!=5);
    user.end();

    return 0;
}

