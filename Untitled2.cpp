#include<iostream>
using namespace std;

class quene{
	public:
	static const int max_sixe = 5;
	int sixe;
	int rear;
	int front;
	int arr[max_sixe];
	 quene(){
	 	rear = -1;
	 	sixe = 0;
	 	front = 0;
	 }
	bool is_full(){
		return sixe == max_sixe;
	}
	bool is_empty(){
		return sixe == 1;
	}
	void inquene(int val){
	   if(is_full()){
	   	cout<<"QUENE IS FULL OR OVERFLOW : ";
	   	return ;
	   }
	   else{
	   	rear = rear +1 % max_sixe;
	   	arr[rear] = val;
	   	sixe++;
	   }	
	}
	
		void dequene(int val){
	   if(is_empty()){
	   	cout<<"QUENE IS EMPTY OR UNDERFLOW : ";
	   	return ;
	   }
	   else{
	   	rear = rear +1 % max_sixe;
	   	arr[rear] = val;
	   	sixe--;
	   }	
	}
	void display(){
		if(sixe == 0){
			return;
		}
		else{
		for(int i=0;i<sixe;i++)	{
			cout<<arr[i]<<" ";
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
	q1.inquene(6);

	q1.display();
	
	
	
	return 0;
}
