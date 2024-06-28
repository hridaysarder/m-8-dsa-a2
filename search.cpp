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

void search(Node *head, int x)
{
    int flag = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == x)
        {
            cout << flag << endl;
            return;
        }
        temp = temp->next;
        flag++;
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
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
        int x;
        cin >> x;
        search(head, x);
    }
    return 0;
}