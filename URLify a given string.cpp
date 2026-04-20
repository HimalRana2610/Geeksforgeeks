#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string URLify(string &s)
    {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                ans += "%20";
            }
            else
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};