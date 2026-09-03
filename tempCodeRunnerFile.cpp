

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
