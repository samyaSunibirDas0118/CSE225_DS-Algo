#include<iostream>
using namespace std;

int main() {

   int rows, cols;

   cout<<"Enter number of rows: ";
   cin>>rows;

   cout<<"Enter number of columns: ";
   cin>>cols;

   char** arr = new char*[rows];

   for(int i = 0; i < rows; i++){

        arr[i] = new char[cols];
   }

   for(int i = 0; i < rows; ++i){
       for(int j = 0; j < cols; j++){
           cout<<"Enter row "<<i+1<<" column "<<j+1<<" value: ";
           cin>>arr[i][j];
        }
   }

   cout<<"output array is \n";
   for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            cout<<arr[i][j]<<"\t";
    }
     cout<<endl;
   }

    delete[] arr;

    cout<<"output array after deletion is \n";
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            cout<<arr[i][j]<<"\t";
    }
     cout<<endl;
   }

   return 0;
}
