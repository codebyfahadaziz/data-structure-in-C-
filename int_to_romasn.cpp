#include<iostream>
using namespace std;
int main(){
	int num;
	string result;

    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string sym[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	cout<<"PLEASE ENTER THE NUMBER : "<<endl;
	cin>>num;
			for(int i=0;i<=13;i++){
				if(num == 0){
					break;
				}
				while(num>=val[i]){
					num = num -val[i];
					result =result + sym[i];
					
		}
			}
		
		cout<<"roman is : "<<result;
	return 0;
}
