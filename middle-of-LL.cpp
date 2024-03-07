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

int Length(ListNode *head)
{
    // if(!head) return 0;
    int length = 0;
    ListNode *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode *middleNode(ListNode *head)
{
    if (!head || !head->next)
        return head;
    int length = Length(head);
    int counter = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        counter++;
        if (counter == length / 2)
        {
            break;
        }
        temp = temp->next;
    }
    return temp->next;
}

ListNode *middleNode(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}