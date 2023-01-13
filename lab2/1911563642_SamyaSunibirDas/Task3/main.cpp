#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{


    dynArr obj1;
    dynArr obj2;

    int uservalue;

    int row, col;


   cout<<"How many rows do you want? ";
   cin>>row;

   cout<<"How many columns do you want? ";
   cin>>col;

   int** arr = new int*[row];

   for(int i = 0; i < row; i++){

        arr[i] = new int[col];
   }
   for(int i = 0; i < row; ++i){
       for(int j = 0; j < col; j++){
           cout<<"R "<<i+1<<" C"<<j+1<<" value: ";
           cin>>arr[i][j];

        }
   }

   cout<<"Output Array: \n";
   for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<"\t";
    }
     cout<<endl;
   }

    delete[] arr;

    cout<<"output array after deletion is \n";
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<"\t";
    }
     cout<<endl;
   }




}
