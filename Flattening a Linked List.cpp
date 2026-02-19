#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *flatten(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }

        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

        Node *current = root;
        while (current)
        {
            pq.push({current->data, current});
            current = current->next;
        }

        Node *temp = new Node(0);
        Node *tail = temp;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            Node *node = top.second;
            tail->bottom = node;
            tail = tail->bottom;

            if (node->bottom)
            {
                pq.push({node->bottom->data, node->bottom});
            }
        }

        return temp->bottom;
    }
};