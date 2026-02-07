#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>   // for isalnum, tolower

using namespace std;
bool valid_palindrom(string& str){
		string clean ="";
   string reverse;
       for (int i = 0;i<str.length() -1;i++){
   if(isalnum(str[i])){
   	clean +=tolower(str[i]);
   }
}


    for (int i = clean.length() -1; i>=0;i--){
    	reverse += clean[i];
	}
   if(reverse == clean ){
   	return true ;
   	
   }
   else{
   	   	return false ;

}
}

  int main(){
  	   string str = "A man, a plan, a canal: Panama \0";
    cout<<valid_palindrom(str);
  		return 0;

  }

