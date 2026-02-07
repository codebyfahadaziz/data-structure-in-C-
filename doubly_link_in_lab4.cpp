#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
	
	node(int val){
		next = NULL;
		prev = NULL;
		data = val;
	}
	};
	class doubly_list{
		public:
			node* head;
			node* tail;
			doubly_list(){
			
				head = tail = NULL;
			}
			void push_front(int val){
				node* newnode = new node(val);
				if(head == NULL){
					head = tail = newnode;
				}
				else{
					newnode->next = head;
				    head->prev =  newnode;
				   	head = newnode;
				}
			}
			
			void push_back(int val){
				node* newnode = new node(val);
				 if(head == NULL){
				 	head = tail = newnode;
				 }
				 else {
				 	tail->next = newnode;
				 	newnode ->prev = tail;
				 	tail = newnode;

				 }
			}
		   
		   void insert_at_specific(){
		   	node* temp = head;
		   	int count = 0;
		   	int val;
		   	int pos;
		   	while(temp != NULL){
		   		count++;
		   		temp = temp->next;
			   }
			   cout<<" ENTER THE INDEX NUMBER THAT YOU WANT INSERT : "<<endl;
			   cin>>pos;
			    cout<<" ENTER THE VALUE THAT YOU WANT INSERT : "<<endl;
			   cin>>val;
			   		   	node * newnode = new node(val);

			   if(pos<1 || pos >count +1){
			   	cout<<"INVALID POSITION : "<<endl;
			   	delete newnode;
			   	return;
			   }
			   else{
			   if(pos == 1){
               newnode->next = head;      // connect new node to old head
    if(head != NULL) head->prev = newnode; // link backward
    head = newnode;            // move head to new node ?
    return;
}

				   else{
				   
			   	node* prev = head;
			   	for(int i=1;i<pos-1;i++){
			   		prev = prev->next;
				   }
				   newnode->next = prev->next;
				   prev->next = newnode;
			}
			   }
		   }
			
			void new_value(int new_val, int pos){
			
				node* temp = head;
				for(int i=1;i<pos;i++){
					temp = temp->next;
				}
				temp->data = new_val;
			}
			void display(){
				node* temp = head;
			while(temp != NULL)
				{
				cout<<temp->data<<" ";
				temp= temp->next;
				}

			}
			
			 void search(int key){
			 	int count = 1;
			 	node* temp = head;
			 	bool found  = false;
			 	while(temp != NULL){
			 		if( temp->data == key){
			 			count++;
			 			found = true;
			 			cout<<"KEY ARE FOUND AT POSITION : "<<count;
			 			return;
					 }
					 temp = temp->next;
					
				 }
				  if(!found){
					 	cout<<"KEY ARE NOT FOUND : "<<endl;
					 }
				 
			 }
					// ?? Delete node at a specific position
   void delete_specific_position() {
    node* temp = head;
    node* del;
    int cot =0;
    while(temp != NULL){
    	cot++;
    	temp= temp->next;
	}
	int pos = 0;
     cout<<"ENTER THE INDEX NUMBER THAT YOU WANT TO DELETE : "<<endl;
     cin>>pos;
    
    if(pos <1 || pos >cot +1){
    	cout<<"YOU ENTER INVALID INPUT : "<<endl;
    	return;
	}
	else{
		if(pos == 1){
			  del = head;
			head  = head->next;
			delete temp;
		}
		else{
			node* prev = head;
			for(int i=1; i<pos-1;i++){
				prev = prev->next;
			}
			del = prev->next;
			prev->next = del->next;
			delete del;
			return;
		}
	}
	}
};
int main(){
	doubly_list l1;
		l1.push_front(50);

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.display();
	l1.insert_at_specific();
		l1.display();
		cout<<endl;
		l1.delete_specific_position();
		l1.display();
		l1.search(10);
		cout<<endl;
		
		l1.new_value(70,2);
				l1.display();


	return 0;
}
