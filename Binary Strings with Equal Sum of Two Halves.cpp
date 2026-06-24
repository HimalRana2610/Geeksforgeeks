#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(long long a, long long b)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
            {
                ans = (ans * a) % 1000000007;
            }

            a = (a * a) % 1000000007;
            b >>= 1;
        }

        return ans;
    }
    int computeValue(int n)
    {
        long long fact1 = 1, fact2 = 1;
        for (int i = 1; i <= 2 * n; i++)
        {
            fact1 = (fact1 * i) % 1000000007;
        }

        for (int i = 1; i <= n; i++)
        {
            fact2 = (fact2 * i) % 1000000007;
        }

        return (fact1 * power((fact2 * fact2) % 1000000007, 1000000007 - 2)) % 1000000007;
    }
};