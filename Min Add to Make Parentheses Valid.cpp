#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minParentheses(string &s)
    {
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans++;
                }
            }
        }

        return ans + st.size();
    }
};