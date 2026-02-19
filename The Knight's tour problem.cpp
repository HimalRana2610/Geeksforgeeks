#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> knightTour(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, -1));
        vector<int> rowMoves = {2, 1, -1, -2, -2, -1, 1, 2};
        vector<int> colMoves = {1, 2, 2, 1, -1, -2, -2, -1};

        function<bool(int, int, int)> backtrack = [&](int row, int col, int moveCount)
        {
            if (moveCount == n * n)
            {
                return true;
            }

            for (int i = 0; i < 8; i++)
            {
                int nextRow = row + rowMoves[i];
                int nextCol = col + colMoves[i];

                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] == -1)
                {
                    board[nextRow][nextCol] = moveCount;
                    if (backtrack(nextRow, nextCol, moveCount + 1))
                    {
                        return true;
                    }
                    board[nextRow][nextCol] = -1;
                }
            }
            return false;
        };

        board[0][0] = 0;
        if (backtrack(0, 0, 1))
        {
            return board;
        }
        else
        {
            return {};
        }
    }
};