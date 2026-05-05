#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string s)
    {
        int n = s.size(), ans = INT_MAX;
        unordered_map<char, int> freq;

        for (int i = 0, j = 0; j < n; j++)
        {
            freq[s[j]]++;
            while (freq['0'] > 0 && freq['1'] > 0 && freq['2'] > 0)
            {
                ans = min(ans, j - i + 1);
                freq[s[i++]]--;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};