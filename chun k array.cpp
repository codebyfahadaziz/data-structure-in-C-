#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr ={1,2,3,4,5};
	int target = 3;
	for(int i=0;i<target;i++){
		cout<<"["<<arr[i]<<","<<"]";
	}

	return 0;
}
