#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    long long n;
    vector<long long> tree, arr;

    long long lcm(long long a, long long b)
    {
        return (a / __gcd(a, b)) * b;
    }

    void build(long long node, long long start, long long end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        long long mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(vector<long long> input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(long long node, long long start, long long end, long long idx, long long val)
    {
        if (start == end)
        {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        long long mid = (start + end) / 2;
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(long long node, long long start, long long end, long long l, long long r)
    {
        if (end < l || start > r)
        {
            return 1;
        }

        if (l <= start && end <= r)
        {
            return tree[node];
        }

        long long mid = (start + end) / 2;
        return lcm(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }
};

class Solution
{
public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<long long> arrl(arr.begin(), arr.end());
        SegmentTree st(arrl);
        vector<long long> ans;

        for (long long i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 1)
            {
                st.update(1, 0, arr.size() - 1, queries[i][1], queries[i][2]);
            }
            else
            {
                ans.push_back(st.query(1, 0, arr.size() - 1, queries[i][1], queries[i][2]));
            }
        }

        return ans;
    }
};