#include<iostream>
using namespace std;

 void bubble_sort(int arr[], int n){
 	 for(int i=0;i<n-1;i++){
 	 	for(int j=0;j<n-i-1;j++){
 	 		if(arr[j] < arr[j+1]){
 	 			int temp = 0;
 	 			temp = arr[j];
 	 			arr[j] = arr[j+1];
 	 			arr[j+1] = temp;
			  }
		  }
 	 	
	  }
 }
 void display(int arr[], int n){
 	 	 for(int i=0;i<n;i++){
 	 	 	cout<<arr[i]<<" ";
}
cout<<endl;
 }
int main(){

int n= 10;
int arr[n] = {2,4,6,7,1,3,5,8,9,10};
cout<<"BEFORE SORTING : "<<endl;
display(arr,n);
cout<<"AFTER SORTING : "<<endl;

bubble_sort(arr,n);
display(arr,n);
	return 0;
}
