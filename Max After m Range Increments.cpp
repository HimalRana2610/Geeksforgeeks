#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(int n, vector<int> &a, vector<int> &b, vector<int> &k)
    {
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < a.size(); i++)
        {
            diff[a[i]] += k[i];
            if (b[i] + 1 <= n)
            {
                diff[b[i] + 1] -= k[i];
            }
        }

        int sum = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += diff[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};