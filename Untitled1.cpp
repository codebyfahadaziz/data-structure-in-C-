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

class List {
public:
    node* head;
    node* tail;

    List() {
        head = tail = NULL;
    }

    // Insert at back (and make it circular)
    void circular_list(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = tail = newnode;
            tail->next=head;
        } else {
        	tail->next=newnode;
        	tail = newnode;
        	tail->next = head;
        }
    }



      	//display function for printing the list
	void print(){
     if(head == NULL) return ;
     node* temp = head;
     do{
     	     cout<<temp->data<<" ";

     temp=temp->next;
	 }while(temp !=head);
}
};

int main() {
    List l1;
    l1.circular_list(34);
    l1.circular_list(44);
    l1.circular_list(94);

    l1.print();  // ? prints: 34 44 94

    return 0;
}

