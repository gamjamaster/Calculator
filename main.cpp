#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string eq = "55-2-3";

    stack<string> st;
    stack<char> op;
    string temp = "";

    for (int x = 0; x < eq.size(); x++) {
        bool isLast = (x == eq.size() - 1);
        if (isdigit(eq[x])) {
            temp.push_back(eq[x]);
        }
        else {
            st.push(temp);
            temp.clear();
        }

        if (isLast) {
            st.push(temp);
            break;
        }
    }

    for (char x : eq) {
        if (!(isdigit(x))) {
            op.push(x);
        }
    }

    stack<string> rev_num;
    while (!st.empty()) {
        rev_num.push(st.top());
        st.pop();
    }

    stack<char> rev_op;
    while (!op.empty()) {
        rev_op.push(op.top());
        op.pop();
    }

    int result = 0;

    while (!rev_op.empty()) {
        char x = rev_op.top();
        rev_op.pop();

        int left = stoi(rev_num.top());
        rev_num.pop();

        int right = stoi(rev_num.top());
        rev_num.pop();

        switch (x) {
        case '+': {
            result = left + right;
            break;
        }
        case '-': {
            result = left - right;
            break;
        }
        default:
            break;
        }
        rev_num.push(to_string(result));
    }

    if (!rev_num.empty()) cout << stoi(rev_num.top());
    else cout << result;

    return 0;
}