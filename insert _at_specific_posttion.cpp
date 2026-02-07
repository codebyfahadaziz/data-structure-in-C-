#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
public:
    node* head;
    node* tail;

    list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // ? insert at specific position (your logic, corrected)
    void insert_specific_position() {
        int pos, count = 0, val1;
        cout << "PLEASE ENTER THE POSITION: ";
        cin >> pos;
        cout << "PLEASE ENTER THE VALUE: ";
        cin >> val1;

        node* newnode = new node(val1);
        node* temp = head;

        // count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (pos < 1 || pos > count + 1) {
            cout << "ENTER INVALID POSITION!" << endl;
            delete newnode;
            return;
        }

        // if inserting at beginning
        if (pos == 1) {
            newnode->next = head;
            head = newnode;
            return;
        }

        // move to (pos - 1) node
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        // insert new node
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void display() {
        node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    list l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(5);

    l1.display();

    l1.insert_specific_position();

    l1.display();
    return 0;
}

