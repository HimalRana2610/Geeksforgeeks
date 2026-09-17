#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCount(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> next(n + 1, vector<int>(n + 1, 0)), current(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int inc = -1; inc < n; inc++)
            {
                for (int dec = -1; dec < n; dec++)
                {
                    int ans = 1 + next[inc + 1][dec + 1];
                    if (inc == -1 || arr[i] > arr[inc])
                    {
                        ans = min(ans, next[i + 1][dec + 1]);
                    }
                    if (dec == -1 || arr[i] < arr[dec])
                    {
                        ans = min(ans, next[inc + 1][i + 1]);
                    }
                    current[inc + 1][dec + 1] = ans;
                }
            }

            next = current;
        }

        return next[0][0];
    }
};