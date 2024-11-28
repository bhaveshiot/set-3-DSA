#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;  // Stack to store opening brackets
    unordered_map<char, char> matchingBrackets = {
        {')', '('},  // Map closing bracket to opening bracket
        {']', '['},
        {'}', '{'}
    };
    
    for (char c : s) {
        // If the character is an opening bracket, push it to the stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        // If the character is a closing bracket, check for matching opening bracket
        else if (c == ')' || c == ']' || c == '}') {
            // If the stack is empty or the top of the stack doesn't match, return false
            if (st.empty() || st.top() != matchingBrackets[c]) {
                return false;
            }
            // If it matches, pop the top element from the stack
            st.pop();
        }
    }

    // If the stack is empty, all brackets were matched; otherwise, return false
    return st.empty();
}

int main() {
    string s;
    cout << "Enter the string of brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
