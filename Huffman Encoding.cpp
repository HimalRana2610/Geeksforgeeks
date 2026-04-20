#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, index;
    Node *left, *right;

    Node(int d, int i)
    {
        data = d;
        index = i;
        left = right = nullptr;
    }

    Node(Node *l, Node *r)
    {
        data = l->data + r->data;
        index = min(l->index, r->index);
        left = l;
        right = r;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        if (a->data != b->data)
        {
            return a->data > b->data;
        }

        return a->index > b->index;
    }
};

class Solution
{
public:
    void preOrder(Node *root, vector<string> &ans, string curr)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            if (curr == "")
            {
                curr = "0";
            }

            ans.push_back(curr);
            return;
        }

        preOrder(root->left, ans, curr + '0');
        preOrder(root->right, ans, curr + '1');
    }

    vector<string> huffmanCodes(string &s, vector<int> f)
    {
        int n = s.length();
        priority_queue<Node *, vector<Node *>, Compare> pq;

        for (int i = 0; i < n; i++)
        {
            Node *tmp = new Node(f[i], i);
            pq.push(tmp);
        }

        if (n == 1)
        {
            return {"0"};
        }

        while (pq.size() >= 2)
        {
            Node *l = pq.top();
            pq.pop();

            Node *r = pq.top();
            pq.pop();

            Node *newNode = new Node(l, r);
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;

        preOrder(root, ans, "");
        return ans;
    }
};