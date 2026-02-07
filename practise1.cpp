#include<iostream>
using namespace std;
class node{
	public:
			int data;
			node* next;
			node(int val){
				data = val;
				next = NULL;
			}
};
class list{
	public:
		node* head;
		node* tail;
		list(){
			head= tail =NULL;
		}
		void push_front(int val){
		node* newnode = new node(val);
			if(head == NULL){
				head = newnode;
			}
			else{
				newnode->next = head;
				head = newnode;
			}
			}
		void delete_first(){
			if(head == NULL){
			 cout<<"LINKED  LIST IS EMPTY : "<<endl;
			 return;	
			}
			else{
				node*temp = head;
				head = head->next;
				delete temp;
			}
		}
		void display(){
			if(head == NULL){
				cout<<"list is empty : "<<endl;
				return;
			}
			else{
				node* temp = head;
				
				while(temp != NULL){
					cout<<temp->data<<" ";
					temp = temp->next;
					
				}
				
			}
		}
	void delete_last() {

    // Case 1: List empty
    if (head == NULL) {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    // Case 2: Only one node
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // Case 3: More than one node
    node* temp = head;

    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}

};
int main(){
	list l1;
	l1.push_front(5);
	l1.push_front(4);
	l1.push_front(3);
	l1.push_front(2);
	l1.push_front(1);
 l1.display();
 	cout<<endl;

 l1.delete_first();
 cout<<"DELETE FIRST ELEMENT : "<<endl;

  l1.display();
 	cout<<endl;

cout<<"DELETE LAST ELEMENT : "<<endl;
l1.delete_last();

  l1.display();

	return 0;
}
