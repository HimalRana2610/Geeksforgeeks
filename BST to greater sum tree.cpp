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
    void dfs(Node *node, int &sum)
    {
        if (!node)
        {
            return;
        }

        dfs(node->right, sum);
        sum += node->data;
        node->data = sum - node->data;
        dfs(node->left, sum);
    }

    void transformTree(Node *root)
    {
        int sum = 0;
        dfs(root, sum);
    }
};