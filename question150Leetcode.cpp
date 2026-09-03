#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            // If token is an operator
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (tokens[i] == "+") {
                    st.push(a + b);
                }
                else if (tokens[i] == "-") {
                    st.push(a - b);
                }
                else if (tokens[i] == "*") {
                    st.push(a * b);
                }
                else if (tokens[i] == "/") {
                    st.push(a / b);
                }
            }

            // If token is a number
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};


int main() {

    int n;

    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> tokens(n);

    cout << "Enter the tokens: ";

    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    Solution obj;

    int result = obj.evalRPN(tokens);

    cout << "Result: " << result << endl;

    return 0;
}