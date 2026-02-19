#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        deque<int> ma, mi;
        pair<int, int> m = {0, 0};

        int n = arr.size(), i = 0;
        for (int j = 0; j < n; j++)
        {
            while (!ma.empty() && arr[ma.back()] < arr[j])
            {
                ma.pop_back();
            }
            ma.push_back(j);

            while (!mi.empty() && arr[mi.back()] > arr[j])
            {
                mi.pop_back();
            }
            mi.push_back(j);

            while (arr[ma.front()] - arr[mi.front()] > x)
            {
                i++;
                if (ma.front() < i)
                {
                    ma.pop_front();
                }
                if (mi.front() < i)
                {
                    mi.pop_front();
                }
            }

            if (j - i + 1 > m.second)
            {
                m = {i, j - i + 1};
            }
        }

        return vector<int>(arr.begin() + m.first, arr.begin() + m.first + m.second);
    }
};