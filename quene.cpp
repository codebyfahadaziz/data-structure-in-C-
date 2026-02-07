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
		node* rare;
		quene(){
		rare = front = NULL;
		}
	 void enqueue(int val) {
        node* newnode = new node(val);
        
        // If queue is empty
        if (rare == NULL) {
            front = newnode;
            rare = newnode;
        }
        // If queue has elements
        else {
            rare->next = newnode;
            rare = newnode;
        }
    }
	  void dequene(){
	  	
		  
		  		node* temp = front;
		front = front->next;
		delete temp;
	
		}
		void display(){
					node* temp = front;
               while(temp != NULL){
               	cout<<temp->data<<" ";
               	temp= temp->next;
			   }
			   cout<<endl;
		}
};

 int main(){
 	quene q1;
 	q1.enqueue(1);
 	q1.enqueue(2);
 	q1.enqueue(3);
 	q1.enqueue(4);
 	q1.enqueue(5);

q1.display();
q1.dequene();
q1.display();
 	return 0;
 }
 
 

