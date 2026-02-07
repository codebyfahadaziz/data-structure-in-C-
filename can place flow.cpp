#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr{1,0,1,0,1};
	int count = 0;
	    int n = arr.size();

    int	target = 1;
	for(int i=1;i<n-1;i++){
		if( arr[i] ==0 && arr[i-1] == 0 && arr[i+1] == 0){
			count++;	
		}
	}
	if(count == target){
		cout<<"true";
	}
	else {
		cout<<"false";
	}
	return 0;
}
