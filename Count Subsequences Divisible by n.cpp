#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubsequences(string &s, int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < s.length(); i++)
        {
            int digit = s[i] - '0';
            vector<int> current(dp);
            current[digit % n] = (current[digit % n] + 1) % 1000000007;

            for (int r = 0; r < n; r++)
            {
                int nr = (r * 10 + digit) % n;
                current[nr] = (current[nr] + dp[r]) % 1000000007;
            }

            dp = current;
        }

        return dp[0];
    }
};