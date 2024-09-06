#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *arrToLL(vector<int> &arr)
{
    Node *dummy = new Node(-1);
    Node *head = dummy;
    for (int i = 0; i < arr.size(); i++)
    {
        dummy->next = new Node(arr[i]);
        dummy = dummy->next;
    }

    return head->next;
}

void traverse(Node *head)
{
    Node *temp = head;
    cout << "Data in LL : ";
    while (temp)
    {
        cout << temp->data << " , ";
        temp = temp->next;
    }
    cout << endl;
}

Node *modifiedList(vector<int> &nums, Node *head)
{
    unordered_set<int> st;
    for (int i : nums)
        st.insert(i);

    Node *newhead = new Node(-1);
    newhead->next = head;
    Node *prev = newhead, *curr = prev->next;

    while (curr != NULL)
    {
        int data = curr->data;
        if (st.find(data) != st.end())
        {
            Node *del = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete (del);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

        // cout << "prev : " << prev->data << " , curr: " << curr->data << endl;
    }

    return newhead->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arrToLL(arr);
    traverse(head);
    vector<int> nums = {1, 2, 3};
    modifiedList(nums, head);
    return 0;
}