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
    void inorder(Node *node, Node *&prev, int &ans)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, prev, ans);
        if (prev)
        {
            ans = min(ans, node->data - prev->data);
        }

        prev = node;
        inorder(node->right, prev, ans);
    }

    int absDiff(Node *root)
    {
        Node *prev = nullptr;
        int ans = INT_MAX;

        inorder(root, prev, ans);
        return ans;
    }
};