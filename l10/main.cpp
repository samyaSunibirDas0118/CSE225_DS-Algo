#include<iostream>

#include "unsortedtype.cpp"

int main(void){

    UnsortedType<int> o1;

    cout<< "gib 5 values : " <<endl;

    for (int i=0;i<5;i++){
        int values;
        cin>> values;
        o1.InsertItem(values);
    }

    int length1 = o1.LengthIs();
    cout<< " length rn : " << length1 <<endl;


    cout<< "u inserted : " <<endl;
    int k;
    for ( int i=0;i <length1;i++){
        o1.GetNextItem(k);
        cout << k << " " ;
    }


}
