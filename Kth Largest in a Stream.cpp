#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            if (pq.size() < k)
            {
                pq.push(arr[i]);
            }
            else if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }

            if (pq.size() == k)
            {
                ans.push_back(pq.top());
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};