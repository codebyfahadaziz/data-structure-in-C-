#include<iostream>
using namespace std;
int main(){
	int matrics[3][3] ={
	 {1,2,3}
	,{4,5,6}
	,{7,8,9}
	};
	cout<<"Orignal matrics :"<<endl;
	for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
          cout<<matrics[i][j]<<" ";
	}
	cout<<endl;
}

	cout<<"Transpose matrics :"<<endl;
	for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
			          cout<<matrics[j][i] <<" ";
}
	cout<<endl;
}
	cout<<"image rotate :"<<endl;
	for(int i=0;i<3;i++){
			for(int j=2;j>=0;j--){
			          cout<<matrics[j][i] <<" ";
}
	cout<<endl;
}
	return 0;
}
