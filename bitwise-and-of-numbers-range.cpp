#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int count = 0;
    while (right != left)
    {
        right = right >> 1;
        left = left >> 1;
        count++;
    }
    while (count)
    {
        right = right << 1;
        count--;
    }
    return right;
}