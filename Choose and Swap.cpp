#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string chooseSwap(string &s)
    {
        int n = s.length();
        vector<int> first(26, -1);

        for (int i = 0; i < n; i++)
        {
            if (first[s[i] - 'a'] == -1)
            {
                first[s[i] - 'a'] = i;
            }
        }

        int pos = -1;
        char x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c < s[i] - 'a'; c++)
            {
                if (first[c] > i)
                {
                    pos = i;
                    x = s[i];
                    y = char('a' + c);
                    break;
                }
            }

            if (pos != -1)
            {
                break;
            }
        }

        if (pos == -1)
        {
            return s;
        }

        string ans = s;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == x)
            {
                ans[i] = y;
            }
            else if (ans[i] == y)
            {
                ans[i] = x;
            }
        }

        return ans;
    }
};