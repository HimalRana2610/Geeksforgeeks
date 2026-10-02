#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLongestWord(string &s, vector<string> &d)
    {
        int n = s.length();
        vector<vector<int>> next(n + 1, vector<int>(26, -1));

        for (int i = n - 1; i >= 0; i--)
        {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }

        string ans = "";
        for (int i = 0; i < d.size(); i++)
        {
            int pos = 0;
            bool is_possible = true;

            for (int j = 0; j < d[i].length(); j++)
            {
                if (pos > n)
                {
                    is_possible = false;
                    break;
                }

                int p = next[pos][d[i][j] - 'a'];
                if (p == -1)
                {
                    is_possible = false;
                    break;
                }
                pos = p + 1;
            }

            if (is_possible)
            {
                if (d[i].length() > ans.length() || (d[i].length() == ans.length() && d[i] < ans))
                {
                    ans = d[i];
                }
            }
        }

        return ans;
    }
};