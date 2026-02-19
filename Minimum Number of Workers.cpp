#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMen(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> range;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                int left = max(0, i - arr[i]), right = min(n - 1, i + arr[i]);
                range.push_back({left, right});
            }
        }

        if (range.empty())
        {
            return -1;
        }

        sort(range.begin(), range.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first); });

        int ans = 0, i = 0, m = -1;
        while (m < n - 1)
        {
            if (i >= (int)range.size())
            {
                return -1;
            }

            if (range[i].first > m + 1)
            {
                return -1;
            }

            int best = m;
            while (i < (int)range.size() && range[i].first <= m + 1)
            {
                best = max(best, range[i].second);
                i++;
            }

            ans++;
            m = best;
        }

        return ans;
    }
};