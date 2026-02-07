#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> rem;
	int num ;
	cout<<"PLEASE ENTER THE NUMBER :"<<endl;
	cin>>num;
	while(num>0){
		rem.push_back(num % 2);
		num = num / 2;
	}
	cout<<"Binary number :"<<endl;
	for (int i = 0;i<rem.size();i++){
		cout<<rem[i];
	}
	return 0;
}
