#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool cekValid(string exp) {
    stack<char> st;

    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !isMatching(st.top(), c))
                return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string ekspresi;
    cout << "Input: ";
    getline(cin, ekspresi);

    if (cekValid(ekspresi))
        cout << "Valid\n";
    else
        cout << "Tidak Valid\n";

    return 0;
}