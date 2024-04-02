#include <bits/stdc++.h>
using namespace std;

// Method 1
bool isIsomorphic(string s, string t)
{
    if (s == t)
        return true;
    unordered_map<char, char> mp;
    unordered_map<char, bool> taken;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            if (mp[s[i]] != t[i])
                return false;
        }
        else
        {
            if (taken[t[i]])
                return false;
            mp[s[i]] = t[i];
            taken[t[i]] = true;
        }
    }
    return true;
}

// Method 2
bool isIsomorphic(string s, string t)
{
    if (s == t)
        return true;
    unordered_map<char, char> mp1, mp2;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i])
            return false;

        else if (mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i])
            return false;

        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    return true;
}