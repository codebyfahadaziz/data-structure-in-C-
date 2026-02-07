#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    vector<int> result;
	    int arr[3][3] = {
        {2, 2, 3},
        {5, 4, 2},
        {23, 5, 13}
    };
    
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		        if ((i == j || i + j == 2) && isPrime(arr[i][j])) {

			    result.push_back(arr[i][j]);
	}
}
}
sort(result.begin(),result.end());
cout<<result[result.size()-1];


	return 0;
}
