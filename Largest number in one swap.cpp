#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestSwap(string &s)
    {
        int n = s.length();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int m = INT_MIN, index = -1;
            for (auto &f : freq)
            {
                if (f.first > s[i] - '0' && f.first > m && f.second > i)
                {
                    m = f.first;
                    index = f.second;
                }
            }

            if (index != -1)
            {
                swap(s[i], s[index]);
                return s;
            }
        }

        return s;
    }
};