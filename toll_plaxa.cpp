#include<iostream>
#include<iomanip>
using namespace std;
 
int exit_car = 0;


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
   	int size;
   	node* front;
   	node* rear;
   	quene(){
   		front = rear = NULL;
   		size = 0;
	   }
	   void push(int val){
	   	if(val == 999){
	   		push_emergency(val);
	   		return;
		   }
	   	    node* newcar = new node(val);//push back
	   	    if(front == NULL){
	   	    	  front =rear = newcar;
	   	    	  size++;
			   }
			   else{
			   	rear->next = newcar;
			   	rear = newcar;
		     	  size++;
			   }
	   }
	   void pop(){
	   	node* temp = front;
	   	front=front->next;
	   	exit_car = temp->data;
	   	delete temp;
	   }

	   void display(){
	   	node* temp = front;
	   	while(temp != NULL){
	   		        cout << setw(4) << temp->data;  // Fixed width for each car

	   		temp = temp->next;
		   }
	   }
	   
  int get_count(){
            int cot = 0;
            node* temp = front;
            while(temp != NULL){
                cot++;
                temp = temp->next;
            }
            return cot;
        }
 

void push_emergency(int val){
    node* newnode = new node(val);   // Create node correctly

    if(front == NULL){
        front = rear = newnode;
    }
    else{
        newnode->next = front;       // Insert at front
        front = newnode;
    }

    size++;                          // Increase size
}

};
class node1{
	public:
		int data;
		node1* next;
		node1(int val){
			data = val;
			next = NULL;
		}
};

class stack{// push front
public:
	node* top; 
	stack(){
		top = NULL;
	}
	void push(){
		node* newnode = new node(exit_car);
		if(top == NULL){
			top =  newnode;
		}
		else{
			newnode->next = top ;
			top = newnode;
		}
	}
	  int get_count(){
            int cot = 0;
            node* temp = top;
            while(temp != NULL){
                cot++;
                temp = temp->next;
            }
            return cot;
        }
	
	
	
  void display(){
  	node* temp = top;
  	while( temp != NULL){
  		        cout << setw(4) << temp->data;  // Fixed width for each car

  		temp = temp->next;
	  }
  }	
};
void displayLane(int laneNumber, quene &q, stack &s) {
    cout<< laneNumber << "\t";

    // Display Entry Queue
    q.display();
    cout <<"\t\t";

    // Display Exit Stack
    s.display();
    cout <<"\t";
    // Display Total Cars (entry + exit)
    int total = q.get_count() + s.get_count();
    cout << total << endl;
}

int main(){
	quene q1;	stack s1;//  lane 1

	quene q2; 	stack s2;//  lane 2

	quene q3;	stack s3;//  lane 3

	quene q4;	stack s4;//  lane 4


// lane 1 cars
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(999);
	 
	q1.pop();
	s1.push();
 
	q1.pop(); 
	s1.push();

// lane 2 cars

	q2.push(999);
	q2.push(7);
	q2.push(8);
	q2.push(9);
	q2.push(10);
	 
	q2.pop();
	s2.push();
 
	q2.pop(); 
	s2.push();

 // lane 3 cars


	q3.push(11);
	q3.push(12);
	q3.push(999);
	q3.push(14);
	q3.push(15);
	 
	q3.pop();
	s3.push();
 
	q3.pop(); 
	s3.push();
	  
 // lane 4 cars

	q4.push(16);
	q4.push(17);
	q4.push(18);
	q4.push(19);
	q4.push(20);
	 
	q4.pop();
	s4.push();
 
	q4.pop(); 
	s4.push();
	
 // DISPLAY CARS
	
cout << "Lane\tENTER CARS\t\tExit CARS\tTOTAL CARS" << endl;
cout << "-----------------------------------------------------------" << endl;

displayLane(1, q1, s1);
displayLane(2, q2, s2);
displayLane(3, q3, s3);
displayLane(4, q4, s4);



	return 0;
}
