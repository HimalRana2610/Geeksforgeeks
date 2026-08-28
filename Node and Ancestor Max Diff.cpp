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
        left = right = nullptr;
    }
};

class Solution
{
public:
    int dfs(Node *node, int &ans)
    {
        if (!node)
        {
            return INT_MAX;
        }

        if (!node->left && !node->right)
        {
            return node->data;
        }

        int val = min(dfs(node->left, ans), dfs(node->right, ans));
        ans = max(ans, node->data - val);

        return min(val, node->data);
    }

    int maxDiff(Node *root)
    {
        int ans = INT_MIN;
        dfs(root, ans);

        return ans;
    }
};