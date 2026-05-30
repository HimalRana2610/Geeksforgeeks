#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double det(vector<vector<double>> mat, int n)
    {
        double ans = 1.0;
        for (int i = 0; i < n; i++)
        {
            int pivot = i;
            for (int j = i + 1; j < n; j++)
            {
                if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                {
                    pivot = j;
                }
            }

            if (fabs(mat[pivot][i]) < 1e-9)
            {
                return 0;
            }

            if (i != pivot)
            {
                swap(mat[i], mat[pivot]);
                ans *= -1;
            }

            ans *= mat[i][i];
            for (int j = i + 1; j < n; j++)
            {
                double factor = mat[j][i] / mat[i][i];
                for (int k = i; k < n; k++)
                {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return ans;
    }

    int countSpanTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]][edges[i][1]] = true;
            graph[edges[i][1]][edges[i][0]] = true;
        }

        vector<vector<double>> L(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            int degree = 0;
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j])
                {
                    degree++;
                    if (i != j)
                    {
                        L[i][j] = -1;
                    }
                }
            }
            L[i][i] = degree;
        }

        vector<vector<double>> minor(n - 1, vector<double>(n - 1));
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                minor[i][j] = L[i][j];
            }
        }

        return (int)round(det(minor, n - 1));
    }
};