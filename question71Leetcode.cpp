#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {

            // Ignore empty parts and "."
            if (part == "" || part == ".") {
                continue;
            }

            // Go to parent directory
            if (part == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                // Normal directory/file name
                st.push(part);
            }
        }

        // If stack is empty, path is root
        if (st.empty()) {
            return "/";
        }

        // Build the final path
        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution obj;

    string path;

    cout << "Enter absolute path: ";
    cin >> path;

    cout << "Simplified path: "
         << obj.simplifyPath(path);

    return 0;
}