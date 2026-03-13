#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areIsomorphic(string &s1, string &s2)
    {
        unordered_map<char, char> mp;
        unordered_set<char> mapped;

        for (int i = 0; i < s1.length(); ++i)
        {
            if (mp.find(s1[i]) != mp.end())
            {
                if (mp[s1[i]] != s2[i])
                {
                    return false;
                }
            }
            else
            {
                if (mapped.find(s2[i]) != mapped.end())
                {
                    return false;
                }

                mp[s1[i]] = s2[i];
                mapped.insert(s2[i]);
            }
        }

        return true;
    }
};