#include <iostream>
#include "TimeStamp.cpp"

using namespace std;

int main(void)
{
    int hour,minute,second;

    cout <<"Enter hour minute and seconds : ";
    cin >>hour>>minute>>second;
    TimeStamp obj1;
    obj1.Initialize(hour,minute,second);

    cout <<"\nEnter hour minute and seconds : ";
    cin >>hour>>minute>>second;
    TimeStamp obj2;
    obj2.Initialize(hour,minute,second);

    bool isEqual = obj1==obj2;
    cout <<"\nObject 1 : ";
    obj1.print();
    cout <<"\nObject 1 : ";
    obj2.print();

    cout << "\nAre they not equal ? " <<isEqual<<endl;

    TimeStamp **list = new TimeStamp*[5];
    for(int i=0; i<5; i++){
        list[i] = new TimeStamp[1];
    }
    cout << "\nEnter 5 time values in format Hour : Minute : Second : " <<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<1; j++){
            cin >>hour>>minute>>second;
            list[i][j].Initialize(hour,minute,second);
        }
    }
    cout << "\n\nPrinting :  " <<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<1; j++){
            cout << list[i][j].print() << endl;
        }
    }




    return 0;
}
