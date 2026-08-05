#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int get_mask(int n)
    {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mask = 0;

        for (int i = 0; i < 10; i++)
        {
            int cnt = 0;
            while (n % primes[i] == 0)
            {
                cnt++;
                n /= primes[i];
            }

            if (cnt > 1)
            {
                return -1;
            }
            if (cnt == 1)
            {
                mask |= (1 << i);
            }
        }

        return mask;
    }

    long long power(long long base, long long exp)
    {
        long long ans = 1;
        while (exp)
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

    int countSubsets(vector<int> &arr)
    {
        vector<int> freq(31, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }

        int ones = freq[1];
        vector<long long> dp(1024, 0);
        dp[0] = 1;

        for (int i = 2; i <= 30; i++)
        {
            if (freq[i] == 0)
            {
                continue;
            }

            int current = get_mask(i);
            if (current == -1)
            {
                continue;
            }

            for (int j = 1023; j >= 0; j--)
            {

                if ((j & current) != 0)
                {
                    continue;
                }

                dp[j | current] = (dp[j | current] + dp[j] * freq[i]) % 1000000007;
            }
        }

        long long ans = 0;
        for (int i = 1; i < 1024; i++)
        {
            ans = (ans + dp[i]) % 1000000007;
        }
        ans = (ans * power(2, ones)) % 1000000007;

        return ans;
    }
};