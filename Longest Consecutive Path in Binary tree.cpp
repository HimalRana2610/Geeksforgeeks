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
    void dfs(Node *node, Node *parent, int current, int &ans)
    {
        if (!node)
        {
            return;
        }

        if (parent && node->data == parent->data + 1)
        {
            current++;
        }
        else
        {
            current = 1;
        }

        ans = max(ans, current);
        dfs(node->left, node, current, ans);
        dfs(node->right, node, current, ans);
    }

    int longestConsecutive(Node *root)
    {
        int ans = 0;
        dfs(root, nullptr, 0, ans);

        if (ans == 1)
        {
            return -1;
        }

        return ans;
    }
};