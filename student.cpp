#include<iostream>
#include<string>
#include "student.h"
template <class T, class V>
Student<T,V>::Student(): front(NULL), back(NULL)
{

}
template <class T, class V>
Student<T,V>::~Student()
{

}
template <class T, class V>
void Student<T,V>::calculate()
{
    mat.get_equations();
    mat.fill_matrix();
    cout <<"The matrix for the input equations is:"<<endl;
    mat.print_matrix1();
    mat.convert_to_fraction();
    mat.calculate();
    cout <<"After calculation, the reduced row echelon form is:"<<endl;
    mat.print_matrix2();
}
template <class T, class V>
void Student<T,V>::print_result()
{
    mat.print_solutions();
}
template <class T, class V>
void Student<T,V>::run()
{
    cout << "*********************************************************\n";
    cout << "**************Welcome to the matrix solver!**************\n";
    cout << "*********************************************************\n";
    cout <<"First you have to login."<<endl;
    add();
    cout <<"You have the following options:"<<endl;
    cout <<"1. Solve a set of equations."<<endl;
    cout <<"2. Check your solutions."<<endl;
    cout <<"3. Login with as another student."<<endl;
    cout <<"4. Check the students who have used this solver."<<endl;
    cout <<"5. Exit this program."<<endl;
}
template <class T, class V>
void Student<T,V>::add()
{
    string names;
    long id_num;
    cout << "Please enter your name: " << endl;
    getline(cin, names);
    cout << "Please enter your ID number: " << endl;
    cin >> id_num;
    if(back == NULL)//first time
    {
        front = new Node;
        front->name = names;
        front->id = id_num;
        front->link = NULL;
        back = front;
    }
    else//not first time
    {
        np temp;
        temp = new Node;
        temp->name = names;
        temp->id = id_num;
        temp->link = NULL;
        back->link = temp;
        back = temp;
    }
}
template <class T, class V>
int Student<T,V>::get_choice()
{
    int choice;
    cout <<"Please enter your choice: ";
    cin >> choice;
    if(choice<1||choice>5)//validate the input choice
    {
        cout <<"Invalid choice! Please enter again: ";
        cin >> choice;
    }
    return choice;
}
template <class T, class V>
void Student<T,V>::print()
{
    cout<<"The student list is: "<<endl;
    np iter;
    for(iter=front;iter!=NULL;iter=iter->link)
    {
        cout<<"Student "<<iter->name<<" with Id number "<<iter->id<<endl;
    }
}
template <class T, class V>
void Student<T,V>::end()
{
    cout<< "Professor Ashraf is the best!"<<endl;
    cout<< "Have a nice day! =)"<<endl;
}
