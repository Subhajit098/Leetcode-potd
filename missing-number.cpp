#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int real = n * (n + 1) / 2;
    return real - total;
}