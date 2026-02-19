#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubs(string &s)
    {
        int n = s.size();
        vector<int> suffix(n), rank(n);

        for (int i = 0; i < n; i++)
        {
            suffix[i] = i;
            rank[i] = s[i];
        }

        vector<int> temp(n);
        for (int i = 1; i < n; i <<= 1)
        {
            auto cmp = [&](int a, int b)
            {
                if (rank[a] != rank[b])
                {
                    return rank[a] < rank[b];
                }

                int rankA = (a + i < n) ? rank[a + i] : -1, rankB = (b + i < n) ? rank[b + i] : -1;
                return rankA < rankB;
            };

            sort(suffix.begin(), suffix.end(), cmp);
            temp[suffix[0]] = 0;

            for (int i = 1; i < n; i++)
            {
                temp[suffix[i]] = temp[suffix[i - 1]] + cmp(suffix[i - 1], suffix[i]);
            }

            rank = temp;
        }

        vector<int> lcp(n, 0);
        for (int i = 0, k = 0; i < n; i++)
        {
            if (rank[i] == n - 1)
            {
                k = 0;
                continue;
            }

            int j = suffix[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
            {
                k++;
            }

            lcp[rank[i]] = k;
            if (k)
            {
                k--;
            }
        }

        return (n * (n + 1) / 2) - accumulate(lcp.begin(), lcp.end(), 0);
    }
};