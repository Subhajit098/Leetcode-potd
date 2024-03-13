#include <bits/stdc++.h>
using namespace std;

// Brute force
int pivot(int n)
{
    if (n == 1)
        return 1;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        int sum2 = total - sum;
        if (sum == sum2 + i)
            return i;
    }
    return -1;
}

// O(1) approach
int pivot(int n)
{
    int sum = n * (n + 1) / 2;
    double a = sqrt(sum);

    if (a - ceil(a) == 0)
        return int(a);
    else
        return -1;
}