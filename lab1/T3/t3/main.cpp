#include<iostream>
using namespace std;

int main() {

    int row,col;

    cout<<"How many rows do you want? ";
    cin>>row;

    int **pArrayElements = (int**) calloc (sizeof (int*), row);

    int *pMatSize = (int *) calloc (sizeof (int), row);

    for ( int i =0; i<row; i++)
    {
        cout<<"How many columns do you want for line " << i << ": ";
        cin>>col;

        cout<<"memory allocation for line "<< i<<endl;
        pArrayElements[i] = (int*) calloc (sizeof(int), col);
        pMatSize[i] = col;
    }

    for ( int i =0; i<row; i++)
        for ( int j =0; j<pMatSize[i]; j++)
        {
            cout<<"enter value for row "<< i << " col "<< j<< endl;
            cin>>pArrayElements[i][j];
        }

    return 0;
}
