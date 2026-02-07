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
class list{
	public:
		node* head;
		node* tail;
		list(){
			head= tail = NULL;
		}
		void push_back(int val){
			node* newnode = new node(val);
			if(head == NULL){
				head = tail = newnode;
			}
			else {
				tail->next = newnode;
				tail= newnode;
				
			}
		}
		void push_front(int val){
				node* newnode = new node(val);
			if(head == NULL){
				head = tail = newnode;
			}
			else {
				newnode->next =head;
				head= newnode;
				
			}
		}
		void insert_specific_position(){
			int count = 0,pos,val1;
			cout<<"PLEASE ENTER POSITION :"<<endl;
			cin>>pos;
			cout<<"PLEASE ENTER VALUE :"<<endl;
			cin>>val1;
			node* temp = head;
			node* newnode = new node(val1);
			while(temp!=NULL){
				count++;
				temp=temp->next;
			}
		
			if(pos<1 || pos>count +1){
				cout<<"INVALID POSTION :"<<endl;
				delete newnode;
				return;
			}
			else{
				if(pos==1){
					newnode->next = head;
					head = newnode;
				if (tail == NULL) tail = newnode; // ?? if list was empty

				}
				else{
					node* temp1 = head;
					for(int i=1;i<pos-1;i++){
					temp1 = temp1->next;
					}
					newnode->next =temp1->next;
					temp1->next = newnode;
					if(newnode->next == NULL){
						tail = newnode;
					}	
				}
			}
		}
		
		//delete first element
		void delete_first(){
			if(head == NULL) return;
			node* temp = head;
			head = head->next;
			delete temp;
					if (head == NULL) tail = NULL; // ?? update tail if list becomes empty

		}
				//delete last element
	void delete_last() {
		if (head == NULL) return; // ?? handle empty list
		if (head->next == NULL) { // ?? only one node
			delete head;
			head = tail = NULL;
			return;
		}
		node* temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		tail = temp;
	}

		void search(int key){
			node* temp =head;
			int pos = 0;
			bool found= false;
			while(temp != NULL){
				if(temp->data == key){
					cout<<"Value : "<<key<<"found at the position at :"<<pos<<endl;
					found = true;
					break;
				}
				temp= temp->next;
				pos++;	
			}
				if(!found){
					cout<<"Value :"<<key<<" Not found"<<endl;
				}
		}
		// ?? Delete node at a specific position
void delete_specific_position() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) { // delete first node
        node* del = head;
        head = head->next;
        delete del;
        if (head == NULL) tail = NULL; // list became empty
        cout << "Node deleted at position 1" << endl;
        return;
    }

    node* prev = head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }

    node* del = prev->next;
    prev->next = del->next;

    if (del == tail) { // if deleting last node
        tail = prev;
    }

    delete del;
    cout << "Node deleted at position " << pos << endl;
}

	
		void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next; // ?? FIX: move inside loop
		}
		cout << endl;
	}
};

int main(){
	list l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(80);

	
	l1.push_front(2);
	l1.push_front(5);
l1.display();
  // l1.specific_pos(3);
   l1.search(80);
   cout<<endl;
 
   
      cout<<"DELETED THE LAST ELEMENT :"<<endl;
      l1.delete_last();
   l1.display();
cout<<"DELETE FIRST ELEMENT :"<<endl;
   l1.delete_first();
   l1.display();
  
    l1.insert_specific_position();

    l1.display();
    
    l1.delete_specific_position();

    l1.display();


   return 0;  
}
