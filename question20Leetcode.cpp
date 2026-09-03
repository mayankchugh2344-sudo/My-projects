#include <iostream>
#include <stack>
using namespace std;

int isValid(string s)
{
    stack<char> st;

    // Simple for loop
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // If stack is empty
            if (st.empty())
            {
                return 0;
            }

            char top = st.top();
            st.pop();

            // Check matching brackets
            if (ch == ')' && top != '(')
            {
                return 0;
            }

            if (ch == '}' && top != '{')
            {
                return 0;
            }

            if (ch == ']' && top != '[')
            {
                return 0;
            }
        }
    }

    // Stack should be empty
    if (st.empty())
    {
        return 1;
    }

    return 0;
}

int main()
{
    string s;

    cout << "Enter brackets: ";
    cin >> s;

    if (isValid(s) == 1)
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}
