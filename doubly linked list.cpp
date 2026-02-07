// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    public:
    node(int val){
        data = val;
        next = prev = NULL;
    }
};
class doubly_list{
    public:
    node* head;
    node* tail;
    doubly_list(){
        head = tail= NULL;
    }
    void push_front(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            newnode->prev = head;
            head  = newnode;
        }
    }
    void push_back(int val){
         node* newnode = new node(val);
         if(tail == NULL){
             tail = newnode;
         }
         else {
             tail->next= newnode;
             newnode->prev =tail;
             tail = newnode;
         }
    }
        void display(){
            node* temp = head;
            if(temp == NULL) return;
            while(temp !=NULL){
                cout<<temp->data<<" ";
                temp= temp->next;
            }
            cout<<endl;
        }
};
int main() {
   doubly_list d1;
    cout<<"PUSH front";
  cout<<endl;

   d1.push_front(1);
   d1.push_front(2);
   d1.push_front(3);
   d1.push_front(4);
   d1.push_front(5);
  d1.display();
 
 cout<<endl;
 cout<<"PUSH BACK";

    return 0;
}
