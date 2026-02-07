#include<iostream>
#include<vector>

using namespace std;
int main(){
	vector<int> arr = {4,6,7,9,1,35,45};
    n =	arr.size();
	   for(int i=0;i<n-2;i++){
	   	for(int j=0;j<n-1;j++){
	     for(int k=0;k<n;k++){
             if(arr[i] + arr[j] + arr[k] == 0){
             	cout<<i<<" "<<j<<" "<<" "<<k;
			 }
		}
 
	   }
}
return 0;
}
