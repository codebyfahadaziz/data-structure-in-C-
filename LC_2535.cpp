#include<iostream>
using namespace std;
int main(){
	int arr[5] = {0,2,3,45,5};
	int sum = 0;
	for(int i=0;i<5;i++){
		sum = sum + arr[i];
	}
	cout<<"SUM OF ARRAY IS : "<<sum;
	int digit;
	int sum1;

	for(int i=0;i<5;i++){ 
      while(arr[i]> 0){

     digit =	arr[i] % 10 ;
     
     sum1 = sum1 + digit;
     arr[i] = arr[i] /10;
    
	 }
}
	 cout<<endl;
	 cout<<sum1;
	 	 cout<<endl;

	 cout<<"DIFFERENCE IS : "<<sum - sum1;
	return 0;
}
