#include<iostream>
using namespace std;
class stack{
	int top;
	int size;
	int* arr ;
	public:
		stack(int s){
		  size = s;
		  top = -1;
		  arr = new int[s];	
		}
		void push(int value){
			if(top == size-1 ){
			
				cout<<"stack overflow..."<<endl;
				return;
				
			}
			else{
				top++;
				arr[top] = value;
				
			}
		}
		void pop(){
			if(size == -1){
				cout<<"stack is under flow :"<<endl;
			}
			else{
				top--;
			}
		}
		int peak_value(){
			if(top == -1){
				cout<<"STACK IS EMPTY :"<<endl;
			}
			else{
				return arr[top];
			}
		}
		bool empty(){
			return top == -1;
		}
		int is_size(){
			return top+1;
		}
		void display(){
			if(top == -1){
				cout<<"STACK IS EMPTY :"<<endl;
			return;
			}
			else{
				for(int i=top;i>=0;i--){
					cout<<arr[i]<<" ";
				}
			}
		}
		void palindrome(){
							bool found = false;
			for(int i=0;i<=top/2;i++){
				if(arr[i] != arr[top - i]){
					found = true;
					break;
				}	
			}
			if(found){
				cout<<"STACK IS NOT PALINDROME: "<<endl;
			}
			else{
					cout<<"STACK IS PALINDROME: "<<endl;

			}
		}
};
int main(){
	stack s(5);
	     	cout<<"BEFORE POP :"<<endl;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(1);

	s.display();

	s.palindrome();
	
	return 0;
}
