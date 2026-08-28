#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWithout(int n, int d)
    {
        if (n <= 0)
        {
            return 0;
        }

        vector<vector<int>> dp(2, vector<int>(2));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = j;
            }
        }

        string s = to_string(n);
        for (int pos = s.length() - 1; pos >= 0; pos--)
        {
            vector<vector<int>> new_dp(2, vector<int>(2, 0));
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    int l = i ? (s[pos] - '0') : 9, current = 0;
                    for (int digit = 0; digit <= l; digit++)
                    {
                        int nj = j || (digit != 0);
                        if (nj && digit == d)
                        {
                            continue;
                        }

                        int ni = i && (digit == l);
                        current += dp[ni][nj];
                    }
                    new_dp[i][j] = current;
                }
            }
            dp = move(new_dp);
        }

        return dp[1][0];
    }
};