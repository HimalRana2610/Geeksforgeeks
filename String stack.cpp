#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stringStack(string &pat, string &tar)
    {
        int j = tar.size() - 1;
        for (int i = pat.size() - 1; i >= 0 && j >= 0; i--)
        {
            if (pat[i] != tar[j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        return j < 0;
    }
};