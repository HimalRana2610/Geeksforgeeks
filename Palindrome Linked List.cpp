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
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node *current = head;

        while (current != NULL)
        {
            arr.push_back(current->data);
            current = current->next;
        }

        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            if (arr[left] != arr[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};