#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFreq(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }

        vector<pair<int, int>> freq_arr(freq.begin(), freq.end());
        sort(freq_arr.begin(), freq_arr.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second == b.second ? a.first > b.first : a.second > b.second; });

        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = freq_arr[i].first;
        }

        return ans;
    }
};