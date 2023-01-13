#include <iostream>
#include "timeStamp.cpp"

using namespace std;

int main()
{
    int h,m,s;

    cout<<"Give hour minute and second [object1]:";
    cin>>h>>m>>s;
    timeStamp obj1(h,m,s);

    cout<<"Give hour minute and second [object2]:";
    cin>>h>>m>>s;
    timeStamp obj2(h,m,s);

    bool k2 = obj1 != obj2;
    cout <<"They equal? 1= true, 0= false"<< "\nAnswer:\t"<<k2<<endl;
}
