#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<int> arr = {2, 1, 5, 3, 4};
      int n =arr.size();

   //to find left max
   vector<int> left_max(n);
   left_max[0] = arr[0];
   for(int i=1;i<n;i++){
   	left_max[i] =max(left_max[i-1],arr[i]);
   }
   cout<<"Left max"<<endl;
      for(int i=0;i<n;i++){
      	cout<<left_max[i]<<" ";
      }
      cout<<endl;
         //to find right max
   vector<int> right_max(n);
   right_max[n-1] = arr[n-1];
   for(int i=n-2;i>=0;i--){
   	right_max[i] =max(right_max[i+1],arr[i]);
   }
   cout<<"Right max"<<endl;
      for(int i=0;i<n;i++){
      	cout<<right_max[i]<<" ";
      }
      cout<<endl;
    int sum =0;
    for (int i=0;i<n;i++){
        int h = min(left_max[i],right_max[i]) - arr[i];
        sum += max(0, h);   // avoid negative values
    }

    cout << "Total trapped water = " << sum << endl;
    return 0;
}
    

