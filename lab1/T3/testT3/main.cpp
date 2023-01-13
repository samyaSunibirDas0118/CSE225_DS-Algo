#include<iostream>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>


int main() {

     _CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int row,col;
    cout<<"How many rows do you want? "; cin>>row;

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

    for ( int i =0; i<row; i++)
        free (pArrayElements[i]);

    free (pArrayElements);
    free (pMatSize);

    return 0;
}
