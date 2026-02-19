#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wildCard(string &txt, string &pat)
    {
        int n = txt.length(), m = pat.length(), i = 0, j = 0, start = -1, match = 0;
        while (i < n)
        {
            if (j < m && (pat[j] == '?' || pat[j] == txt[i]))
            {
                i++;
                j++;
            }
            else if (j < m && pat[j] == '*')
            {
                start = j++;
                match = i;
            }
            else if (start != -1)
            {
                j = start + 1;
                i = ++match;
            }
            else
            {
                return false;
            }
        }

        while (j < m && pat[j] == '*')
        {
            j++;
        }

        return j == m;
    }
};