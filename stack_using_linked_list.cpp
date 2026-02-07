#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListStack {
    Node* top;
    
public:
    LinkedListStack() {
        top =NULL;
    }
    
    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value << endl;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    bool isFull() {
        return false;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListStack llStack;
    
    cout << "=== STACK USING LINKED LIST ===" << endl;
    
    llStack.push(100);
    llStack.push(200);
    llStack.push(300);
    llStack.push(400);
    
    llStack.display();
    
    llStack.pop();
    llStack.pop();
    
    llStack.display();
    
    cout << "Top element: " << llStack.peek() << endl;
    cout << "Is stack empty? " << (llStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (llStack.isFull() ? "Yes" : "No") << endl;
    
    return 0;
}
