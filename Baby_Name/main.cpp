#include <iostream>
#include <string>
#include <vector>
using namespace std;
class info {
private:
public:
    vector<string> MomNames,Momthings,DadNames,Dadthings;
    void SetMom(vector<string> n,vector<string> t)
    {
        MomNames=n;
        Momthings=t;
    }
    void SetDad(vector<string> n,vector<string> t)
    {
        DadNames=n;
        Dadthings=t;
    }

};
class SetBabyName:public info{
public:
        vector<string> BestForDad;
        vector<string> BestForMom;
    void Mom()
    {   
        int counter=0;
        for (int i=0;i<MomNames.size();i++)
        for (int j=0;j<MomNames[i].size();j++)
        {
            int c=0;
            if (MomNames[i][j]==Momthings[i][j])
            {
                c++;
                if (c>counter)
                {
                counter=c;
                BestForMom.push_back(MomNames[i]);
                }
            }
        }
    }
    void Dad()
    {   
        int counter=0;
        for (int i=0;i<DadNames.size();i++)
        for (int j=0;j<DadNames[i].size();j++)
        {
            int c=0;
            if (DadNames[i][j]==Dadthings[i][j])
            {
                c++;
                if (c>counter)
                {
                counter=c;
                BestForDad.push_back(DadNames[i]);
                }
            }
        }
    }
    void ShowResults()
    {
        if (BestForMom.size()>=1)
        {
            cout<<endl<<endl<<"The Best Names for Mom is: ";
            for (int i=0;i<BestForMom.size();i++)
                cout<<i+1<<")"<<BestForMom[i]<<endl;
        }
        if (BestForDad.size()>=1)
            cout<<endl<<endl<<"The Best Names for Dad is: ";
        for (int i=0;i<BestForDad.size();i++)
            cout<<i+1<<")"<<BestForDad[i]<<endl;
    }
};
int main (){
    int m,d;
    SetBabyName intro;
    cout<<"How many names from mom: ";
    cin>>m;
    cout<<"How many names from dad: ";
    cin>>d;
    cout<<"Mom enter your fav names:"<<endl;
    vector <string> MomNs;
    for (int i=0;i<m;i++)
    { 
        string name;
        cout<<i+1<<")";
        cin>>name;
        MomNs.push_back(name);
    }

    cout<<"Dad enter your fav names:"<<endl;
    vector <string> DadNs;
    for (int i=0;i<d;i++)
    { 
        string name;
        cout<<i+1<<")";
        cin>>name;
        DadNs.push_back(name);
    }
    
    cout<<"Enter things you both love"<<endl;
    cout<<"Mom things: "<<endl;
    vector<string> MomTh;
    for (int i=0;i<m;i++)
    {
        string y;
        cout<<i+1<<")";
        cin>>y;
        MomTh.push_back(y);
        
    }
    cout<<"Dad things: "<<endl;
    vector<string>DadTh;
    for (int i=0;i<d;i++)
    {
        string y;
        cout<<i+1<<")";
        cin>>y;
        DadTh.push_back(y);
    }
    intro.SetMom(MomNs,MomTh);
    intro.SetDad(DadNs,DadTh);
    intro.Mom();
    intro.Dad();
    intro.ShowResults();
    char z;
    cin>>z;
}