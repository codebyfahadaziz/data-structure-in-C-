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
    			head = tail =NULL;
			}
			void push_front(int val){
				node* newnode = new node(val);
				if(head == NULL){
					head = tail = newnode;
					tail-> next = newnode;
				}
				else{
					tail ->next = newnode;
					tail = newnode;
					tail ->next = head;
				}
			}
	 void display() {
        node* temp = head;

        // If list empty, do nothing
        if (head == NULL) return;

        // ? FIX 2: Use do-while until we reach head again (not NULL)
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main(){
	list l1;
	l1.push_front(12);
	l1.push_front(100);
	l1.display();
	return 0;
}
