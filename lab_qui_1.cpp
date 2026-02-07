#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class doubly_list {
public:
    node* head;
    node* tail;

    doubly_list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    // ? Insert at specific position (same logic, adjusted for doubly list)
    void insert_at_specific_pos() {
        int count = 0;
        node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int pos, value;
        cout << "PLEASE ENTER NUMBER THAT YOU WANT TO INSERT: ";
        cin >> value;
        cout << "PLEASE ENTER POSITION IN WHICH YOU WANT TO INSERT A NUMBER: ";
        cin >> pos;

        node* newnode = new node(value);

        if (pos < 1 || pos > count + 1) {
            cout << "YOU ENTERED INVALID POSITION!" << endl;
            delete newnode;
            return;
        }

        if (pos == 1) {
            // insert at start
            newnode->next = head;
            if (head != NULL)
                head->prev = newnode;
            head = newnode;
            if (tail == NULL) // if list was empty
                tail = newnode;
        } else {
            node* prev = head;
            for (int i = 1; i < pos - 1; i++) {
                prev = prev->next;
            }
            newnode->next = prev->next;
            newnode->prev = prev;

            if (prev->next != NULL)
                prev->next->prev = newnode;
            else
                tail = newnode; // if inserted at end

            prev->next = newnode;
        }
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    doubly_list l1;
    l1.push_front(50);
    l1.push_front(40);
    l1.push_front(30);
    l1.push_front(20);
    l1.push_front(10);

    cout << "BEFORE INSERTION: ";
    l1.display();

    l1.insert_at_specific_pos();

    cout << "AFTER INSERTION: ";
    l1.display();

    return 0;
}

