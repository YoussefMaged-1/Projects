#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<pair<int,int>,int>,string>m; //map check on the year number and choose the nearest date...if equal then check the month...if equal check day
    map<pair<pair<int,int>,int>,string>::iterator it;
    pair<pair<int,int>,int> p1; // for year ,month ,day
    pair<int,int>p2;//for year,month 
    string name;//reservation name
    int *i=(int*)calloc(1,1);
    i=0;
    for(int i=0;i<3;i++){
        cout<<"Reservation Name: ";
        cin>>name;
        cout<<"Date: ";
        scanf("%d%*c%d%*c%d",&p1.second,&p2.second,&p2.first);
        p1.first=p2;
        m[p1]=name;
    }
    cout<<"\n\n"<<"Dates: \n";
    for(it=m.begin();it!=m.end();it++){
        cout<<i<<")"<<endl;
        cout<<(*it).second<<"   "<<(*it).first.second<<"/"<<(*it).first.first.second<<"/"<<(*it).first.first.first<<endl;
        i++;

    }
    system("pause");
    


}