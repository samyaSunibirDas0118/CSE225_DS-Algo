#include <iostream>

using namespace std;

int main()
{
    //Allocating of Memory
    int *a= new int;
    *a = 99;

    //cout<<a<<endl;  //Prints Address
    //cout<<*a<<endl; //Prints value

    char *b = new char[5];
    int x = 5;
    float *c = new float[3*x];
    double **d = new double*[10];

    //De-Allocation of Memory
    delete a;

    delete [] b;
    delete [] c;
    delete [] d;
}
