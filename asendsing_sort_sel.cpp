//  selection sorting
#include<iostream>
using namespace std;
void selection_sort(int arr[] , int n){
	int smallest,temp;
	for(int i=0;i<n-1;i++){
		smallest = i;
		for(int j=i+1;j<n;j++){
	     if(arr[j] > arr[smallest]){
	     			smallest = j;

		 }
		}
		 temp = arr[smallest];
		 arr[smallest] = arr[i];
		arr[i] = temp;
	}
}
void display(int arr[] , int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n=5;
	int arr[n] = {2,5,8,9,1};
	selection_sort(arr, n);
	display(arr, n);
	return 0;
}
