#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubSeq(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length();
        if (n > m)
        {
            return false;
        }

        int j = 0;
        for (int i = 0; i < m && j < n; i++)
        {
            if (s2[i] == s1[j])
            {
                j++;
            }
        }

        return j == n;
    }
};