#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;
int main(){
	vector<int> arr = {6,2,4,6,3,4};
   set<int> unique(arr.begins(),arr.ends());
   for(int val : unique){
   	cout<<val<<" ";
   }
	return 0;
}
