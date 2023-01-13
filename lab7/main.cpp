#include <iostream>
#include "quetype.cpp"
#include "quetype.h"
#include <queue>

using namespace std;

int main()
{

    QueType<string> q;
    int i,n;
    cout<<"Value for n?"<<endl;
    cin>>n;
    for(i=1; i<=n; i++){
    q.Enqueue("1");

    while (n--)
    {
        string s1=q.front;
        q.Dequeue();
        cout << s1 << "\n";
        string s2 = s1;
        q.Enqueue(s1.append("0"));
        q.Dequeue(s2.append("1"));

    }
    }

}
