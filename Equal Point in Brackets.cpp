#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findIndex(string &s)
    {
        int n = s.length();
        vector<int> open(n + 1, 0), close(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            open[i + 1] = open[i] + (s[i] == '(');
            close[i + 1] = close[i] + (s[i] == ')');
        }

        for (int i = 0; i < n; i++)
        {
            if (open[i] == close[n] - close[i])
            {
                return i;
            }
        }

        return n;
    }
};