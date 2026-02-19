#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({arr1[0] + arr2[0], 0, 0});

        set<vector<int>> s;
        s.insert({0, 0});

        vector<vector<int>> ans;
        bool flag = true;

        for (int i = 0; i < k && flag; i++)
        {
            int x = pq.top()[1], y = pq.top()[2];
            pq.pop();

            ans.push_back({arr1[x], arr2[y]});
            flag = false;

            if (x + 1 < arr1.size())
            {
                vector<int> current = {x + 1, y};
                if (s.find(current) == s.end())
                {
                    pq.push({arr1[x + 1] + arr2[y], x + 1, y});
                    s.insert(current);
                }
                flag = true;
            }

            if (y + 1 < arr2.size())
            {
                vector<int> current = {x, y + 1};
                if (s.find(current) == s.end())
                {
                    pq.push({arr1[x] + arr2[y + 1], x, y + 1});
                    s.insert(current);
                }
                flag = true;
            }
        }

        return ans;
    }
};