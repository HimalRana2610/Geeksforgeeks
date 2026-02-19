#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<vector<int>> &jobs)
    {
        sort(jobs.begin(), jobs.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;

        for (int i = 0; i < jobs.size(); i++)
        {
            int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
            while (!pq.empty() && pq.top().first <= start)
            {
                ans = max(ans, pq.top().second);
                pq.pop();
            }
            pq.push({end, profit + ans});
        }

        while (!pq.empty())
        {
            ans = max(ans, pq.top().second);
            pq.pop();
        }

        return ans;
    }
};