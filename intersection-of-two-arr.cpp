#include <bits/stdc++.h>
using namespace std;

// First Method
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = 0; i < n1; i++)
    {
        mp[nums1[i]]++;
    }

    vector<int> ans;
    for (int i = 0; i < n2; i++)
    {
        if (mp.find(nums2[i]) != mp.end())
        {
            ans.push_back(nums2[i]);
            mp[nums2[i]]--;
            if (mp[nums2[i]] == 0)
                mp.erase(nums2[i]);
        }
    }
    return ans;
}

// Second Method
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < n1 && j < n2)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++, j++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}