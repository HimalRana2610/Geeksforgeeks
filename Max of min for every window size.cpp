#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp(n + 1, 0);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                int t = s.top();
                s.pop();

                int left = s.empty() ? -1 : s.top(), right = i;
                int size = right - left - 1;
                temp[size] = max(temp[size], arr[t]);
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int t = s.top();
            s.pop();

            int left = s.empty() ? -1 : s.top(), right = n;
            int size = right - left - 1;
            temp[size] = max(temp[size], arr[t]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = temp[i + 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};