#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findPrefixes(vector<string> &arr)
    {
        unordered_map<string, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 1; j <= arr[i].length(); j++)
            {
                freq[arr[i].substr(0, j)]++;
            }
        }

        vector<string> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 1; j <= arr[i].length(); j++)
            {
                string prefix = arr[i].substr(0, j);
                if (freq[prefix] == 1)
                {
                    ans.push_back(prefix);
                    break;
                }
            }

            if (ans.size() < i + 1)
            {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};