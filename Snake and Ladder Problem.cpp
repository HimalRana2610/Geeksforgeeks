#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minThrows(int n, vector<int> &lad, vector<int> &sn)
    {
        vector<int> moves(n * n + 1, -1);
        for (int i = 0; i < lad.size(); i += 2)
        {
            moves[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < sn.size(); i += 2)
        {
            moves[sn[i]] = sn[i + 1];
        }

        queue<pair<int, int>> q;
        q.push({1, 0});

        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        pair<int, int> current;
        while (!q.empty())
        {
            current = q.front();
            q.pop();

            int pos = current.first, dist = current.second;
            if (pos == n * n)
            {
                return dist;
            }

            for (int nxt = pos + 1; nxt <= pos + 6 && nxt <= n * n; nxt++)
            {
                if (!visited[nxt])
                {
                    visited[nxt] = true;
                    int dest = (moves[nxt] == -1) ? nxt : moves[nxt];
                    q.push({dest, dist + 1});
                }
            }
        }

        return -1;
    }
};