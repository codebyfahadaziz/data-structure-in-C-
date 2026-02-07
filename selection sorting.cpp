// selewction sorting
#include<iostream>
using namespace std;
     
     
     void selection_sorting(int arr[] , int n){
     	int smallest = 0 , temp = 0;
     	for(int i=0; i<n-1;i++){
     		smallest = i;
     		for(int j=i+1;j<n;j++){
     			if(arr[j]<arr[smallest])
     			smallest = j;
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
  cout<<endl;
}
int main(){
	int n = 10;
		int arr[n] = {5,8,7,10,2,3,4,1,9,6};

	cout<<"BEFORE SELECTION SORTING : "<<endl;
	  	  	for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	cout<<"AFTER SELECTION SORTING : "<<endl;
	selection_sorting(arr,n);
	display(arr,n);
	return 0;
}
