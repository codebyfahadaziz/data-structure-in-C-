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
	stack(){
		top = NULL;
	}
	bool is_empty(){
		return (top == NULL);
	}	
	void push(int val){
		node* newnode = new node(val);
		if(is_empty()){
			top = newnode;
		}
		else{
			newnode->next = top;
			top = newnode;
		}
	}
	void pop(){
		if(is_empty()){
			cout<<"STACK IS UNDERFLOW : "<<endl;
			return;
		}
		else{
		
		node* temp = top;
		top =top->next;
		delete top;
	}
	}
	
	void display(){
		if(is_empty()){
			cout<<"STACK IS UNDERFLOW : "<<endl;
			return;
		}
		else{
			
		node * temp = top;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
	}
		}
	}
	void odd_even(stack s2){
		stack s3; // even number stack;
		stack s4; // odd number stack;
		node* temp = top;
   while(temp != NULL){
   	if(temp->data% 2 == 0){
   		s3.push(temp->data);
	   }
	   else{
	   	s4.push(temp->data);
	   }
	   temp = temp->next;
   }
   node* temp3 = s3.top;
   while(temp3 != NULL){
   	cout<<temp3->data<<" ";
   	temp3 = temp3 ->next;
   }
   
    node* temp4 = s4.top;
   while(temp4 != NULL){
   	cout<<temp4->data<<" ";
   	temp4 = temp4 ->next;
   }
   	int even_sum = 0;
   			node* temp1 = s3.top;
   	while(temp1 != NULL){
   		even_sum += temp1->data;
   		
   		temp1 = temp1->next;
	   }
   cout<<even_sum;

   	int odd_sum = 0;
   			node* temp2 = s4.top;
   	while(temp2 != NULL){
   		odd_sum += temp2->data;
   		temp2 = temp2->next;
	   }
      cout<<odd_sum;

}
};

int main(){
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);

	s1.display();
	cout<<endl;
	s1.odd_even(s1);
	
	
	
	
	
	
	
	
	
	
	
	
}
