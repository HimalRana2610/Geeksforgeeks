#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        for (int i = 0, j = 0; i < a.size() && j < b.size();)
        {
            if (a[i] == b[j])
            {
                if (ans.empty() || ans.back() != a[i])
                {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }
};