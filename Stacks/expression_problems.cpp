#include "iostream"

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

string infix_to_postfix(const string &infix) {
    stack<char> st;
    string ans;

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
            ans += infix[i];
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) > precedence(infix[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infix_to_prefix(string infix) {
    stack<char> st;
    string ans;

    reverse(infix.begin(), infix.end());


    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
            ans += infix[i];
        else if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) > precedence(infix[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int perform_operation(int op1, int op2, char op) {
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return static_cast<int> (pow(op1, op2));
        default: return 0;
    }
}

int postfix_evaluation(string postfix) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            st.push(postfix[i] - '0');
        else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            st.push(perform_operation(op1, op2, postfix[i]));
        }
    }
    return st.top();
}

int main() {
    cout<<infix_to_postfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infix_to_prefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<postfix_evaluation("46+2/5*7+")<<endl;
}