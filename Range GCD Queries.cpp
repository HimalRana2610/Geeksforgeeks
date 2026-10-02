#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = __gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {
                update(2 * node + 1, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = __gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_gcd = query(2 * node + 1, start, mid, l, r);
        int right_gcd = query(2 * node + 2, mid + 1, end, l, r);
        return __gcd(left_gcd, right_gcd);
    }
};

class Solution
{
public:
    vector<int> processQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        SegmentTree st(arr);
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
            {
                ans.push_back(st.query(0, 0, arr.size() - 1, queries[i][1], queries[i][2]));
            }
            else
            {
                st.update(0, 0, arr.size() - 1, queries[i][1], queries[i][2]);
            }
        }

        return ans;
    }
};