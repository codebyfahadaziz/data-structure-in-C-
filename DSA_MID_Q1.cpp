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

    list() {
        head = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    void display() {
        node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void similar_difference(list &a, list &b) {

        node* t1 = a.head;
        node* t2;
        
        list C; // intersection
        list D; // difference (elements in A not in B)

        // Find intersection and difference
        while (t1 != NULL) {
            bool found = false;
            t2 = b.head;

            while (t2 != NULL) {
                if (t1->data == t2->data) {
                    found = true;
                    break;
                }
                t2 = t2->next;
            }

            if (found)
                C.push_front(t1->data);      // common elements
            else
                D.push_front(t1->data);      // different elements

            t1 = t1->next;
        }

        cout << "\nSimilar Elements (Intersection): ";
        C.display();

        cout << "Different Elements (A - B): ";
        D.display();
    }
};

int main() {
    list a;
    cout << "LIST A: ";
    a.push_front(32);
    a.push_front(17);
    a.push_front(22);
    a.push_front(9);
    a.push_front(16);
    a.push_front(15);
    a.push_front(10);
    a.push_front(7);
    a.push_front(3);
    a.display();

    cout << "LIST B: ";
    list b;
    b.push_front(28);
    b.push_front(1);
    b.push_front(10);
    b.push_front(8);
    b.push_front(47);
    b.push_front(13);
    b.push_front(9);
    b.push_front(2);
    b.push_front(16);
    b.display();

    list c;
    c.similar_difference(a, b);

    return 0;
}

