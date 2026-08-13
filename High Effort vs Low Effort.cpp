#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTask(vector<int> &h, vector<int> &l)
    {
        int n = h.size();
        if (n == 0)
        {
            return 0;
        }

        int prev1 = max(h[0], l[0]);
        if (n == 1)
        {
            return prev1;
        }

        int curr = max(h[1], l[1] + prev1), prev2 = prev1;
        prev1 = curr;

        for (int i = 2; i < n; i++)
        {
            curr = max(l[i] + prev1, h[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};