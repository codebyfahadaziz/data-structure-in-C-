#include<iostream>
using namespace std;
class stack{
	int size;
	int top;
	int* arr;
	public:
		stack(int s){
			size = s;
			top = -1;
			arr = new int(s);
		}
		void push(int value){
			if(top == size-1){
				cout<<"STACK IS OVERFLOW :"<<endl;
				return;
			}
			else{
				top++;
				arr[top] = value;
			}
		}
		void pop(){
			if(top == -1){
				cout<<"STACK IS UNDERFLOW :"<<endl;
				return;
			}
			else{
				top--;
			}
		}
		void display(){
			
		}
};
int main(){

   stack st(5);
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
    return 0;
}
   
