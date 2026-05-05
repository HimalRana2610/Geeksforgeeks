#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        vector<int> ans;
        for (int i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();)
        {
            if (a[i] == b[j] && b[j] == c[k])
            {
                ans.push_back(a[i++]);
                j++;
                k++;

                while (i < a.size() && a[i] == a[i - 1])
                {
                    i++;
                }
                while (j < b.size() && b[j] == b[j - 1])
                {
                    j++;
                }
                while (k < c.size() && c[k] == c[k - 1])
                {
                    k++;
                }
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else if (b[j] < c[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        return ans;
    }
};