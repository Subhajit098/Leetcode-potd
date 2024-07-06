#include <bits/stdc++.h>
using namespace std;

// Approach 1
int passThePillow(int n, int time)
{
    int count = 0;
    int flag = 1;
    int ans = 0;
    int z = 0; // it is used for removing the duplicate timer count on the last and first element.
    while (true)
    {
        if (flag)
        {
            for (int i = 1 + z; i <= n; i++)
            {
                if (count == time)
                {
                    return i;
                }
                count++;
            }
            z = 1;
            flag = 0;
        }
        else
        {
            for (int i = n - z; i >= 1; i--)
            {
                if (count == time)
                {
                    return i;
                }
                count++;
            }
            flag = 1;
        }
    }
    return 0;
}

// Approach 2
int passThePillow(int n, int time)
{

    int c = time / (n - 1);

    if (c % 2 == 0)
        return time % (n - 1) + 1;
    return n - (time % (n - 1));
}

int main()
{

    return 0;
}