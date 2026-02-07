#include<iostream>
using namespace std;
class quene{
	public:
	static const int max_Size = 5;
	int front;
	int rear;
	int size;
	int arr[max_Size];
	
	quene(){
		front = 0;
		rear = -1;
		size = 0;
	}
	bool is_full(){
		return size == max_Size;
	}
	bool is_empty(){
		return size == 0;
	}
	void inquene(int val){
	if(is_full()){
		cout<<"QUENE IS FULL :"<<endl;
		return ;
	}	
	else{
	  rear = (rear +1) % max_Size;
	  arr[rear] = val;
	  size++;
	}
	}
	
	void dequene(){
		if(is_empty()){
		cout<<"QUENE IS EMPTY : "<<endl;
		return;	
		}
		else{
			front = (front +1) % max_Size;
			size--;
		}
	}
	void display(){
		if(is_empty()){
			cout<<"QUENE IS EMPTY : "<<endl;
			return ;	
		}
		else{
			for(int i=0;i<size;i++){
				cout<<arr[(front + i) % max_Size]<<" ";
			}
		}
	}
};
int main(){
	quene q1;
	q1.inquene(1);
	q1.inquene(2);
	q1.inquene(3);
	q1.inquene(4);
	q1.inquene(5);
    q1.display();
    
    
cout<<endl;
    q1.dequene();
   
			q1.display();

    
	return 0;
}
