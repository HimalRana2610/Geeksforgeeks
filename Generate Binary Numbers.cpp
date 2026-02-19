#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateBinary(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(bitset<32>(i).to_string().substr(bitset<32>(i).to_string().find('1')));
        }

        return ans;
    }
};