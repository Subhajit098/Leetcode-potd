#include <bits/stdc++.h>
using namespace std;

// Approach using prefix sum
// TC: O(n*log(n)) , SC: O(n)
long long largestPerimeter(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }

    long long flag = -1, sum = -1;
    for (int i = 1; i < n; i++)
    {
        if (i >= 2 && prefix_sum[i - 1] > nums[i])
        {
            flag = i;
            sum = prefix_sum[i - 1] + nums[i];
        }
    }
    if (!flag)
        return flag;
    return sum;
}

// Second approach using constant space and only sorting
// TC: O(n*log(n)) , SC: O(1)
long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long ans=-1,sum=0;
        for(int i=0;i<n;i++){
            if(sum>nums[i]){
                ans=nums[i]+sum;
            }
            sum+=nums[i];
        }
        return ans;
    }
