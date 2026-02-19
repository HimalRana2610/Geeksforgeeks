#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unionf(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
        {
            return;
        }

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    int minConnect(int V, vector<vector<int>> &edges)
    {
        int m = edges.size();
        if (m < V - 1)
        {
            return -1;
        }

        UnionFind uf(V);
        int components = V, redundant = 0;

        for (int i = 0; i < m; i++)
        {
            if (edges[i].size() < 2)
            {
                continue;
            }

            int u = edges[i][0], v = edges[i][1];
            int pu = uf.find(u), pv = uf.find(v);

            if (pu != pv)
            {
                uf.unionf(pu, pv);
                components--;
            }
            else
            {
                redundant++;
            }
        }

        int needed = components - 1;
        if (redundant >= needed)
        {
            return needed;
        }

        return -1;
    }
};