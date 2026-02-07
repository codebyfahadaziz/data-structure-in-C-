// Online C++ compiler to run C++ program onli
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 void binarySearch(vector<int>& arr ,int target){
 	    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr.size() - 1;
   while(start<=end){
      int mid = (start + end) / 2;
       if(target>arr[mid]){
           start = mid +1;
       }
       else if(target<arr[mid]){
           end =mid -1;
       }
       else {
           cout<<mid;
           break;
       }
   }
 }
int main(){
    vector<int> arr = {1,4,6,8,9,10,3,6,7,9};
    int target = 6;

     binarySearch(arr,target);
	return 0;
}
