#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &arr, int k)
{
    int maxi = *max_element(arr.begin(), arr.end());
    long long count = 0, ans = 0;
    long long i = 0, j = 0;
    long long n = arr.size();
    while (j < n)
    {
        if (arr[j] == maxi)
            count++;

        if (count < k)
            j++;

        else if (count == k)
        {
            ans += (n - j);
            if (arr[i] == maxi)
            {
                count--;
            }
            i++;
            while (count == k && i <= j)
            {
                ans += (n - j);
                if (arr[i] == maxi)
                    count--;
                i++;
            }
            j++;
        }
    }
    return ans;
}