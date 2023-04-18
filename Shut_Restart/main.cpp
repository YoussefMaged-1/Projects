
#include <iostream> 
//#include <stdlib.h>
using namespace std; 
int main() 
{
    again:
    system("cls");
	cout<<"-------Welcome-------"<<endl;
	cout<<"[S]hutdown"<<endl;  
	cout<<"[R]estart"<<endl;   
	cout<<"[L]ogoff"<<endl;   
	char choice;  
	
	cin>>choice;
	 
	if(choice=='S' || choice=='s'){
		cout<<"Shutting down..."<<endl;
       system("c:\\windows\\system32\\shutdown /s"); 
     }
	else if(choice=='R' || choice=='r'){
		cout<<"Restarting..."<<endl;
	   system("c:\\windows\\system32\\shutdown /r"); 
     }
	else if(choice=='L' || choice=='l'){
		cout<<"Logging off..."<<endl;
	   system("c:\\windows\\system32\\shutdown /l"); 
     }
	else{
        system("cls");
	    cout<<"Command not valid. Enter valid command"<<endl; 
        system("pause");

    }
        goto again;          

} 