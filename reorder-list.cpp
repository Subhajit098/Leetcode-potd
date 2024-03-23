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

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *second = slow->next;
    slow->next = NULL;
    ListNode *first = head;
    ListNode *temp2 = reverse(second);
    while (first && temp2)
    {
        ListNode *next = first->next;
        ListNode *temp2_next = temp2->next;
        first->next = temp2;
        temp2->next = next;
        temp2 = temp2_next;
        first = next;
    }
}