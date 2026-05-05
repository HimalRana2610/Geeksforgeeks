#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubstr(string &s, int k)
    {
        unordered_map<char, int> freq;
        int m = 0, ans = 0, l = 0;

        for (int r = 0; r < s.length(); ++r)
        {
            freq[s[r]]++;
            m = max(m, freq[s[r]]);

            if (r - l + 1 - m > k)
            {
                freq[s[l++]]--;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};