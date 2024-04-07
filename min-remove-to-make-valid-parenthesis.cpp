#include <bits/stdc++.h>
using namespace std;

// Stack approach
string minRemoveToMakeValid(string s)
{
    if (s == "")
        return s;
    int n = s.size();
    string dummy = "";
    stack<pair<char, int>> st;
    for (int i = 0; i < n; i++)
    {
        pair<char, int> new_pair = make_pair(s[i], i);
        if (s[i] == '(' || s[i] == ')')
        {
            if (st.empty())
                st.push(new_pair);

            else if (st.top().first == '(' && s[i] == ')')
                st.pop();

            else
            {
                st.push(new_pair);
            }
        }
    }
    if (st.empty())
        return s;
    while (!st.empty())
    {
        s[st.top().second] = '$';
        st.pop();
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '$')
            ans += s[i];
    }
    return ans;
}


// Without stack approach
string minRemoveToMakeValid(string s)
{
    if (s == "")
        return s;
    int n = s.size();
    string dummy = "";
    int open = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
            dummy.push_back(ch);
        else if (ch == ')')
        {
            if (open > 0)
            {
                open--;
                dummy.push_back(ch);
            }
            else
                continue;
        }
        else
        {
            open++, dummy.push_back(ch);
        }
    }
    int close = 0;
    string ans = "";
    for (int i = dummy.size() - 1; i >= 0; i--)
    {
        char ch = dummy[i];

        if (ch >= 'a' && ch <= 'z')
            ans.push_back(ch);

        else if (ch == '(')
        {
            if (close > 0)
            {
                close--;
                ans.push_back(ch);
            }
            else
                continue;
        }
        else
        {
            close++, ans.push_back(ch);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}