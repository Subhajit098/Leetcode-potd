#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{
    if (s == "")
        return s;
    stack<char> q;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
            q.push(s[i]);
        else
        {
            char ch = q.top();
            if (tolower(ch) == tolower(s[i]) && s[i] != ch)
            {
                q.pop();
            }
            else
            {
                q.push(s[i]);
            }
        }
    }
    if (q.empty())
        return "";
    string ans = "";
    while (!q.empty())
    {
        ans = q.top() + ans;
        q.pop();
    }
    return ans;
}