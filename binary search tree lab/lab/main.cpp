#include<iostream>
#include "binarysearchtree.cpp"


int main() {

    TreeType<char> *root = NULL;
    int count, input;
    cout <<"How many nodes ? ";
    cin >> count;
    cout <<"\nEnter nodes : ";
    for(int i=0; i<count; i++)
    {
        cin >> input;
        root = Insert(root, input);
    }
    cout <<"\nIn order Print : ";
    InOrder(root);
    cout <<endl;
    cout <<"\nPost Order Print : ";
    PostOrder(root);
    cout <<endl;
    cout <<"Pre Order Print : ";
    PreOrder(root);
    cout <<endl;

    return 0;


    return 0;
}
