//  bubble sorting
#include<iostream>
using namespace std;
void bubble_sorting(int arr[] , int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = 0;
		     	temp = 	arr[j];
		     	arr[j] = arr[j+1];
		     	arr[j+1] = temp;
			}
		}
	}
}

void display(int arr[] , int n){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
	int n=5;
	int arr[n] = {5,4,2,3,1};
	bubble_sorting(arr,n);
	display(arr,n);
	return 0;
}
