#include<iostream>
using namespace std;
int main(){
	int k = 3;
		int arr[4] = {1,2,3,1};

	int n = 4;

	bool flag = false;
	for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
		if(arr[i]==arr[j]  &&  (i-j)<=k){
			flag =true;
		}
	}
}
		cout<<flag;
	
	
	return 0;
}
