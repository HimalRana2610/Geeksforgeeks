#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &maze, int n, int x, int y, string current, vector<vector<bool>> &visited, vector<string> &ans)
    {
        if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || visited[x][y])
        {
            return;
        }

        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(current);
            return;
        }

        visited[x][y] = true;
        dfs(maze, n, x + 1, y, current + 'D', visited, ans);
        dfs(maze, n, x - 1, y, current + 'U', visited, ans);
        dfs(maze, n, x, y + 1, current + 'R', visited, ans);
        dfs(maze, n, x, y - 1, current + 'L', visited, ans);
        visited[x][y] = false;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> ans;

        dfs(maze, n, 0, 0, "", visited, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
};