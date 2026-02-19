#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int odd = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 != 0)
            {
                odd++;
            }

            if (freq.find(odd - k) != freq.end())
            {
                ans += freq[odd - k];
            }

            freq[odd]++;
        }

        return ans;
    }
};