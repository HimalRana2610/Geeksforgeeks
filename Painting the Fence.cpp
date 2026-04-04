#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }

        long long same = k, diff = 1LL * k * (k - 1);
        long long ans = same + diff;

        for (int i = 3; i <= n; i++)
        {
            long long newSame = diff, newDiff = ans * (k - 1);
            same = newSame;
            diff = newDiff;
            ans = same + diff;
        }

        return static_cast<int>(ans);
    }
};