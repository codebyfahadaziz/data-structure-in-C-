#include<iostream>
using namespace std;
  void	reverse_string( string &str, int target){
  	int k = target -1;
	char temp = str[k];
    str[k] = str[k - 1];
    str[k - 1] = temp;
    cout<<str;
  }

int main(){
	string str = "abcdefgh";
		int target=2;

	reverse_string(str, target)
	
	return 0;
}

