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
    int lengthOfLoop(Node *head)
    {
        unordered_map<Node *, int> index;
        Node *temp = head;

        for (int i = 1; temp; i++)
        {
            index[temp] = i;
            if (index.find(temp->next) != index.end())
            {
                return i - index[temp->next] + 1;
            }
            temp = temp->next;
        }

        return 0;
    }
};