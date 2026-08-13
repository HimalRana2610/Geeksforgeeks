#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x], parent);
        }

        return parent[x];
    }

    int minEdgesReq(int n, vector<vector<int>> &edges)
    {
        if (edges.size() < n - 1)
        {
            return -1;
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        vector<int> size(n, 1);
        for (auto &e : edges)
        {
            int ru = find(e[0], parent), rv = find(e[1], parent);
            if (ru == rv)
            {
                continue;
            }
            if (size[ru] < size[rv])
            {
                swap(ru, rv);
            }

            parent[rv] = ru;
            size[ru] += size[rv];
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(i, parent) == i)
            {
                components++;
            }
        }

        return components - 1;
    }
};