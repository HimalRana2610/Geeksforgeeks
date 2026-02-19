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
    void traverse(Node *node, vector<int> &ans)
    {
        if (!node)
        {
            return;
        }

        traverse(node->left, ans);
        traverse(node->right, ans);
        ans.push_back(node->data);
    }

    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        traverse(root, ans);

        return ans;
    }
};