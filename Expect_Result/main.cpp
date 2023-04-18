#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Num_Players;
int Count_Teams=0;
class Player{
private:
    string name;
    char injury;
    int age,rate,goals,First_Team_Rate,Second_Team_Rate,Player_Rate;
public:
    void Set_name(string n)
    {
        name=n;
    }
    void Set_age(int a)
    {
        if (a>5&&a<50)
        { 
            age=a;
        }
        else
        {
            system("cls");
            again:
            int a;
            cout<<"Something went wrong!!"<<endl;
            cout<<"Enter the age again: ";
            cin>>a;
            if (a>5&&a<50)
            {
                age=a;
            }
            else 
            {
                system("cls");
                goto again;
            }

        }
    }
    void Have_Injury(char i)
    {
        if(i=='y'||i=='Y'||i=='n'||i=='N')
        {
            injury=i;
        }
        else 
        { 
            system("cls");
            again:
            char t;
            cout<<"Invalid choice!!"<<endl<<"Do you suffer from an injury? (y/n)";
            cin>>t;
            if(t=='y'||t=='Y'||t=='n'||t=='N')
            {
                injury=i;
            }
            else 
            {
                system("cls");
                goto again;
            }
        }
    
    }
    void Set_Rate(int r)
    {
        if (r>=0)
        {
            rate=r;
        }
        else 
        {
            again:
            int t;
            cout<<"Something went wrong!! check your rate again and try again: ";
            cin>>t;
            if (t>=0)
            {
                rate=t;
            }
            else 
            {
                system("cls");
                goto again;
            }

        }
    }
    void Set_Goals(int g)
    {
        if (g>=0)
        {
            goals=g;
        }
        else 
        {
            again:
            int t;
            cout<<"Something went wrong!! Try again: ";
            cin>>t;
            if (t>=0)
            {
                goals=t;
            }
            else 
            {
                system("cls");
                goto again;
            }
        }
    }
    void Rating(char injury,int age,int rate,int goals,int j,int Num_Players)
    {
        
        int f,s;
        if (j=1)
        {
            if (injury=='y'||injury=='Y' )
            {
                Player_Rate=((age+rate+goals)/3)-10;
            }
            else
            {
                Player_Rate=((age+rate+goals)/3);
            }
            f+=Player_Rate;
            First_Team_Rate+=f/Num_Players;
        }
        else
        {
            if (injury=='y'||injury=='Y' )
            {
                Player_Rate=((age+rate+goals)/3)-10;
            }
            else
            {
                Player_Rate=((age+rate+goals)/3);
            }
            s+=Player_Rate;
            Second_Team_Rate+=s/Num_Players;

        }
    }
    void Result(){
        if (First_Team_Rate>Second_Team_Rate)
        {
            cout<<"First team is the winner!!"<<endl;
        }
        else if (Second_Team_Rate>First_Team_Rate)
        {
            cout<<"Second team is the winner!!"<<endl;
        }
        else
        {
            cout<<"You points are the same!!";
        }
        
    }
};
int main(){
    Player info[Num_Players];
    for (int j=1;j<=2;j++)
    {
        cout<<"Number of #"<<j<<" team number: ";
        cin>>Num_Players;
        system("cls");
        for(int i=0;i<Num_Players;i++)
        {
            string name;
            char injury;
            int age,rate,goals;
            cout<<"Name of #"<<i+1<<": ";
            cin>>name;
            info->Set_name(name);
            system("cls");
            cout<<name<<" enter your age: ";
            cin>>age;
            info->Set_age(age);
            system("cls");
            cout<<"Do you suffer from an injury? (y/n)";
            cin>>injury;
            info->Have_Injury(injury);
            system("cls");
            cout<<name<<" Ente your rate: ";
            cin>>rate;
            info->Set_Rate(rate);
            system("cls");
            cout<<"How many goals did your score "<<name;
            cin>>goals;
            info->Set_Goals(goals);
            system("cls");
            info->Rating(injury,age,rate,goals,j,Num_Players);
        }
    }
        for (int i=0;i<1;i++)
        {
            info->Result();
        }
    system("pause");
}