#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool prefers(vector<vector<int>> &women, int w, int m, int m1)
    {
        for (int i = 0; i < women[w].size(); i++)
        {
            if (women[w][i] == m)
            {
                return true;
            }
            if (women[w][i] == m1)
            {
                return false;
            }
        }

        return false;
    }

    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
    {
        int n = men.size();
        vector<int> wPartner(n, -1), mPartner(n, -1), next(n, 0);
        vector<bool> freeMan(n, true);

        int freeCount = n;
        while (freeCount > 0)
        {
            int m;
            for (m = 0; m < n; m++)
            {
                if (freeMan[m])
                {
                    break;
                }
            }

            int w = men[m][next[m]];
            next[m]++;

            if (wPartner[w] == -1)
            {
                wPartner[w] = m;
                mPartner[m] = w;
                freeMan[m] = false;
                freeCount--;
            }
            else
            {
                int m1 = wPartner[w];
                if (prefers(women, w, m, m1))
                {
                    wPartner[w] = m;
                    mPartner[m] = w;
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }

        return mPartner;
    }
};