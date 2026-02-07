#include<iostream>
#include<string>
using namespace std;
int main(){
		 			  int count =0;

	string days[5] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
	string user_day;
	
	    string times[5][8] = {
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"},  // Monday
        {"8:00 - 8:50", "8:50 - 9:40", "9:40 - 10:30", "10:30 - 11:20", "11:20 - 12:10", "12:10 - 1:00", "1:00 - 1:50", "1:50 - 2:40"},     // Tuesday
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"},  // Wednesday
        {"9:00 - 9:50", "9:50 - 10:40", "10:40 - 11:30", "11:30 - 12:20", "12:20 - 1:10", "1:10 - 2:00", "2:00 - 2:50", "2:50 - 3:40"},     // Thursday
        {"8:30 - 9:20", "9:20 - 10:10", "10:10 - 11:00", "11:00 - 11:50", "11:50 - 12:40", "12:40 - 1:30", "1:30 - 2:20", "2:20 - 3:10"}    // Friday
    };
    
	string time_table[5][8] ={{"Free","DSA","Free","Pro_and_Stats","CN","CN_lab","CN_lab","CN_lab"},
	                          {"DSA","CN","Pro_and_Stats","Free","Software Eng","IS_lab","IS_lab","IS_lab"},
	                          {"DSA_LAB","DSA_LAB","DSA_LAB","DSA","Free","Free","Free","Free"},
	                          {"IS","Free","Software Engn","Pro_and_Stats","Free","AP","AP","AP"},
	                          {"IS","Software Engn","AP_LAB","AP_LAB","AP_LAB","Free","Free","Free"}};
	                          
     string room_table[5][8] = {
        {"---", "6405", "---", "6323", "6323", "IT-Lab-1", "IT-Lab-1", "IT-Lab-1"},
        {"6323", "6323", "6323", "---", "6323", "IT-Lab-2", "IT-Lab-2", "IT-Lab-2"},
        {"IT-Lab-1", "IT-Lab-1", "IT-Lab-1", "6402", "---", "---", "---", "---"},
        {"6404", "---", "6404", "6404", "---", "6405", "6405", "6405"},
        {"6404", "---", "6404", "PHYSICS-LAB", "PHYSICS-LAB", "---", "---", "---"}
    };
	                          
	cout<<"PLEASE ENTER A DAY : "<<endl;
	cin>>user_day;
	 for(int i=0;i<user_day.length();i++){
	 	user_day[i] = tolower(user_day[i]);
	 
	 
}
	  int day_index = -1;
	 
	      for (int i = 0; i < 5; i++) {
        string temp = days[i];
        for (int j = 0; j < temp.length(); j++)
            temp[j] = tolower(temp[j]);

        if (user_day == temp)
            day_index = i;
    }

	 if(day_index == -1){
	 	cout<<"INVALID DAY : "<<endl;
	 }
	 	else{

	 		cout<<"CLASS ROUTINE OF : "<<days[day_index];
	 		cout<<endl;
	 			 			cout<<"Slot\t\Time\t\tSubject\t\t\Room"<<endl;
                            cout<<"-----------------------------------------------"<<endl;
	 		  for (int j = 0; j < 8; j++) {
            cout << j + 1 << "\t" << times[day_index][j] << "\t";

            if (time_table[day_index][j].length() < 8)
                cout << time_table[day_index][j] << "\t\t";
            else
                cout << time_table[day_index][j] << "\t";

            cout << room_table[day_index][j] << endl;

            if (time_table[day_index][j] == "Free")
                count++;
        }
    }

		 cout<<"TOTAL NUMBER OF FREE SLOTS ON : "<<days[day_index]<<" is :"<<count;
	 
	return 0;
}
