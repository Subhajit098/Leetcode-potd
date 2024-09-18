#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b)
{
    string sa = to_string(a), sb = to_string(b);

    if ((sa + sb) > (sb + sa))
        return true;

    return false;
}

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), cmp);

    if (nums[0] == 0)
        return "0";

    string ans = "";
    for (int i : nums)
    {
        ans += to_string(i);
    }

    return ans;
}

int main()
{

    return 0;
}