#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2)
    {
        if (s1.length() < s2.length())
        {
            swap(s1, s2);
            swap(costS1, costS2);
        }

        int n = s1.length(), m = s2.length();
        vector<int> prev(m + 1), current(m + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    current[j] = prev[j - 1] + 1;
                }
                else
                {
                    current[j] = max(prev[j], current[j - 1]);
                }
            }
            swap(prev, current);
        }

        return (n - prev[m]) * costS1 + (m - prev[m]) * costS2;
    }
};