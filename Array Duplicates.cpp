#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        int n = arr.size();
        vector<bool> visited(n + 1, false);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (visited[arr[i]])
            {
                ans.push_back(arr[i]);
            }
            visited[arr[i]] = true;
        }

        return ans;
    }
};