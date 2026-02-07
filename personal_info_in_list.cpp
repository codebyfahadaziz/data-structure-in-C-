#include<iostream>
using namespace std;
class node{
	public:
	int age;
	string name;
	int class_no;
	node* next;
	public:
	node(int age,string name,int class_no){
		this->age = age;
		this->name = name;
		this->class_no = class_no;
		next = NULL;
	}
};
class singly_list{
	
    public:
	node* head;
	node* tail;
	
	singly_list(){
		head = tail = NULL;
	}
	void push( string name ,int age,int class_no){
		node* newnode = new node( age,name,class_no);
		if(head == NULL){
			head = newnode;
		}
		else{
		   newnode->next = head;
		   head= newnode;	
		}
	}
	void pop(){
		if(head == NULL){
			cout<<"LIST IS EMPTY : "<<endl;
			return;
		}
		else{
			node* temp = head;
			head = head->next;
			delete temp;
		}
	
	}
	void display(){
		node* temp = head;
		if(head == NULL){
						cout<<"LIST IS EMPTY : "<<endl;
 return;
		}
	else{
		while(temp != NULL){
			cout<<temp->name<<" "<<temp->age<<" "<<temp->class_no<<endl;
			temp = temp->next;
		}
		}
	}
};
 int main(){
 	singly_list s1;
 	s1.push("Ali",20,12);
 	 	s1.push("Ahmad",20,12);
 	s1.push("Hassan",20,12);
   s1.display();
 	return 0;
 }
