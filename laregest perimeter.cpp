#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int perimeter(vector<int> &arr){
	sort(arr.begin(),arr.end());
	int n =arr.size();
	if(arr[n-1] +arr[n-2] > arr[n-3]){
		int add = arr[n-1] +arr[n-2] + arr[n-3];
   return add;
}
	}
int main(){
	int arr[] = {2,4,5,6,3);
	return 0;
}
