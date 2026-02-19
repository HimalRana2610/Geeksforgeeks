#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdig(string &s, int k)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            while (!st.empty() && k > 0 && st.top() > s[i])
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int idx = 0;
        while (idx < ans.length() && ans[idx] == '0')
        {
            idx++;
        }
        ans = ans.substr(idx);

        if (ans.length() == 0)
        {
            return "0";
        }

        return ans;
    }
};