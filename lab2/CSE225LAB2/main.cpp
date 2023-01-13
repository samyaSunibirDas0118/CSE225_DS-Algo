#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{
    //creating two objects

    dynArr obj1;
    dynArr obj2(5);

    int uservalue;

    for(int i=0;i< 5;i++){
        cout<<"enter element in position "<<i+1<<": ";
        cin>>uservalue;
        obj2.setValue(i,uservalue);
    }

    cout<<"Printing the given values: "<<endl;

    for(int i=0;i<5;i++){
        cout<<obj2.getValue(i)<<"\t";
    }

    obj2.~dynArr();

    cout<<"\nAfter deletion printing the given values: "<<endl;

    for(int i=0;i<5;i++){
        cout<<obj2.getValue(i)<<"\t";
    }

    //END OF FIRST TASK

    //SECOND TASK



    //END OF SECOND TASK

    //THIRD TASK



    //END OF THIRD TASK

    return 0;
}
