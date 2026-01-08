#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    string eq = "532+56-12";

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

    }

    stack<string> copy = st;
    stack<string> rev;
    while (!copy.empty()) {
        rev.push(copy.top());
        copy.pop();
    }

    while (!rev.empty()) {
        cout << rev.top() << "\n";
        rev.pop();
    }



    return 0;
}