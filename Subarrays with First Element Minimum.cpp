#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[i] <= arr[s.top()])
            {
                s.pop();
            }

            ans += s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        return ans;
    }
};