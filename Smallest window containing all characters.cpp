#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestWindow(string &s, string &p)
    {
        unordered_map<char, int> need, window;

        for (int i = 0; i < p.length(); i++)
        {
            need[p[i]]++;
        }

        int have = 0, cnt = need.size(), left = 0, ans = INT_MAX, start = 0;
        for (int right = 0; right < s.length(); right++)
        {
            window[s[right]]++;
            if (need.count(s[right]) && window[s[right]] == need[s[right]])
            {
                have++;
            }

            while (have == cnt)
            {
                if (right - left + 1 < ans)
                {
                    ans = right - left + 1;
                    start = left;
                }

                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]])
                {
                    have--;
                }
                left++;
            }
        }

        if (ans == INT_MAX)
        {
            return "";
        }

        return s.substr(start, ans);
    }
};