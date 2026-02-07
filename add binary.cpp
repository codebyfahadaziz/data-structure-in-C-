#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
 int binary_to_decimal(int num){
 	    int i = 0;
    int answer = 0;
    while(num > 0) {
           int bit = num % 10;            
        answer = answer + bit * pow(2, i);
        num = num / 10;               
        i++;
    }
    return answer;
 }
int main() {    
     int sum =binary_to_decimal(100) + binary_to_decimal(100);
     vector<int> rem;
      while(sum>0){
      	rem.push_back(sum % 2);
      	sum = sum/2;
	  }
     for(int i=rem.size()-1;i>=0;i--){
     	cout<<rem[i];
	 }
	return  0;
}
