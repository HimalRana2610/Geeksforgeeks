#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstring(string &s)
    {
        int n = s.length(), zero = n, minus = 0, ans = 0, current = zero;
        vector<int> mp(2 * n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                current--;
            }
            else
            {
                current++;
            }

            if (current <= zero)
            {
                minus++;
            }

            mp[current]++;
        }

        for (int i = 0; i < n; i++)
        {
            ans += (n - i - minus);
            if (s[i] == '1')
            {
                mp[++zero]--;
                minus += mp[zero];
            }
            else
            {
                mp[--zero]--;
                minus--;
                minus -= mp[zero + 1];
            }
        }

        return ans;
    }
};