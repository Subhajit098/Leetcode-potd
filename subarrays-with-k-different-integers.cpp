#include<bits/stdc++.h>
using namespace std;

int sliding_window(vector<int> nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        while (j < n) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding_window(nums, k) - sliding_window(nums, k - 1);
    }