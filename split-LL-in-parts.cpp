#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    temp = head;
    vector<ListNode *> ans;
    if (len == 0)
    {
        for (int i = 0; i < k; i++)
            ans.push_back(nullptr);
        return ans;
    }

    int each = len / k, rem = len % k;
    int cnt = rem;
    while (cnt--)
    {
        int length_of_each = each + 1;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = NULL;
        dummy->next = temp;
        while (length_of_each--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        ans.push_back(dummy->next);
    }

    cnt = k - rem;
    while (cnt--)
    {
        int length_of_each = each;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = NULL;
        dummy->next = temp;
        while (length_of_each--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        ans.push_back(dummy->next);
    }

    return ans;
}

int main()
{

    return 0;
}