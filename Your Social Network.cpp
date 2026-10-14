#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> socialNetwork(vector<int> &arr)
    {
        int n = arr.size() + 1;
        vector<vector<int>> ans;

        for (int i = 2; i <= n; i++)
        {
            int current = i;
            vector<int> path;

            while (current != 1)
            {
                current = arr[current - 2];
                path.push_back(current);
            }

            int distance = path.size();
            for (int j = path.size() - 1; j >= 0; j--)
            {
                ans.push_back({i, path[j], distance});
                distance--;
            }
        }

        return ans;
    }
};