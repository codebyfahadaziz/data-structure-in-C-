#include <iostream>
using namespace std;

class stack {
public:
    int top;
    int capacity;
    char* arr;

    stack(int c) {
        capacity = c;
        top = -1;
        arr = new char[capacity];
    }

    void push(char c) {
        if (top == capacity - 1) {
            cout << "STACK IS OVERFLOW : " << endl;
            return;
        } else {
            top++;
            arr[top] = c;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "STACK IS UNDERFLOW : " << endl;
            return;
        } else {
            top--;
        }
    }

    bool empty() {
        return top == -1;
    }

    char getTop() {
        if (top == -1) {
            cout << "STACK IS UNDERFLOW : " << endl;
            return '\0';
        } else {
            return arr[top];
        }
    }

    bool braket_balance(string bracket) {
        stack st(100); // enough capacity
        for (char c : bracket) {
            if (c == '(' || c == '{' || c == '[') { // ?? fixed ']' -> '['
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if ((st.getTop() == '(' && c == ')') ||
                        (st.getTop() == '{' && c == '}') ||
                        (st.getTop() == '[' && c == ']')) {
                        st.pop();
                    } else {
                        return false; // ?? added for mismatch case
                    }
                }
            }
        }
        return st.empty();
    }
};

int main() {
    char choice;
    do{
    string brackets;
    cout << "PLEASE ENTER THE BRACKETS: ";
    cin >> brackets;

    stack st(100); // ?? fixed: added capacity argument
    if (st.braket_balance(brackets))
        cout << "? Balanced brackets";
    else
        cout << "? Not balanced";
        cout<<"DID YOU WANT TO PERFORM AGAIN THE N PRESS (Y)";
        cin>>choice;
}while(choice == 'y');
    return 0;
}
