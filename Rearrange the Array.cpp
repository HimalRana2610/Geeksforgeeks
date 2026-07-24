#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long modPow(int x, int y)
    {
        long long ans = 1;
        while (y)
        {
            if (y & 1)
            {
                ans = (ans * x) % 1000000007;
            }

            x = (1LL * x * x) % 1000000007;
            y >>= 1;
        }

        return ans;
    }

    int minOperations(vector<int> &b)
    {
        int n = b.size();
        vector<bool> visited(n, false);
        vector<int> cycles;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int l = 0, current = i;
                while (!visited[current])
                {
                    visited[current] = true;
                    current = b[current] - 1;
                    l++;
                }
                cycles.push_back(l);
            }
        }

        vector<int> spf(n + 1);
        for (int i = 0; i <= n; i++)
        {
            spf[i] = i;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        unordered_map<int, int> m;
        for (int i = 0; i < cycles.size(); i++)
        {
            unordered_map<int, int> freq;
            while (cycles[i] > 1)
            {
                int p = spf[cycles[i]], cnt = 0;
                while (cycles[i] % p == 0)
                {
                    cycles[i] /= p;
                    cnt++;
                }
                freq[p] = cnt;
            }

            for (auto &f : freq)
            {
                m[f.first] = max(m[f.first], f.second);
            }
        }

        long long ans = 1;
        for (auto &i : m)
        {
            ans = (ans * modPow(i.first, i.second)) % 1000000007;
        }

        return ans;
    }
};