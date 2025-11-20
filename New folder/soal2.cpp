#include <iostream>
#include <stack>
using namespace std;

int main() {
    string kalimat;
    cout << "Input: ";
    getline(cin, kalimat);

    stack<char> st;

    for (char c : kalimat)
        st.push(c);

    cout << "Output: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}