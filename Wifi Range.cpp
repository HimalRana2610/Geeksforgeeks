#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wifiRange(string &s, int x)
    {
        int n = s.length(), m = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (m < i - x - 1)
                {
                    return false;
                }
                m = max(m, i + x);
            }
        }

        return m >= n - 1;
    }
};