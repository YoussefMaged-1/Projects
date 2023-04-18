#include<iostream>
#include<string>
using namespace std;
void Welcom(){
    cout<<"\t\t\t\t---------------Welcom to CMDY----------------"<<endl;
}
void Ping_Site()
{
    string Site_Name;    
    cout<<"Enter the Web Site/host name: ";
    cin.ignore();
    getline(cin,Site_Name);
    system(("ping "+Site_Name).c_str());
    system("pause");
    system("cls");
}
void IP_Adress()
{
    system("ipconfig");
    system("pause");
    system("cls");
}
void System_info()
{
    system("systeminfo");
    system("pause");
    system("cls");
}
int main(){
    start:
    system("cls");
    Welcom();
    char x=0;
    cout<<"What do you want?"<<endl;
    cout<<"1)Ping"<<endl<<"2)IP Adress"<<endl<<"3)System info"<<endl;
    cin>>x;
    system("cls");
    if (x=='1')
    {
        Ping_Site();
    }

    else if (x=='2')
    {
        IP_Adress();
    }

    else if (x=='3')
    {
        System_info();
    }

    goto start;
}