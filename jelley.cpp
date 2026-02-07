//write a code in which set a stack 
#include<iostream>
using namespace std;
class stack{
	public:
	  int top;
	 int sixe;
	  int arr[] = new int[sixe];
	  
	  stack(int s){
	  	 sixe = s;
	  	 top = -1;
	  }
	  void push(int val){
	  	if(top == sixe -1){
	  		cout<<"STACK IS FULL : "<<endl;
	  		return;
		  }
		  else{
		  	top++;
		  	arr[top] = val;
		  }
	  }
	  void pop(){
	  	if(top == -1){
	  		cout<<"STACK IS EMPTY : "<<endl;
	  		return ;
		  }
		  else{
		  	top--;
		  }
	  }
	  void display(){
	  	for(int i=0 ;i<sixe;i++){
	  		cout<<arr[i]<<" ";
		  }
		  cout<<endl;
	  }
	};
int main(){
	stack st(26);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);
      st.display();
	return 0;
}
