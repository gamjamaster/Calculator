#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    string eq = "532+56+1+1+1";

    stack<string> st;
    stack<char> op;
    string temp = "";

    for (int x = 0; x < eq.size(); x++){
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

    stack<int> ints;
    int result = 0;
    while (!rev_num.empty()) {
        ints.push(stoi(rev_num.top()));
        rev_num.pop();
    }

    while (!rev_op.empty()) {
        char x = rev_op.top();
        rev_op.pop();

        switch (x) {
        case '+': {
            int right = ints.top(); ints.pop();
            int left  = ints.top(); ints.pop();
            result = left + right;
            ints.push(result);
            break;
        }
        default:
            break;
        }
    }

    cout << result;

    return 0;
}