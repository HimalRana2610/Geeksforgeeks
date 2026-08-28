#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int transform(string &s1, string &s2)
    {
        if (s1.length() != s2.length())
        {
            return -1;
        }

        int n = s1.length();
        unordered_map<char, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[s1[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq.count(s2[i]))
            {
                freq[s2[i]]--;
            }
        }

        for (auto &f : freq)
        {
            if (f.second != 0)
            {
                return -1;
            }
        }

        int ans = 0;
        for (int i = n - 1, j = n - 1; i >= 0 && j >= 0; i--, j--)
        {
            while (i >= 0 && s1[i] != s2[j])
            {
                ans++;
                i--;
            }
        }

        return ans;
    }
};