#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	
	node(int val){
		next = NULL;
		data = val;
	}
	};
	class circular_list{
		public:
			node* head;
			node* tail;
			circular_list(){
				head = tail = NULL;
			}
			void push_front(int val){
				node* newnode = new node(val);
				if(head == NULL){
					head = tail = newnode;
				}
				else{
					newnode->next = head;
					head = newnode;
				    tail->next =  head;
				}
			}
			void push_back(int val){
				node* newnode = new node(val);
				 if(head == NULL){
				 	head = tail = NULL;
				 }
				 else {
				 	tail->next = newnode;
				 	tail = newnode;
				 	tail ->next = head;
				 }
			}
			void display(){
				node* temp = head;
				do
				{
				cout<<temp->data<<" ";
				temp= temp->next;
				}while(temp != head);
				
			}
			
	};
int main(){
	circular_list l1;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l1.push_front(4);
	l1.push_front(5);
    l1.push_back(6);
	l1.display();
	return 0;
}
