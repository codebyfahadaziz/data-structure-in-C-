#include<iostream>
#include<math.h>
using namespace std;
int main(){
		int num = 0;

	cout<<"PLEASE ENTER YOUR NUMBER : "<<endl;
	cin>>num;
	int sign = 1;
	if(num<0){
			num = abs(num);
			sign = -1;
	}
   int reverse = 0,digit;
	while(num != 0){
	digit = num % 10;
	if(digit != 0){
			reverse = reverse * 10 +digit;

	}
	num = num / 10;
	}
	cout<<"your reverse number is :"<<reverse * sign;
	return 0;
}
