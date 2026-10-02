#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void root(vector<vector<int>> &adj, string &s, vector<vector<int>> &sa, int node = 0, int parent = -1)
    {
        int ra = 0, ba = 0;
        for (auto &neighbour : adj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }

            root(adj, s, sa, neighbour, node);
            ra = max(ra, sa[neighbour][0]);
            ra = max(ra, sa[neighbour][1]);
            ba = max(ba, sa[neighbour][1]);
        }

        if (s[node] == 'R')
        {
            sa[node][0] = ra + 1;
            sa[node][1] = 0;
        }
        else
        {
            sa[node][0] = ba + 1;
            sa[node][1] = ba + 1;
        }
    }

    void reroot(vector<vector<int>> &adj, string &s, vector<vector<int>> &ans, vector<vector<int>> &sa, int node = 0, int parent = -1, int red_parent = 0, int blue_parent = 0)
    {
        if (s[node] == 'R')
        {
            ans[node][0] = max(sa[node][0], 1 + red_parent);
            ans[node][1] = 0;
        }
        else
        {
            ans[node][0] = max(sa[node][0], 1 + blue_parent);
            ans[node][1] = max(sa[node][1], 1 + blue_parent);
        }

        int fr = red_parent, sr = red_parent, fb = blue_parent, sb = blue_parent;
        for (auto &neighbour : adj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }

            if (sa[neighbour][0] > fr)
            {
                sr = fr;
                fr = sa[neighbour][0];
            }
            else if (sa[neighbour][0] > sr)
            {
                sr = sa[neighbour][0];
            }

            if (sa[neighbour][1] > fb)
            {
                sb = fb;
                fb = sa[neighbour][1];
            }
            else if (sa[neighbour][1] > sb)
            {
                sb = sa[neighbour][1];
            }
        }

        for (auto &neighbour : adj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }

            int new_red = 0, new_blue = 0;
            if (s[node] == 'R')
            {
                new_red = 1;
                if (sa[neighbour][0] == fr)
                {
                    new_red += sr;
                }
                else
                {
                    new_red += fr;
                }
                new_blue = 0;
            }
            else
            {
                new_red = 1;
                if (sa[neighbour][1] == fb)
                {
                    new_red += sb;
                }
                else
                {
                    new_red += fb;
                }
                new_blue = new_red;
            }

            reroot(adj, s, ans, sa, neighbour, node, new_red, new_blue);
        }
    }

    int longestPath(string &s, vector<vector<int>> &edges)
    {
        int n = s.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        vector<vector<int>> sub_ans(n, vector<int>(2));
        root(adj, s, sub_ans);

        vector<vector<int>> ans(n, vector<int>(2));
        reroot(adj, s, ans, sub_ans);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max({res, ans[i][0], ans[i][1]});
        }

        return res;
    }
};