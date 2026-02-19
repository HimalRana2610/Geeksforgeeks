#include <bits/stdc++.h>
using namespace std;

class kQueues
{
private:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;

public:
    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        free = 0;
    }

    void enqueue(int x, int i)
    {
        if (free == -1)
        {
            return;
        }

        int newIdx = free;
        free = next[free];

        arr[newIdx] = x;
        next[newIdx] = -1;

        if (rear[i] == -1)
        {
            front[i] = newIdx;
        }
        else
        {
            next[rear[i]] = newIdx;
        }
        rear[i] = newIdx;
    }

    int dequeue(int i)
    {
        if (front[i] == -1)
        {
            return -1;
        }

        int idx = front[i];
        int val = arr[idx];

        front[i] = next[idx];

        if (front[i] == -1)
        {
            rear[i] = -1;
        }

        next[idx] = free;
        free = idx;

        return val;
    }

    bool isEmpty(int i)
    {
        return front[i] == -1;
    }

    bool isFull()
    {
        return free == -1;
    }
};