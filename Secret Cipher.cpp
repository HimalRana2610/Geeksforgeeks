#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compress(string &s)
    {
        int n = s.length();
        vector<int> lps(n);
        lps[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int l = lps[i - 1];
            while (l > 0 && s[i] != s[l])
            {
                l = lps[l - 1];
            }

            if (s[i] == s[l])
            {
                l++;
            }

            lps[i] = l;
        }

        stack<char> st;
        for (int i = n - 1; i > 0; i--)
        {
            int l = i + 1;
            if (l % 2 != 0)
            {
                st.push(s[i]);
                continue;
            }

            bool flag = false;
            int block = l - lps[i];

            if (lps[i] * 2 >= l && l % block == 0 && (l / block) % 2 == 0)
            {
                flag = true;
            }

            if (flag)
            {
                st.push('*');
                i = (l / 2);
            }
            else
            {
                st.push(s[i]);
            }
        }

        string ans;
        ans.push_back(s[0]);

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};