#include <iostream>
#include "dynArr.h"
#include "dynArr.cpp"

using namespace std;

int main()
{
    dynArr obj1;
    dynArr obj2(5);

    int uservalue;

    for(int i=0; i<5; i++)
    {
        cout <<"Enter element in position "<< i+1 <<" : ";
        cin >> uservalue;
        obj2.setValue(i,uservalue);
    }
    cout <<endl;
    cout <<"Printing elements : \n";
    for(int i=0; i<5 ; i++)
    {
        cout <<obj2.getValue(i)<<"\t";
    }

    obj2.~dynArr();
    cout << "\nAfter deletion printing values :  \n";
    for(int i=0; i <5; i++)
    {
        cout << obj2.getValue(i)<<"\t";
    }

    return 0;
}
