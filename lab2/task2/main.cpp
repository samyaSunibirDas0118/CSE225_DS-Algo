#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{

    int s=0;

    dynArr obj1;
    dynArr obj2;
    obj2.allocate(s);



    int uservalue;

    cout<<"Enter Array Size"<<endl;
    cin>>s;

    for(int i=0;i< s;i++){
        cout<<"Input Element for position "<<i+1<<": ";
        cin>>uservalue;
        obj2.setValue(i,uservalue);
    }

    cout<<"Output values: "<<endl;

    for(int i=0;i<s;i++){
        cout<<obj2.getValue(i)<<"\t";
    }

    obj2.~dynArr();

    cout<<"\nAfter deletion printing the given values: "<<endl;

    for(int i=0;i<s;i++){
        cout<<obj2.getValue(i)<<"\t";
    }



    return 0;
}
