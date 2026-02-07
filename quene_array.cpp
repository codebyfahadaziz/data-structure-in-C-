#include<iostream>
using namespace std;
class quene{
	int front;
	int rear;
	int capacity;
	int* arr;
	public:
		quene(int c){
			capacity = c;
			front = rear = -1;
			 arr = new int[capacity];
		}
		bool is_empty(){
			return front == -1;
		}
	   bool is_full(){
	   	return rear == capacity -1;
	   }
	   void push(int val){
	   	if(is_empty()){
	   		front = rear = 0;
	   		arr[0]  = val;
		   }
		   else if(is_full()){
		   	cout<<"QUENE IS OVERFLOW : "<<endl;
		   	return;
		   }
		  
		   else{
		   	rear++;
		   	arr[rear] = val;
		   }
	   }
	   void pop() {
    if (is_empty()) {
        cout << "QUEUE IS UNDERFLOW : " << endl;
        return;
    }

    // If only one element left
    if (front == rear) {
        front = rear = -1; // Reset queue
    } else {
        front++;
    }
}

	   void display(){
	   	for(int i=front;i<=rear;i++){
	   		cout<<arr[i]<<" ";
		   }
	   }
};

int main(){
	quene q1(5);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	
q1.display();

q1.pop();
cout<<endl;
q1.display();

	return 0;
}











