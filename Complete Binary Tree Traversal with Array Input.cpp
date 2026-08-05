#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelSort(vector<int> &arr)
    {
        int n = arr.size(), level = 0, index = 0;
        vector<vector<int>> ans;

        while (index < n)
        {
            int s = pow(2, level);
            vector<int> current;

            for (int i = 0; i < s && index < n; i++)
            {
                current.push_back(arr[index]);
                index++;
            }

            sort(current.begin(), current.end());
            ans.push_back(current);
            level++;
        }

        return ans;
    }
};