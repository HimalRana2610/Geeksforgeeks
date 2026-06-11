#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lexicographicallySmallest(string &s, int k)
    {
        int n = s.length();
        if (n & (n - 1))
        {
            k += k;
        }
        else
        {
            k /= 2;
        }

        if (k >= n)
        {
            return "-1";
        }

        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k > 0 && st.top() > s[i])
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        if (k > 0)
        {
            while (k--)
            {
                st.pop();
            }
        }

        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};