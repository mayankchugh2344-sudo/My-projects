#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:

    // Constructor
    MinStack() {
    }

    // Push element
    void push(int value) {

        st.push(value);

        // If minStack is empty or value is smaller/equal
        // to the current minimum
        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    // Remove top element
    void pop() {

        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        // If the removed element is the minimum
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    // Get top element
    int top() {

        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return st.top();
    }

    // Get minimum element
    int getMin() {

        if (minSt.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return minSt.top();
    }
};

int main() {

    MinStack s;

    // Push elements
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    // Remove 2
    s.pop();

    cout << "After pop:" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    // Remove 7
    s.pop();

    cout << "After another pop:" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;

    return 0;
}