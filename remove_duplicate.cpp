#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void remove_duplicate(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *run = temp;
        while (run->next != NULL)
        {
            if (run->next->val == temp->val)
            {
                Node *duplicate = run->next;
                run->next = run->next->next;
                delete duplicate;
            }
            else
            {
                run = run->next;
            }
        }
        temp = temp->next;
    }
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head, tail, val);
    }
    remove_duplicate(head);
    print_linked_list(head);
    return 0;
}