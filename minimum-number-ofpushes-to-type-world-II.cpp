#include <bits/stdc++.h>
using namespace std;


int minimumPushes(string word)
{
    unordered_map<char, int> mp;
    for (char ch : word)
        mp[ch]++;

    vector<pair<int, char>> freq;
    for (auto it : mp)
    {
        freq.push_back(make_pair(it.second, it.first));
    }

    sort(freq.begin(), freq.end(), greater<pair<int, char>>());

    int count = 0;

    int ans = 0;

    for (int i = 0; i < freq.size(); i++)
    {
        count++;
        if (count <= 8)
        {
            ans += (freq[i].first) * 1;
        }
        else if (count >= 9 && count <= 16)
            ans += (freq[i].first) * 2;

        else if (count >= 17 && count <= 24)
            ans += (freq[i].first) * 3;

        else
            ans += (freq[i].first) * 4;
    }

    return ans;
}



int main()
{

    return 0;
}