#include<iostream>
using namespace std;
 class node{
 	public:
 		int data;
 		node* prev;
 		node* next;
 		node(int val){
 		   data = val;
			prev = next = NULL;	
		 }
 };
 
 class doubly{
 public:
 	node* head;
 	node* tail;
 	doubly(){
 		head = tail = NULL ;
	 }
 	void push_front(int val){
 		node* newnode = new node(val);
 		if(head == NULL){
 			head = newnode;
		 }
		 else{
		 	newnode->next = head;// fro forward move
		 	head = newnode;
		 	head->prev = newnode;// fro backward move
		 }
	 }
	 void push_back(int val){
	 		node* newnode = new node(val);
 		if(head == NULL){
 			head =tail =  newnode;
		 }
		 else{
		 	tail->next = newnode;
		 	newnode->prev = tail;// fro backward move
		 	tail = newnode;
		 }
	 }

	 void insert_at_specific_pos(){
	 	int pos,val;
	 	node * temp = head;
	 	int count = 0;
	 	while(temp != NULL){
	 		temp = temp->next;
	 		count +=1;
	}
	cout<<"PLEASE ENTER YOUR POSITION OF INSERTION : "<<endl;
	cin>>pos;
	cout<<"PLEASE ENTER YOUR VALUE : "<<endl;
	cin>>val;
		 node* newnode = new node(val);
		 if(pos<1 || pos >count +1){
		 	cout<<"YOU ENTER INVALID INPUT "<<endl;
		 	delete newnode;
		 	return;
		 }
		 else{
		 	if(pos ==1){
		 		newnode->next = head;
		 	`	head ->prev = newnode;
		 		head = newnode;
			 }
			 else{
			 	node* prev1 = head;
			
			 	for(int i=0 ;i<pos-1;i++){
			 	   prev1 = prev1->next;	
				 }
				 newnode->next = prev1->next;
				 prev1->next->prev = newnode;
				 prev1->next = newnode;
				 newnode->prev = prev1;
			 }
		 }
	 }
	 	 void display(){
	 	node* temp = head;
	 	
	 	while(temp != NULL){
	 		cout<<temp->data<<" ";
	 		temp = temp->next;
		 }
	 }
 };
 int main(){
 	doubly d1;
 d1.push_back(1);
 d1.push_back(2);
 d1.push_back(3);
 d1.push_back(4);
 d1.push_back(5);
d1.push_front(0);

d1.display();
d1.insert_at_specific_pos();
d1.display();

 }
