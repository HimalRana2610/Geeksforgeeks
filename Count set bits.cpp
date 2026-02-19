#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            int x = 31 - __builtin_clz(n);
            int p = 1 << x;

            ans += x * (p >> 1);
            ans += n - p + 1;
            n -= p;
        }

        return ans;
    }
};