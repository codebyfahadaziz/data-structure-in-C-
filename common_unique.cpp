#include<iostream>
using namespace std;
 class node{
 	public:
 		int data;
 		node* next ;
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
 	  	head = tail = NULL;
	   }
	   
	   void push_back(int val){
	   	node* newnode = new node(val);
	   	if(head == NULL){
	   		head = tail = newnode;
		   }
		   else{
		   		   	tail->next = newnode;
		   		   	   tail = newnode;

		   }
	   }
	   void display(){
	   	node* temp = head;
	   	while( temp != NULL){
	   		cout<<temp->data<<" ";
	   		temp = temp->next;
		   }
	   }
 };
 
 int main(){
 	list l1,l2;
 	l1.push_back(1);
 	l1.push_back(2);
 	l1.push_back(3);
 	l1.push_back(4);
 	l1.push_back(5);
 	
 	
 	
 	 l1.display();
cout<<endl;
 	l2.push_back(6);
 	l2.push_back(5);
 	l2.push_back(4);
 	l2.push_back(7);
 	l2.push_back(8);
 	l2.push_back(9);
 	l2.push_back(10);
    l2.display();

 	
 	return 0;
 }
