#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k)
    {
        auto compare = [](pair<int, int> a, pair<int, int> b)
        {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        int i = 0;

        while (i < arr.size())
        {
            if (pq.empty())
            {
                pq.push({arr[i++], 1});
            }
            else
            {
                pair<int, int> top = pq.top();
                if (top.first == arr[i])
                {
                    pq.push({arr[i++], 1});
                }
                else if (top.first + 1 == arr[i])
                {
                    pq.pop();
                    pq.push({arr[i++], top.second + 1});
                }
                else
                {
                    if (top.second < k)
                    {
                        return false;
                    }
                    pq.pop();
                }
            }
        }

        while (!pq.empty())
        {
            if (pq.top().second < k)
            {
                return false;
            }
            pq.pop();
        }

        return true;
    }
};