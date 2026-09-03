#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Display linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Construct linked list
void linkedListConstruction(int n, int data[], Node*& head) {

    if (n == 0) {
        head = NULL;
        return;
    }

    Node* temp = NULL;

    for (int i = 0; i < n; i++) {

        Node* newNode = new Node(data[i]);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Reorder the Linked List using stack
void reorderList(Node*head){
stack<Node*> st;
//Put them all in one stack
Node*curr=head;
while(curr!=NULL){
    st.push(curr);
    curr=curr->next;
}
int n1=st.size();
curr=head;

//Reorder the list
for(int i=0;i<n1/2;i++){
    Node* last = st.top();
        st.pop();

        Node* nextNode = curr->next;

        curr->next = last;
        last->next = nextNode;

        curr = nextNode;
    }

    // Make last node point to NULL
    curr->next = NULL;

};



int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int* data = new int[n];

    cout << "Enter data of nodes: ";

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    Node* head = NULL;

    linkedListConstruction(n, data, head);

    cout << "Original List: ";
    display(head);

       reorderList(head);

    cout << "Reordered Linked List: ";
    display(head);
 

    delete[] data;

    return 0;
}
 