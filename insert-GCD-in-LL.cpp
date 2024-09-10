#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    return GCD(b % a, a);
}

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *temp = head->next;
    ListNode *prev = head;

    while (temp)
    {
        int a = prev->val, b = temp->val;
        ListNode *gcd = new ListNode(GCD(a, b));

        prev->next = gcd;
        gcd->next = temp;
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{

    return 0;
}