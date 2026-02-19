#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(vector<int> &ranks, int n, int time)
    {
        int total = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            total += int((sqrt(1.0 + 8.0 * time / ranks[i]) - 1.0) / 2.0);
            if (total >= n)
            {
                return true;
            }
        }

        return false;
    }

    int minTime(vector<int> &ranks, int n)
    {
        int low = 0, high = *min_element(ranks.begin(), ranks.end()) * n * (n + 1) / 2;
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (is_valid(ranks, n, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};