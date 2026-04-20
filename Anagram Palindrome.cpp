#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFormPalindrome(string &s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int odd = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                odd++;
                if (odd == 2)
                {
                    return false;
                }
            }
        }

        return true;
    }
};