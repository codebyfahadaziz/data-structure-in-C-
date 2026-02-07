#include<iostream>
#include <variant>  
using namespace std;
int main(){
       	int num;
       		cout<<"PLEASE EBNTER NUMBER : "<<endl;

	if(num>0){
			int digit,reverse;
	cin>>num;
			while(num!=0){
		digit = num % 10;
		reverse = digit * 10 +digit;
		num = num / 10;
	}
	cout<<reverse;
	
	} 
	if(num<0){
		   variant<int, char> data = num;  
		   cout<<"numbers : "<<get<int>data;
	}

	
	return 0;
}
