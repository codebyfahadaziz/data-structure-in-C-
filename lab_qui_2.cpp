#include<iostream>
using namespace std;
class stack{
	public:
		int size;
		int top;
		 int* arr;
		 stack(int s){
		 	size = s;
		 	top =-1;
		 	arr = new int[s];
		 }
		 
		 void push(int val){
		 	if(top == size-1){
		 		cout<<"STACK IS OVERFLOW : "<<endl;
		 		return;
			 }
			 else{
			 	top++;
			 	arr[top] = val;
			 }
		 }
		 int peek(){
		 	if(top == -1){
		 		cout<<"STACK IS EMPTY : "<<endl;
		 		return 0;
			 }
			 else{
			 					return arr[top];

			 }
		 }
		 void pop(){
		 	if(top == -1){
		 		cout<<"stack is under flow : "<<endl;
		 		return;
			 }
			 else{
			 	top--;
			 }
		 }
		 void display(){
		 	for(int i=0;i<=top;i++){
		 		cout<<arr[i]<<" ";
			 }
		 }
};
int main(){
	
	 stack s1(6);
    int choice, value;

    // Pre-filled values (optional)
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
 do {
 
        cout << "\n==============================\n";
        cout << "MENU DRIVEN STACK PROGRAM\n";
        cout << "1. DISPLAY STACK\n";
        cout << "2. SEE TOP VALUE\n";
        cout << "3. PUSH NEW VALUE\n";
        cout << "4. POP VALUE\n";
        cout << "5. EXIT\n";
        cout << "==============================\n";
        cout << "PLEASE ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s1.display();
            break;

        case 2:
            s1.peek();
                s1.display();

            break;

        case 3:
            cout << "ENTER VALUE TO PUSH: ";
            cin >> value;
            s1.push(value);
                s1.display();

            break;

        case 4:
            s1.pop();
                s1.display();

            break;

        case 5:
            cout << "EXITING PROGRAM..." << endl;
            break;

        default:
            cout << "INVALID CHOICE!" << endl;
        }
    } while (choice != 5);

    return 0;
}

