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
class stack{
	public:
		
	node* top;
	stack() {
    top = NULL;
}

	void push(int val){
		node* newnode = new node(val);
		if(top == NULL){
			top = newnode;
		}
		else{
			newnode->next = top;
			top = newnode;
		}
	}
		void pop(){
			if(top == NULL){
			cout<<"STACK IS UNDERFLOW : "<<endl;
			return;	
			}
			else{
				node* temp = top;
				top = top->next;
			  delete temp;	
			}
		}
	void display(){
		node* temp = top;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp =temp->next;
		}
	}
	void is_plaindrome(stack s1){
		bool found  = false;
		stack rev ;
		node* temp = s1.top;
				while(temp != NULL){
			rev.push(temp->data);
			temp = temp->next;
		}
		node* t1 = s1.top;
		node* t2 = rev.top;
		while(t1 != NULL && t2 != NULL){
			if(t1->data != t2->data){
			
			found = true;
			cout<<"stack is not palindrome : "<<endl;
			return;
		}
		t1 = t1->next;
		t2 = t2->next;

	}
		if(!found){
						cout<<"stack is palindrome : "<<endl;

		}
		
	}
};
int main(){
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(2);
	st.push(1);
	st.display();
	cout<<endl;
	st.is_plaindrome(st);
	
	return 0;
}

