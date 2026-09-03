#include<iostream>
#include<algorithm>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Display first linked list
void display1(Node* head1) {
    Node* curr1 = head1;
    while(curr1 != NULL) {
        cout << curr1->data << " ";
        curr1 = curr1->next;
    }
    cout << endl;
}

// Display second linked list
void display2(Node* head2) {
    Node* curr2 = head2;
    while(curr2 != NULL) {
        cout << curr2->data << " ";
        curr2 = curr2->next;
    }
    cout << endl;
}

// Take input
void takeInput(int &n, int &m, int* &datan, int* &datam) {

    cout << "Enter number of nodes in first linked list: ";
    cin >> n;

    cout << "Enter number of nodes in second linked list: ";
    cin >> m;

    datan = new int[n];
    datam = new int[m];

    cout << "Enter elements of first sorted linked list:\n";
    for(int i = 0; i < n; i++)
        cin >> datan[i];

    cout << "Enter elements of second sorted linked list:\n";
    for(int i = 0; i < m; i++)
        cin >> datam[i];
}

// Create linked lists
void createLL(int n, int m, int datan[], int datam[], Node* &head1, Node* &head2) {

    Node** node1 = new Node*[n];
    Node** node2 = new Node*[m];

    // Create first linked list
    for(int i = 0; i < n; i++) {
        node1[i] = new Node(datan[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        node1[i]->next = node1[i + 1];
    }

    node1[n - 1]->next = NULL;
    head1 = node1[0];

    // Create second linked list
    for(int i = 0; i < m; i++) {
        node2[i] = new Node(datam[i]);
    }

    for(int i = 0; i < m - 1; i++) {
        node2[i]->next = node2[i + 1];
    }

    node2[m - 1]->next = NULL;
    head2 = node2[0];

    delete[] node1;
    delete[] node2;
}

// Merge two linked lists using arrays
Node* merge(int &n, int &m, int datan[], int datam[]) {

    int total = n + m;

    int* arr = new int[total];

    // Copy first array
    for(int i = 0; i < n; i++) {
        arr[i] = datan[i];
    }

    // Copy second array
    for(int i = 0; i < m; i++) {
        arr[n + i] = datam[i];
    }

    // Sort merged array
    sort(arr, arr + total);

    // Create merged linked list
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < total; i++) {

        Node* newNode = new Node(arr[i]);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    delete[] arr;

    return head;
}

int main() {

    int n, m;
    int* datan;
    int* datam;

    Node* head1 = NULL;
    Node* head2 = NULL;

    takeInput(n, m, datan, datam);

    createLL(n, m, datan, datam, head1, head2);

    cout << "\nFirst Linked List: ";
    display1(head1);

    cout << "Second Linked List: ";
    display2(head2);

    Node* mergedHead = merge(n, m, datan, datam);

    cout << "Merged Linked List: ";
    display1(mergedHead);

    delete[] datan;
    delete[] datam;

    return 0;
}
