#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string str;
    stack<char> st;

public:
    void append(char x)
    {
        str.push_back(x);
    }

    void undo()
    {
        st.push(str.back());
        str.pop_back();
    }

    void redo()
    {
        str.push_back(st.top());
        st.pop();
    }

    string read()
    {
        return str;
    }
};