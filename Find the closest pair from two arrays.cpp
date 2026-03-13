#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        int n = arr1.size(), m = arr2.size(), diff = INT_MAX;
        vector<int> ans(2);

        for (int i = 0, j = m - 1; i < n && j >= 0;)
        {
            int sum = arr1[i] + arr2[j];
            if (abs(sum - x) < diff)
            {
                diff = abs(sum - x);
                ans[0] = arr1[i];
                ans[1] = arr2[j];
            }

            if (sum > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};