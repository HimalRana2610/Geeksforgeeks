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
    void traverse(Node *root, vector<int> &inorder)
    {
        if (!root)
        {
            return;
        }

        traverse(root->left, inorder);
        inorder.push_back(root->data);
        traverse(root->right, inorder);
    }

    int kthSmallest(Node *root, int k)
    {
        vector<int> inorder;
        traverse(root, inorder);

        if (k > inorder.size())
        {
            return -1;
        }

        return inorder[k - 1];
    }
};