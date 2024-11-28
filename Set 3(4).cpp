#include <iostream>
#include <string>
using namespace std;

bool checkValidString(const string& s) {
    int minOpen = 0, maxOpen = 0;

    // First pass (left to right)
    for (char c : s) {
        if (c == '(') {
            minOpen++;
            maxOpen++;
        } else if (c == ')') {
            minOpen--;
            maxOpen--;
        } else { // c == '*'
            minOpen--;
            maxOpen++;
        }

        // minOpen can't be negative, it should be at least 0
        if (minOpen < 0) {
            minOpen = 0;
        }

        // If maxOpen is negative, it means there's an excess of closing parentheses
        if (maxOpen < 0) {
            return false;
        }
    }

    // After the first pass, minOpen should be 0 (we matched all parentheses)
    return minOpen == 0;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    if (checkValidString(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
