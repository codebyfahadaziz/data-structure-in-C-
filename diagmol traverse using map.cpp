#include<iostream>
using namespace std;
int main(){
    int n = 3, m = 3;
    int arr[m][n] = {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> result;
    // 1) Diagonals starting from top row
    for (int sum = 0; sum<5; sum++) {
    	for(int i=m-1;i>=0;i--){
    		int j =i-sum;
    		if(j>=0 && i<m){
    			    		     result.push_back(arr[i][j]);

			}
        }
    }
    for(int i=0;i<reslt.size();i++){
    	cout<<result[i]<<" ";
	}
       
	return 0;
}
