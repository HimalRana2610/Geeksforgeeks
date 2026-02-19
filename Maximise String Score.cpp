#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string &s, vector<vector<char>> &jumps)
    {
        int n = s.length();
        if (n == 0)
        {
            return 0;
        }

        unordered_map<char, unordered_set<char>> mp;
        for (int i = 0; i < jumps.size(); i++)
        {
            mp[jumps[i][0]].insert(jumps[i][1]);
        }

        unordered_set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (long long)(unsigned char)s[i];
        }

        unordered_map<char, vector<int>> prefix_cnt;
        prefix_cnt.reserve(st.size() * 2);

        for (char ch : st)
        {
            vector<int> arr(n + 1, 0);
            for (int i = 0; i < n; i++)
            {
                arr[i + 1] = arr[i] + (s[i] == ch ? 1 : 0);
            }
            prefix_cnt.emplace(ch, move(arr));
        }

        vector<long long> dp(n + 1, 0);
        unordered_map<char, long long> best;
        best.reserve(st.size() * 2);

        for (char ch : st)
        {
            best[ch] = LLONG_MIN;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            long long ans = 0;
            unordered_set<char> allowed;

            auto it = mp.find(s[i]);
            if (it != mp.end())
            {
                allowed = it->second;
            }
            allowed.insert(s[i]);

            for (char t : allowed)
            {
                auto itcnt = prefix_cnt.find(t);
                if (itcnt == prefix_cnt.end())
                {
                    continue;
                }

                long long bv = best[t];
                if (bv == LLONG_MIN)
                {
                    continue;
                }

                long long candidate = bv - (prefix[i] - (long long)(unsigned char)t * (long long)itcnt->second[i]);
                if (candidate > ans)
                {
                    ans = candidate;
                }
            }
            dp[i] = ans;

            long long A_i = prefix[i] - (long long)(unsigned char)s[i] * (long long)prefix_cnt[s[i]][i] + dp[i];
            auto itb = best.find(s[i]);

            if (itb == best.end() || A_i > itb->second)
            {
                best[s[i]] = A_i;
            }
        }

        return (int)dp[0];
    }
};