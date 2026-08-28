#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(long long base, long long exp)
    {
        long long ans = 1;
        while (exp > 0)
        {
            if (exp & 1)
            {
                ans = (ans * base) % 1000000007;
            }

            base = (base * base) % 1000000007;
            exp >>= 1;
        }

        return ans;
    }

    int prefixStrings(int n)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans * 2 * (2 * i - 1)) % 1000000007;
            ans = (ans * power(i + 1, 1000000005)) % 1000000007;
        }

        return ans;
    }
};