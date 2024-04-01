#include <bits/stdc++.h>
using namespace std;

// Method 1 using extra space
int lengthOfLastWord(string s)
{
    vector<string> ds;
    string str = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        else
        {
            int start = i;
            while (s[i] != ' ' && i < n)
            {
                i++;
            }
            ds.push_back(s.substr(start, i - start));
        }
    }
    string ans = ds[ds.size() - 1];
    return ans.size();
}

// Method 2 with O(1) space
int lengthOfLastWord(string s)
{
    // vector<string> ds;
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        else
        {
            int start = i;
            while (s[i] != ' ' && i < n)
            {
                i++;
            }
            ans = s.substr(start, i - start);
        }
    }
    return ans.size();
}