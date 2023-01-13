#include <iostream>
#include "complex.cpp"

using namespace std;

int main()
{
    Complex cm1(2,5);
    Complex cm2(3,7);

    Complex k = cm1 + cm2;
    cout <<"Complex addition : "<<
    k.Print();

    Complex k1 = cm1 * cm2;
    cout <<"\nComplex multiplication : "<<
    k1.Print();

    bool k2 = cm1 != cm2;
    cout <<"\n Are they equals : "<< k2;
    return 0;
}
