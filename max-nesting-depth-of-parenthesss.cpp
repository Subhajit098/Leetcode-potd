#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    string dummy = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == ')')
            dummy += s[i];
    }
    int maxi = 0, count = 0;
    for (int i = 0; i < dummy.size(); i++)
    {
        if (dummy[i] == '(')
            count++;
        if (count > maxi)
            maxi = count;
        if (dummy[i] == ')')
            count--;
    }
    return maxi;
}