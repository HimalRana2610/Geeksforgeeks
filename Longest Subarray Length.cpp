#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> temp(n, n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                temp[i] = s.top();
            }

            s.push(i);
        }

        while (!s.empty())
        {
            s.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                t = s.top();
            }

            s.push(i);
            int l = temp[i] - t - 1;

            if (l >= arr[i])
            {
                ans = max(ans, l);
            }
        }

        return ans;
    }
};