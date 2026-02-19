#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
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
            return 0;
        }

        int l = dfs(node->left, ans), r = dfs(node->right, ans);
        ans += abs(l) + abs(r);

        return node->data + l + r - 1;
    }

    int distCandy(Node *root)
    {
        int ans = 0;
        dfs(root, ans);

        return ans;
    }
};