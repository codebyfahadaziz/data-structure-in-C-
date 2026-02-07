#include<iostream>
using namespace std;
int main(){
	int num,reverse = 0,digit = 0;
	cout<<"please enter number : "<<endl;
	cin>>num;
	 while(num!=0){
	 	digit = num % 10;
	 	reverse = reverse * 10 + digit;
	 	num = num / 10;
	 }
	 	 	if(num == reverse){
	 	 		cout<<"True";
			  }
			  else{
			  	cout<<"False";
			  }
return 0;
}

