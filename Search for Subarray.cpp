#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        vector<int> lps(m, 0);

        int l = 0, i = 1;
        while (i < m)
        {
            if (b[i] == b[l])
            {
                lps[i++] = ++l;
            }
            else
            {
                if (l != 0)
                {
                    l = lps[l - 1];
                }
                else
                {
                    lps[i++] = 0;
                }
            }
        }

        i = 0;
        int j = 0;
        vector<int> ans;

        while (i < n)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;

                if (j == m)
                {
                    ans.push_back(i - j);
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return ans;
    }
};