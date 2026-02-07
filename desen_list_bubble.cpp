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
			head =tail = NULL;
		}
		void push(int val){
			node* newnode = new node(val);
			if(head == NULL){
				head =tail = newnode;
			}
			else{
				tail->next = newnode;
				tail = newnode;
			}
		}
		void display(){
			node* temp = head;
			while(temp != NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
	
	    void sorting(){
        if(head == NULL) return;

        node* i;
        node* j;
        int temp;

        for(i = head; i != NULL; i = i->next){
            for(j = i->next; j != NULL; j = j->next){
                if(i->data < j->data){
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
		};
		
		
		int main(){
			list l1;
			cout<<"BUBBLE SORTING IN LINKED LIST :"<<endl;
			cout<<"BEFORE SORTING : "<<endl;
			l1.push(4);
			l1.push(2);
			l1.push(3);
			l1.push(1);
			l1.push(5);
			l1.push(9);
			l1.push(10);
			l1.push(5);
			l1.push(5);
			l1.push(5);

			l1.display();
			cout<<endl;
						cout<<"AFTER SORTING : "<<endl;

			l1.sorting();
						l1.display();

        return 0;
        
		}
