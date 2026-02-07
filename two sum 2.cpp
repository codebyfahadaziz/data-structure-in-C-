#include<iostream>
using namespace std;
int main(){
   vector<int> arr = {5,6,7,8,9,10};
   int n =arr.size();
   int i = arr[i];
   int j =arr[n-1];
   while(i>j){
   	if(arr[i] + arr[j] >target){
   		j--;
	   }
	   else if(arr[i] + arr[j] < target){
	   	i++;
	   }
	   else{
	   	cout<<i+1<<","<<j+1;
	   }
   }
   return 0;
}
