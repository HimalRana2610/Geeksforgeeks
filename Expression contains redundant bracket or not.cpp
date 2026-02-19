#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                bool isRedundant = true;
                while (!st.empty() && st.top() != '(')
                {
                    char top = st.top();
                    st.pop();

                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                }

                if (!st.empty())
                {
                    st.pop();
                }

                if (isRedundant)
                {
                    return true;
                }
            }

            else
            {
                st.push(s[i]);
            }
        }

        return false;
    }
};