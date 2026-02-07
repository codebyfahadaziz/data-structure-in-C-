#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	public:
		node(int val){
			data = val;
			next = NULL;
		}
};
class stack{
	public:
	node* top;
	stack(){
	    top = NULL;	
	}
	bool is_empty(){
		return top == NULL;
	}
	void push(int val){
	  	node* newnode = new node(val);
        if(top == NULL){
            top = newnode;	
		}
		else{
			newnode->next =  top;
			top = newnode;
		}	
	}
	void pop(){
		if(is_empty()){
			cout<<"STACK IS EMPTY : "<<endl;
			return;
			}
			else{
				top--;
			}
}
void display(){
  node*	temp = top;
   while(temp!= NULL){
   	cout<<temp->data<<" ";
   	temp = temp->next;
   }
}
};
int main(){
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

		s1.display();

	return 0;
}
