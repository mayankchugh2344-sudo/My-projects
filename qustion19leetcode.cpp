#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display linked list
void display(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Remove nth node from end
Node* removeNthFromEnd(Node* head, int n)
{
    Node dummy(0);
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    // Move fast pointer n+1 steps
    for(int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return dummy.next;
}

int main()
{
    Node* head = NULL;

    int size;
    cout << "Enter number of nodes: ";
    cin >> size;

    cout << "Enter node values:\n";

    for(int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    cout << "Original Linked List: ";
    display(head);

    int n;
    cout << "Enter nth node from end to delete: ";
    cin >> n;

    head = removeNthFromEnd(head, n);

    cout << "Linked List after deletion: ";
    display(head);

    return 0;
}