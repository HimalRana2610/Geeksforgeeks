#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
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

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};