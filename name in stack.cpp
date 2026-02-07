#include<iostream>
using namespace std;
class stack{
	int top;
	int size;
	char* arr ;
	public:
		stack(int s){
		  size = s;
		  top = -1;
		  arr = new char[s];	
		}
		void push(char value){
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
			if(top == -1){
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
	
};
int main(){
	stack s(5);

	s.push('d');
	s.push('a');
	s.push('h');
	s.push('a');
	s.push('f');
	s.push('a');

	s.display();

	cout<<endl;
	s.pop();

		s.display();

	return 0;
}
