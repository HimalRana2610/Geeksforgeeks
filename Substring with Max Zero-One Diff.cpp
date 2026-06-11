#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubstring(string &s)
    {
        int current = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            current += (s[i] == '0' ? 1 : -1);
            if (current < 0)
            {
                current = 0;
            }
            ans = max(current, ans);
        }

        return ans == 0 ? -1 : ans;
    }
};