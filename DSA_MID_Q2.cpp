#include<iostream>
using namespace std;
//(A+B^D)*(D/E)
class stack {
    int top;
    int capacity;
    char* arr;

public:
    stack(int c) {
        capacity = c;
        arr = new char[capacity];
        top = -1;
    }

    void push(char c) {
        if (top == capacity - 1) {
            cout << "STACK OVERFLOW!\n";
            return;
        }
        arr[++top] = c;
    }

    void pop() {
        if (top == -1) {
            cout << "STACK UNDERFLOW!\n";
            return;
        }
        top--;
    }

    bool is_empty() {
        return top == -1;
    }

    char get_top() {
        return arr[top];
    }

    int precedence(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        if (c == '^') return 3;   // optional but useful
        return 0;
    }

    string infix_to_postfix(string infix) {
        stack s(infix.length());
        string postfix = "";

        for (char c : infix) {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                s.push(c);
            }
            else if (c == ')') {
                while (!s.is_empty() && s.get_top() != '(') {
                    postfix += s.get_top();
                    s.pop();
                }
                if (!s.is_empty()) s.pop();  // pop '('
            }
            else { // operator
                while (!s.is_empty() &&
                       precedence(s.get_top()) >= precedence(c)) {
                    postfix += s.get_top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.is_empty()) {
            postfix += s.get_top();
            s.pop();
        }

        return postfix;
    }
};

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    stack s(infix.length());
    cout << "Postfix: " << s.infix_to_postfix(infix) << endl;

    return 0;
}

