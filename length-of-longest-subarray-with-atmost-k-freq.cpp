#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0, n = arr.size();
    int maxi = INT_MIN, ans = INT_MIN;
    while (j < n)
    {
        mp[arr[j]]++;

        maxi = max(maxi, mp[arr[j]]);

        if (maxi <= k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }

        else
        {
            while (mp[arr[j]] > k && i <= j)
            {
                mp[arr[i]]--;
                i++;
            }
            maxi = mp[arr[j]]; // or else we can write maxi=k
            j++;
        }
    }
    return ans;
}