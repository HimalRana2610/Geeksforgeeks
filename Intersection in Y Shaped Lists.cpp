#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        unordered_set<Node *> s;
        Node *current1 = head1;

        while (current1 != NULL)
        {
            s.insert(current1);
            current1 = current1->next;
        }

        Node *current2 = head2;
        while (current2 != NULL)
        {
            if (s.find(current2) != s.end())
            {
                return current2;
            }
            current2 = current2->next;
        }

        return NULL;
    }
};