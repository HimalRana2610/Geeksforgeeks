#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length)
    {
        int n = height.size();
        vector<vector<int>> boxes;

        for (int i = 0; i < n; i++)
        {
            int a = height[i], b = width[i], c = length[i];
            boxes.push_back({a, b, c});
            boxes.push_back({a, c, b});
            boxes.push_back({b, a, c});
            boxes.push_back({b, c, a});
            boxes.push_back({c, a, b});
            boxes.push_back({c, b, a});
        }

        sort(boxes.begin(), boxes.end(), [](vector<int> &box1, vector<int> &box2)
             { return box1[0] == box2[0] ? (box1[1] == box2[1] ? box1[2] > box2[2] : box1[1] > box2[1]) : box1[0] > box2[0]; });

        int ans = 0;
        vector<int> dp(n * 6);

        for (int i = n * 6 - 1; i >= 0; i--)
        {
            dp[i] = boxes[i][2];
            for (int j = i + 1; j < boxes.size(); j++)
            {
                if (boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1])
                {
                    dp[i] = max(dp[i], boxes[i][2] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};