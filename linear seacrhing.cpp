#include<iostream>
#include<vector>
using namespace std;
void linearSearch(vector<int> arr,int target){
	for(int i=0;i<=arr.size();i++){
		if(target == arr[i]){
			cout<<"YOUR TARGET POSITION IS : "<<i<<endl;
		}
	}
}
int main(){
	int se = 8;
	int target =10;
  vector<int> arr = {9,5,3,7,8,0,10,21};
     linearSearch(arr,target);
	return 0;
}
