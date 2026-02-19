#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size(), start = -1, ml = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[0])
            {
                int j = 0, k = i;
                for (; j < m && k < n; k++)
                {
                    if (s1[k] == s2[j])
                    {
                        j++;
                    }
                }

                if (j == m)
                {
                    int end = k - 1;
                    j = m - 1;

                    for (; j >= 0; end--)
                    {
                        if (s1[end] == s2[j])
                        {
                            j--;
                        }
                    }
                    end++;

                    if (ml > (k - end))
                    {
                        ml = k - end;
                        start = end;
                    }
                }
            }
        }

        if (start == -1)
        {
            return "";
        }

        return s1.substr(start, ml);
    }
};