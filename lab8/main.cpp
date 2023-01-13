#include <iostream>
#include"stacktype.cpp"
using namespace std;

int main()
{
    char c;
    string s;
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;

    StackType<char> st;
    st.Push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        ns+=s[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')

        st.Push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(st.Top() != 'N' && st.Top() != '(')
            {
                char c = st.Top();
                //st.Pop();
               ns += c;
            }
            if(st.Top() == '(')
            {
                char c = st.Top();
                //st.Pop();
            }
        }

        //If an operator is scanned
        else{
            while(st.Top() != 'N' && prec(s[i]) <= prec(st.Top()))
            {
                char c = st.Top();
                //st.Pop();
                ns += c;
            }
            st.Push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(st.Top() != 'N')
    {
        char c = st.Top();
        //st.Pop();
        ns += c;
    }

    cout << ns << endl;

}
}
