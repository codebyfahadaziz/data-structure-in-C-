#include <iostream>
#include <stack>
using namespace std;

class Queue {
    int size;
    stack<int> s1, s2; // making two stack  int format

public:
    Queue(int n) {
        size = n;
    }

    bool is_full() {
        return s1.size() + s2.size() == size;
    }//  if sixe if full

    bool is_empty() {
        return s1.empty() && s2.empty();
    }// if stac kis empty

    void enqueue(int x) {
        if (is_full()) {
            cout << "QUEUE IS FULL (OVERFLOW)\n";
            return;
        }
        s1.push(x);
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (is_empty()) {
            cout << "QUEUE IS EMPTY (UNDERFLOW)\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {// not empty
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued.\n";
        s2.pop();
    }

    void display() {
        if (is_empty()) {
            cout << "QUEUE IS EMPTY\n";
            return;
        }

        stack<int> temp2 = s2;
        stack<int> temp1 = s1;

        cout << "QUEUE : ";

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        stack<int> rev;
        while (!temp1.empty()) {
            rev.push(temp1.top());
            temp1.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
