#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;
    int n = nums.size(), ans = 0, i = 0, j = 0;
    int prod = 1;
    while (j < n)
    {
        prod *= nums[j];

        if (prod < k)
        {
            ans += j - i + 1;
            j++;
        }
        else
        {
            while (prod >= k)
            {
                prod /= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
    }
    return ans;
}