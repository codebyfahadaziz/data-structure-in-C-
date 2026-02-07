#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ 
vector<int> arr = {1,8,6,2,5,4,8,3,7};
int n =arr.size();
  int i = 0;
  int j = n-1;
  vector<int> area;
  while(i<j){
  	int w =j-i;
  	int h =min(arr[i],arr[j]);
  	area.push_back(h*w);
  	if(arr[i]>arr[j]){
  		j--;
	  }
	  else{
	  	i++;
	  }
  }
  int num =area.size();
  int k =area[0];
  for(int i = 0;i<num;i++){
  	if(area[i] > k){
  		k =area[i];
	  }
  }
  cout<<k;
  
  
return 0;
}
