#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int ans = 0;

        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            ans += first + second;
            pq.push(first + second);
        }

        return ans;
    }
};