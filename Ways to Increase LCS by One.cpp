#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> pos(26);

        for (int i = 1; i <= m; i++)
        {
            pos[s2[i - 1] - 'a'].push_back(i);
        }

        vector<vector<int>> left(n + 2, vector<int>(m + 2, 0)), right(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    left[i][j] = 1 + left[i - 1][j - 1];
                }
                else
                {
                    left[i][j] = max(left[i - 1][j], left[i][j - 1]);
                }
            }
        }

        for (int i = n; i >= 1; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    right[i][j] = 1 + right[i + 1][j + 1];
                }
                else
                {
                    right[i][j] = max(right[i + 1][j], right[i][j + 1]);
                }
            }
        }

        int base = left[n][m], ans = 0;
        for (int i = 0; i <= n; i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                for (int j = 0; j < pos[ch - 'a'].size(); j++)
                {
                    int p = pos[ch - 'a'][j];
                    if (left[i][p - 1] + right[i + 1][p + 1] == base)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};