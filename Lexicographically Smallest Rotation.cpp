#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lexiString(string &s)
    {
        int n = s.length(), i = 0, j = 1, k = 0;
        s += s;

        while (i < n && j < n && k < n)
        {
            if (s[i + k] == s[j + k])
            {
                k++;
            }
            else if (s[i + k] > s[j + k])
            {
                i = i + k + 1;
                if (i <= j)
                {
                    i = j + 1;
                }
                k = 0;
            }
            else
            {
                j = j + k + 1;
                if (j <= i)
                {
                    j = i + 1;
                }
                k = 0;
            }
        }

        return s.substr(min(i, j), n);
    }
};