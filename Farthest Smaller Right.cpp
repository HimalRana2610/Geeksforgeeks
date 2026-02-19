#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> farMin(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> suffix(n);
        suffix[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = min(arr[i], suffix[i + 1]);
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            if (suffix[i + 1] >= arr[i])
            {
                continue;
            }

            int left = i + 1, right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (suffix[mid] < arr[i])
                {
                    ans[i] = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return ans;
    }
};