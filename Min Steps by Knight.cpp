#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
    {
        if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1])
        {
            return 0;
        }

        int steps = 0;
        vector<pair<int, int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        queue<pair<int, int>> q;
        q.push({knightPos[0], knightPos[1]});

        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        visited[knightPos[0]][knightPos[1]] = true;

        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                if (x == targetPos[0] && y == targetPos[1])
                {
                    return steps;
                }

                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dirs[i].first, ny = y + dirs[i].second;
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};