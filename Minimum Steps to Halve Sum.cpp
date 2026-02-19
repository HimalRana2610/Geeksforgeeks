#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &arr)
    {
        priority_queue<double> pq;
        double total = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i];
            pq.push((double)arr[i]);
        }

        double current = total;
        int ans = 0;

        while (current > total / 2)
        {
            double top = pq.top();
            pq.pop();
            current -= top / 2;
            pq.push(top / 2);
            ans++;
        }

        return ans;
    }
};