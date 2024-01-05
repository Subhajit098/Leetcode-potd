#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int i,int prev_ind,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;

        if(dp[i][prev_ind+1]!=-1) return dp[i][prev_ind+1];

        int not_take=0+helper(nums,i+1,prev_ind,dp);

        int take=0;
        if(prev_ind ==-1 || nums[i]>nums[prev_ind]){
            take= 1 + helper(nums,i+1,i,dp);
        }

        return dp[i][prev_ind+1]=max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(nums,0,-1,dp);
    }