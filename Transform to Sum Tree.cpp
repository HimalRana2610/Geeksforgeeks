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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int dfs(Node *node)
    {
        if (!node)
        {
            return 0;
        }

        int old = node->data;
        node->data = dfs(node->left) + dfs(node->right);

        return old + node->data;
    }

    void toSumTree(Node *root)
    {
        dfs(root);
    }
};