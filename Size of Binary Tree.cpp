#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
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

        return 1 + dfs(node->left) + dfs(node->right);
    }

    int getSize(Node *root)
    {
        return dfs(root);
    }
};