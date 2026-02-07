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

class quene{
	public:
		node* front ;
		node* rear ;
		quene(){
			front = rear = NULL;
		}
		bool is_empty(){
			 return front == NULL;
		}
		
	  void push(int val){
	  	node* newnode = new node(val);
	  	if(is_empty()){
	  		front = rear = newnode;
		  }
		  else{
		  	rear->next = newnode;
		  	rear = newnode;
		  }
	  }	
	  void pop(){
	  	if(is_empty()){
	  		return ;
		  }
		  else{
		  	node* temp = front;
		  	front = front->next;
		  	delete temp;
		  }
	  }	
	  void display(){
	  	node* temp = front;
	  while(temp != NULL){
	  	cout<<temp->data<<" ";
	  	temp = temp->next;
	  }
	  }		
};
int main(){
	 quene q1;
	 q1.push(1);
	 q1.push(2);
	 q1.push(3);
	 q1.push(4);
	 q1.push(5);

	q1.display();
		 q1.pop();
		 cout<<endl;
		 	q1.display();


	return 0;
}
