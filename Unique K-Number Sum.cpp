#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int sum, vector<int> current, int n, int k, vector<vector<int>> &ans)
    {
        if (current.size() == k && sum == n)
        {
            ans.push_back(current);
            return;
        }
        if (current.size() > k || sum > n)
        {
            return;
        }

        for (int j = i + 1; j <= 9; j++)
        {
            current.push_back(j);
            dfs(j, sum + j, current, n, k, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, i, {i}, n, k, ans);
        }

        return ans;
    }
};