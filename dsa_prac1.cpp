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
             head = NULL;
             tail = NULL;
         }
         void push_front(int val){
             node* newnode = new node(val);
             if (head == NULL){
                 head = newnode;
                 tail = newnode;
             }
             else{
             	newnode->next = head;
             	head = newnode;
             }
         }
         void display(){
         	node* temp = head;
         	while(temp != NULL){
         		cout<<temp->data<<" ";
         		temp = temp->next;
             }
         	cout<<endl;
         }
         void search(int target){
         	node* temp = head;
         	while(temp != NULL){
         		if(temp->data == target){
         			cout<<"TARGET IS FOUND : "<<endl;
         			return;
                 }
                 temp = temp->next;
                
             }
            cout<<"TARGET IS NOT FOUND :"<<endl;
         }
 };
 int main(){
     list l1;
     l1.push_front(5);
     l1.push_front(4);
     l1.push_front(3);
     l1.push_front(2);
     l1.push_front(1);
     cout<<"YOUR SINGLY LIST :"<<endl;
     l1.display();
     
    int target = 0;
     cout<<"please enter your target : "<<endl;
     cin>>target;
     l1.search(target);
     return 0;
 }
