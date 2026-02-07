#include<iostream>
using namespace std;
int main(){
	int fib1= 0,fib2=1,result=0;
	int input = 5;
	for(int i=1;i<=input;i++){
		cout<<fib1<<" ";
		result = fib1 + fib2;
		fib1=fib2;
		fib2=result;
	}
	return 0;
}
