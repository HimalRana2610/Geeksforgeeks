#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCharGap(string &s)
    {
        vector<int> prev(26, -1);
        int ans = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (prev[s[i] - 'a'] != -1)
            {
                ans = max(ans, i - prev[s[i] - 'a'] - 1);
            }
            else
            {
                prev[s[i] - 'a'] = i;
            }
        }

        return ans;
    }
};