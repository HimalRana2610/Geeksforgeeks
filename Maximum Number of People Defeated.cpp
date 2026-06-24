#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPeopleDefeated(int p)
    {
        int ans = 0;
        for (int i = 1;; i++)
        {
            if (i * i <= p)
            {
                ans++;
                p -= i * i;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};