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
    void traverse(Node *node, int l, int r)
    {
        if (!node)
        {
            return;
        }

        if (node->left && node->left->data < l)
        {
            node->left = node->left->right;
            traverse(node, l, r);
        }
        else if (node->left && node->left->data > r)
        {
            node->left = node->left->left;
            traverse(node, l, r);
        }

        if (node->right && node->right->data > r)
        {
            node->right = node->right->left;
            traverse(node, l, r);
        }
        else if (node->right && node->right->data < l)
        {
            node->right = node->right->right;
            traverse(node, l, r);
        }

        traverse(node->left, l, r);
        traverse(node->right, l, r);
    }

    Node *removekeys(Node *root, int l, int r)
    {
        Node *newRoot = new Node(0);
        newRoot->left = root;

        traverse(newRoot, l, r);
        return newRoot->left;
    }
};