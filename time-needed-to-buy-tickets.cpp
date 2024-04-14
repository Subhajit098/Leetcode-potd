#include <bits/stdc++.h>
using namespace std;

// Approach using queue , TC:O(n*maxi)  where maxi=max element in the array, SC:O(n)
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(tickets[i], i);
        q.push(p);
    }
    int count = tickets[k], timer = 0;
    while (count > 0 && !q.empty())
    {
        pair<int, int> p = q.front();
        if (p.first > 0)
        {
            q.pop();
            pair<int, int> next = make_pair(p.first - 1, p.second);
            q.push(next);
            timer++;
            if (p.second == k)
                count--;
        }
        else
        {
            q.pop();
        }
    }
    return timer;
}

// Constant space but same time complexity
int timeRequiredToBuy(vector<int> &v, int k)
{
    int n = v.size();
    int t = 0;
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)
            {
                v[i] = v[i] - 1;
                t++;
            }
            if (i == k && v[i] == 0)
                return t;
        }
    }
    return 0;
}

// Optimal solution , TC : O(n) , SC : O(1)
