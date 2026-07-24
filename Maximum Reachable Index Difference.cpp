#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIndexDifference(string &s)
    {
        int n = s.size(), ans = -1;
        vector<int> best(26, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            int farthest = i;
            if (s[i] != 'z' && best[s[i] - 'a' + 1] != -1)
            {
                farthest = best[s[i] - 'a' + 1];
            }

            best[s[i] - 'a'] = max(best[s[i] - 'a'], farthest);
            if (s[i] == 'a')
            {
                ans = max(ans, farthest - i);
            }
        }

        return ans;
    }
};