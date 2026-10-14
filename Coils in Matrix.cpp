#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> formCoils(int n)
    {
        int m = 8 * n * n;
        vector<int> coil1(m), coil2(m);
        coil1[0] = 8 * n * n + 2 * n;

        int current = coil1[0], flag = 1, step = 2, index = 1;
        while (index < m)
        {
            for (int i = 0; i < step && index < m; i++)
            {
                current = coil1[index++] = current - 4 * n * flag;
            }

            for (int i = 0; i < step && index < m; i++)
            {
                current = coil1[index++] = current + flag;
            }

            flag *= -1;
            step += 2;
        }

        for (int i = 0; i < m; i++)
        {
            coil2[i] = 16 * n * n + 1 - coil1[i];
        }

        reverse(coil1.begin(), coil1.end());
        reverse(coil2.begin(), coil2.end());

        return {coil2, coil1};
    }
};