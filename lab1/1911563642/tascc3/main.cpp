#include<iostream>
using namespace std;

int main() {

   int row,col;

   cout<<"How many rows do you want? ";
   cin>>row;



   int** arr = new int*[row];

   for(int i = 0; i < row; i++){

    arr[i] = new int[col];
    cout<<"How many columns do you want? ";
    cin>>col;
    for(int j = 0; j < col; j++){
           cout<<"R "<<i+1<<" C "<<j+1<<" value: ";
           cin>>arr[i][j];
   }
   }



   cout<<"Output array: \n";
   for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; j++){
            cout<<arr[i][j]<<"\t";
    }
     cout<<endl;
   }
   for (int i = 0; i < row; i++)
{
    delete[] arr[i];
}
delete[] arr;
return 0;
}


