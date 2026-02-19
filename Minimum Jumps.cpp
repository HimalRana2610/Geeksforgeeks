#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (arr[0] == 0)
        {
            return -1;
        }

        int ans = 0, current = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + arr[i]);
            if (i == current)
            {
                ans++;
                current = farthest;

                if (current <= i)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};