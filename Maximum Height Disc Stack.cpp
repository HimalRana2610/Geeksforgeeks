#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int> tree;

public:
    FenwickTree(int n)
    {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value)
    {
        while (index < tree.size())
        {
            tree[index] = max(tree[index], value);
            index += index & -index;
        }
    }

    int query(int index)
    {
        int ans = 0;
        while (index > 0)
        {
            ans = max(ans, tree[index]);
            index -= index & -index;
        }

        return ans;
    }
};

class Solution
{
public:
    int maxStackHeight(vector<int> &r, vector<int> &h)
    {
        int n = r.size();
        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++)
        {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end(), [](auto &a, auto &b)
             { return a.first != b.first ? a.first < b.first : a.second > b.second; });

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            heights.push_back(discs[i].second);
        }

        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        int ans = 0;
        FenwickTree ft(heights.size());

        for (int i = 0; i < n; i++)
        {
            int index = lower_bound(heights.begin(), heights.end(), discs[i].second) - heights.begin() + 1, current = ft.query(index - 1) + discs[i].second;
            ft.update(index, current);
            ans = max(ans, current);
        }

        return ans;
    }
};