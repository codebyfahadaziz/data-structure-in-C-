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
	node* head;
	node*tail;
	public:
	list(){ //parameteried constructor
	  	head = tail =NULL;
	}
	void push_front(int  val){
		node* newNode = new node(val) ;
		if(head ==NULL){
			head = tail =newNode;
		}
		else{
		newNode->next =head;
		head =newNode;
		}
	}
	// push_back
	void push_back(int  val){
		node* newNode = new node(val) ;
		if(head ==NULL){
			head = tail =newNode;
		}
		else{
		tail =newNode->next;
		tail =newNode;
		}
	}
	//display function for printing the list
	void print(){
		node* temp =head;
		while(temp != NULL){
			cout << temp->data << " ";

			temp = temp->next;
		}
	}
	void reverse(){
		node*  next= NULL;
		node*  curr =head;
		node*  prev= NULL;
 while (curr!= NULL){
 	next =curr->next;
 	curr->next =prev;
 	prev = curr;
 	curr =next;	
 }
 head =prev;
	}
};
int main(){
	list ll;
	ll.push_front(3);
	ll.push_front(56);
	ll.push_front(9);
	
		ll.push_front(90);
		ll.print();
		ll.reverse();
		cout<<endl;
   cout<<"Rverse list"<<endl;
			ll.print();
cout<<"PUSH BACK"<<endl;
ll.push_back(10);
ll.push_back(11);
ll.push_back(12);
ll.push_back(13);
ll.push_back(14);
ll.print();


	return 0;
}
