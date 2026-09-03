#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:

    // Push element x onto the stack
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    // Remove and return the top element
    int pop() {
        int value = q1.front();
        q1.pop();
        return value;
    }

    // Return the top element
    int top() {
        return q1.front();
    }

    // Check whether stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    cout << "Top: " << st.top() << endl;

    cout << "Is stack empty? " << st.empty() << endl;

    return 0;
}