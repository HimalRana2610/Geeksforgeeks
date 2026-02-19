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
    void traverse(Node *node, vector<int> &inorder)
    {
        if (!node)
        {
            return;
        }

        traverse(node->left, inorder);
        inorder.push_back(node->data);
        traverse(node->right, inorder);
    }

    int findMedian(Node *root)
    {
        vector<int> inorder;
        traverse(root, inorder);

        return inorder[(inorder.size() - 1) / 2];
    }
};