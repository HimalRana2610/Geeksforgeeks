#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int overlapInt(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> data;

        for (int i = 0; i < n; i++)
        {
            data.push_back({arr[i][0], 0});
            data.push_back({arr[i][1], 1});
        }

        sort(data.begin(), data.end(), [](vector<int> &a, vector<int> &b)
             { return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] < b[1]); });

        int cnt = 0, ans = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i][1] == 0)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};