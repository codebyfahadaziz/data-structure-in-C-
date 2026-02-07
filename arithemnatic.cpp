#include<iostream>
using namespace std;
int main(){
int n=5;
	int arr[n] = {1,3,5,7,9};
	bool found = false;
	int diff;
		diff= arr[1] - arr[0] ;

	for(int i=0;i<n-1[];i++){
		if(arr[i+1] - arr[i] != diff){
			cout<<"ARRAY IS  NOT ARITHMETIC : "<<endl;
			found = true;
			break;
		}
	}
	if(!found){
		cout<<"ARRAY IS ARITHEMATIC : "<<endl;
	}
	return 0;
}
