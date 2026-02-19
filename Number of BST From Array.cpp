#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBSTs(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> sorted(n);

        for (int i = 0; i < n; i++)
        {
            sorted[i] = {arr[i], i};
        }

        sort(sorted.begin(), sorted.end());
        vector<int> fact(2 * n + 1, 1);

        for (int i = 1; i <= 2 * n; i++)
        {
            fact[i] = (fact[i - 1] * i);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[sorted[i].second] = (fact[2 * i] / (fact[i] * fact[i + 1])) * (fact[2 * (n - i - 1)] / (fact[n - i] * fact[n - i - 1]));
        }

        return ans;
    }
};