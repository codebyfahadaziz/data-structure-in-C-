#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n = 5;
	int arr[n] = {2,3,5,1,3};
	 int ex_candies = 3;
	 sort(arr.begin(),arr.end());
	  int max = arr[n-1];
	  for(int i=0;i<n;i++){
	  	if(arr[i] + ex_candies >= max ){
	  		cout<<true;
		  }
		  else{
		  		  		cout<<false;

		  }
	  }
	return 0;
}
