#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, string s)
    {
        vector<int> state(26, 0);
        int occupied = 0, ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'A';
            if (state[idx] == 0)
            {
                state[idx] = 1;
                if (occupied < n)
                {
                    occupied++;
                    state[idx] = 2;
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                if (state[idx] == 2)
                {
                    occupied--;
                }
                state[idx] = 0;
            }
        }

        return ans;
    }
};