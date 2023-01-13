#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Number of elements?\n"<<endl; //take input
    cin>>n;
    int *nums = new int [n];

    //cout<<n;

    for (int i=0; i < n; i++){
        cout<<"\nGive Value"<<i+1<<endl;
        cin>>nums[i];
    }   //input taking ends
    cout <<"Output"<<endl; //output
    for (int i=0;i<n;i++){
        cout<<nums[i]<<endl;
    }
    delete[] nums; //deletion starts
    for (int i=0;i<n;i++){
        cout<<nums[i]<<endl;
    }   //output after deletion

}
