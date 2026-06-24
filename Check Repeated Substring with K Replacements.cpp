#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kSubstr(string &s, int k)
    {
        int n = s.length();
        if (n % k != 0)
        {
            return false;
        }

        unordered_map<string, int> freq;
        int m = 0;

        for (int i = 0; i < n; i += k)
        {
            m = max(m, ++freq[s.substr(i, k)]);
        }

        return (n / k) - m <= 1;
    }
};