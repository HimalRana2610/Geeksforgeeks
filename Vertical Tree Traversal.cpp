#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        unordered_map<int, vector<int>> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *node = q.front().first;
                int current = q.front().second;
                q.pop();

                mp[current].push_back(node->data);
                if (node->left)
                {
                    q.push({node->left, current - 1});
                }
                if (node->right)
                {
                    q.push({node->right, current + 1});
                }
            }
        }

        vector<pair<int, vector<int>>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](pair<int, vector<int>> &a, pair<int, vector<int>> &b)
             { return a.first < b.first; });

        vector<vector<int>> ans;
        for (int i = 0; i < vec.size(); i++)
        {
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};