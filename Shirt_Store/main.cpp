#include <bits/stdc++.h>
#include<cctype>
#include<windows.h>

using namespace std;

fstream boyWinter("Boys Winter.txt");
fstream girlWinter("Girls Winter.txt");
fstream boySummer("Boys Summer.txt");
fstream girlSummer("Girls Summer.txt");

int *version=(int*)calloc(1,sizeof(int));
int *gender=(int*)calloc(1,sizeof(int));

string checkPassword()
{
    string input;
    cout<<"\t\tAdmin Password: ";
	HANDLE hStdInput
		= GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;

	// Create a restore point Mode
	// is know 503
	GetConsoleMode(hStdInput, &mode);

	// Enable echo input
	// set to 499
	SetConsoleMode(
		hStdInput,
		mode & (~ENABLE_ECHO_INPUT));

	// Take input
	string ipt;
	getline(cin, ipt);

	// Otherwise next cout will print
	// into the same line
	cout << endl;

	// Restore the mode
	SetConsoleMode(hStdInput, mode);

	return ipt;
}

void showVersion(int v){
    system("cls");
    if(v==1)
        cout<<"\t\t* * * * * * * * * * * * * * * * *\n"
              "\t\t*         Summer Mode           *\n"
              "\t\t* * * * * * * * * * * * * * * * *\n\n";
    else
        cout<<"\t\t* * * * * * * * * * * * * * * * *\n"
              "\t\t*         Winter Mode           *\n"
              "\t\t* * * * * * * * * * * * * * * * *\n\n";
}

class addData{
private:
    string name;
    int ID;
public:  

    void setName(string n){
        if (n.size()<=2)
        {
            string newName;
            int w=0;
            while (w!=1){
                system("cls");
                cout<<"\t\tInvalid Name! try again: ";
                getline(cin,newName);
                if (newName.size()>2)
                {
                    w++;
                    name=newName;
                    

                }
            }   
        }
        else 
        {
            name=n;
        }
    }

    bool setID(int id){
        int c=0;
        while(id<=0||id>=500&&c<1)
        {
            showVersion(*version);
            cout<<"\t\tInvalid ID! Try again: ";
            cin>>id;
            if(id>=1||id<=500)
            {
                ID=id;
                c++;  
                return 1;
            }
        }
        ID=id;
        return 1;
    }

    void printToFile(string nameOfFile,fstream & pointer){

        pointer.open(nameOfFile,ios::app|ios::in);
        if(pointer.is_open())
        {
            pointer<<"ID: "<<ID<<endl
            <<"---------------------------------------\n"
            <<"Name: "<<name<<endl
            <<"=======================================\n";
              "=======================================\n";
        }
        else
        {
            showVersion(*version);
        cout<<"\t\tSomething went wrong!!\n";
        system("pause");
        }
        pointer.close();
    }

    void printInfo(){
    boyWinter.close();
    girlWinter.close();
    boySummer.close();
    girlSummer.close();

    //based on mode and gender we choose
    if(*version==1){
        if(*gender==1)
            printToFile("Boys Summer.txt",boySummer);
        else
            printToFile("Girls Summer.txt",girlSummer);
    }

    else if(*version==2){
        if(*gender==1)
            printToFile("Boys Winter.txt",boyWinter);
        else
            printToFile("Girls Winter.txt",girlWinter);
    }
    }
};

class searchData{
private:
    string container;
    vector<string> vecFile;
    int count=0;
public:

    int getCount(){
        return count;
    }

    void searchInFiles(string fileName,fstream & pointer,string id,int justSearch){
        showVersion(*version);
        pointer.close();
        pointer.open(fileName,ios::in);
        if (pointer.is_open())
        {
            while(getline(pointer,container))
            {
                vecFile.push_back(container);
            }
            for (int i=0;i<vecFile.size();i++)
            {
                if (vecFile[i]==id||count<4&&count>0)
                {
                    count++;
                    if(justSearch==1)
                        cout<<vecFile[i]<<endl;
                }
            }
            pointer.close();
        }
        else{
            showVersion(*version);
            cout<<"Something went wrong..Check data Files!!"<<endl;
        }
        
    }

    void checkForSearch(string see,int justSearch){
        count=0;
        if(*version==1){
            searchInFiles("Boys Summer.txt",boySummer,see,justSearch);
            if(count==0)
                searchInFiles("Girls Summer.txt",girlSummer,see,justSearch);
        }
        else if(*version==2){
            searchInFiles("Boys Winter.txt",boySummer,see,justSearch);
            if(count==0)
                searchInFiles("Girls Winter.txt",girlSummer,see,justSearch); 
        }
        if(count==0){
            showVersion(*version);
            cout<<"\t\t\tID Is Not Found in this version !"<<endl;
        }
    }
};

class listInfo{
private:
    vector<string> listData;
    string line;
public:

    void listSize(string fileName,fstream & pointer){
        pointer.close();
        pointer.open(fileName,ios::in);
        if(pointer.is_open()){
            showVersion(*version);
            while(getline(pointer,line)){
                listData.push_back(line);
            }
            if(listData.size()==0){
                showVersion(*version);
                cout<<"\t\tNo One In This Type"<<endl;
            }
            else{
                for(int i=0;i<listData.size();i++){
                    cout<<listData[i]<<endl;
                }
            }
        }
        pointer.close();
    }
};

class deleteData{
private:
    vector<string>vecFile;
    string container;
    int count=0,findMember=0;
public:

    void deletePersons(string nameOfFile,fstream & pointer,string deleted){
        vecFile.clear();
        container="";
        pointer.close();
        pointer.open(nameOfFile,ios::in);
        if (pointer.is_open())
        {   
            while(getline(pointer,container))
            {
                vecFile.push_back(container);
            }
            for (int i=0;i<vecFile.size();i++)
            {
                if (vecFile[i]==deleted)
                {
                    findMember++;
                }
            }
            if(findMember)
            {
                
                ofstream t ("temp.txt");
                fstream temp ("temp.txt");

                for(int i=0;i<vecFile.size();i++){
                    if(vecFile[i]==deleted||count<4&&count>0){
                        count++;
                        continue;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                pointer.close();
                temp.close();
                pointer.open(nameOfFile,ios::out);
                temp.open("temp.txt",ios::in);
                vecFile.clear();
                container="";
                while(getline(temp,container))
                {
                    vecFile.push_back(container);
                }
                for(int i=0;i<vecFile.size();i++){
                    pointer<<vecFile[i]<<endl;
                }
                t.close();
                temp.close();
                remove("temp.txt");
                showVersion(*version);
                cout<<"Deleted Successfully! "<<endl;
                system("pause");
            }
        }  
        else{
            cout<<"Something went wrong with files"<<endl;
        }
        pointer.close();
    }
    
    void searchForPerson(string del){
        if(*version==1){
            deletePersons("Boys Summer.txt",boySummer,del);
            if(findMember==0)
                deletePersons("Girls Summer.txt",girlSummer,del);
        }

        else if(*version==2){
            deletePersons("Boys Winter.txt",boyWinter,del);
            if(findMember==0)
                deletePersons("Girls Winter.txt",girlWinter,del);
        }

        if(findMember==0){
            showVersion(*version);
            cout<<"ID doesn't exist"<<endl;
            system("pause");
        }

    }

};

class more{
private:
    string line;
    vector<string> vecCount;
    int counter=0,overAll=0;
public:

    void countSizes(string fileName,fstream & pointer){
        counter=0;
        vecCount.clear();
        line="";
        pointer.close();
        pointer.open(fileName,ios::in);
        if(pointer.is_open()){
            while(getline(pointer,line)){
                vecCount.push_back(line);
            }
            for(int i=0;i<vecCount.size();i++){
                if (vecCount[i].find("ID: ")!=string::npos){
                    counter++;
                }
            }
            overAll+=counter;
        }
        pointer.close();
    }

    void aboutSizes(){
        if(*version==1){
            countSizes("Boys Summer.txt",boySummer);
            cout<<"\tBoy's T_Shirts: "<<counter<<endl;
            cout<<"\t----------------------------------------"<<endl;
            countSizes("Girls Summer.txt",girlSummer);
            cout<<"\tGirl's T_Shirts: "<<counter<<endl;
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\tOverall you have: "<<overAll<<endl<<endl;
        }
        if(*version==2){
            countSizes("Boys Winter.txt",boyWinter);
            cout<<"\tBoy's T_Shirts: "<<counter<<endl;
            cout<<"\t----------------------------------------"<<endl;
            countSizes("Girls Winter.txt",girlWinter);
            cout<<"\tGirl's T_Shirts: "<<counter<<endl;
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\t----------------------------------------"<<endl;
            cout<<"\tOverall you have: "<<overAll<<endl<<endl;
        }
    }
};

int main() {
    boyWinter.close();
    girlWinter.close();
    boySummer.close();
    girlSummer.close();

    pass:
    if (checkPassword()=="youpro11")
    {
        
        system("cls");
        cout<<
                "\t\t* * * * * * * * * * * * * * * * *\n"
                "\t\t*                               *\n"
                "\t\t*      1)Summer Version         *\n"
                "\t\t*                               *\n"
                "\t\t*      2)Winter Version         *\n"
                "\t\t*                               *\n"
                "\t\t* * * * * * * * * * * * * * * * *\n";
        cout<<"Enter the Mode: ";
        cin>>*version;

        again:

        int *choice=(int*)calloc(1,sizeof(int));
        int *numOfPersons=(int*)calloc(1,sizeof(int));

        showVersion(*version);
        cout<<
                "\t\t* * * * * * * * * * * * * * * * *\n"
                "\t\t*                               *\n"
                "\t\t*      1)Add Shirt              *\n"
                "\t\t*                               *\n"
                "\t\t*      2)Search By ID           *\n"
                "\t\t*                               *\n"
                "\t\t*      3)List                   *\n"
                "\t\t*                               *\n"
                "\t\t*      4)Delete                 *\n"
                "\t\t*                               *\n"
                "\t\t*      5)Statistics             *\n"
                "\t\t*                               *\n"                                
                "\t\t*      6)Change Version         *\n"
                "\t\t*                               *\n"
                "\t\t* * * * * * * * * * * * * * * * *\n";
        cout<<"\t\tChoose number: ";
        while ( !(cin >> *choice))
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\tInvalid input; please re-enter: ";
        }

        if(*choice==1){
            addData data;
            searchData search;
           gender:
            showVersion(*version);
        cout<<
                "\t\t* * * * * * * * * * * * * * * * *\n"
                "\t\t*                               *\n"
                "\t\t*      1)Boys's T_Shirt         *\n"
                "\t\t*                               *\n"
                "\t\t*      2)Girls's T_Shirt        *\n"
                "\t\t*                               *\n"
                "\t\t* * * * * * * * * * * * * * * * *\n";

            while ( !(cin>>*gender))
            {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore();
                cout << "\t\tInvalid input; please re-enter: ";
            }

            showVersion(*version);
            if(*gender==1){
                cout<<"Number of Boys: ";
                while ( !(cin>>*numOfPersons))
                {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.ignore();
                    cout << "\t\tInvalid input; please re-enter: ";
                }

            }

            else if(*gender==2){
                cout<<"Number of Girls:";
                while ( !(cin>>*numOfPersons))
                {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.ignore();
                    cout << "\t\tInvalid input; please re-enter: ";
                }
            }

            else{
                showVersion(*version);
                cout<<"Wrong choice!"<<endl;
                system("pause");
                goto gender;
            }

            for(int i=0;i<*numOfPersons;i++){
                showVersion(*version);
                string name;
                int id;
                cin.ignore();
                cout<<"Name of #"<<i+1<<" :";
                getline(cin,name);
                data.setName(name);
                showVersion(*version);
                id:
                cout<<"ID of "<<name<<":";
                while ( !(cin >> id))
                {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\tInvalid input; please re-enter: ";
                }
                if(data.setID(id)){
                    search.checkForSearch("ID: "+to_string(id),0);
                    if(search.getCount()>=1){
                        showVersion(*version);
                        cout<<"\tThe ID is already registered"<<endl<<"\t";
                        system("pause");
                        goto id;
                    }
                }
                data.printInfo();
            }
        }

        else if(*choice==2){
            searchData search;
            string scan;
            showVersion(*version);
            cout<<"\t\tSearch By ID: ";
            cin>>scan;
            scan="ID: "+scan;
            search.checkForSearch(scan,1);
            system("pause");
        }

        else if(*choice == 3){
            showVersion(*version);
            listInfo show;
            int type;

            cout<<
                "\t\t* * * * * * * * * * * * * * * * *\n"
                "\t\t*                               *\n"
                "\t\t*      1)Boys's T_Shirt         *\n"
                "\t\t*                               *\n"
                "\t\t*      2)Girls's T_Shirt        *\n"
                "\t\t*                               *\n"
                "\t\t* * * * * * * * * * * * * * * * *\n";
            cout<<"\t\tChoose number: ";
            while ( !(cin >> type))
            {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\tInvalid input; please re-enter: ";
            }

            if(*version==1){
                if(type==1)
                    show.listSize("Boys Summer.txt",boySummer);
                else if(type==2)
                    show.listSize("Girls Summer.txt",girlSummer);
            }

            else if(*version==2){
                if(type==1)
                    show.listSize("Boys Winter.txt",boyWinter);
                else if(type==2)
                    show.listSize("Girls Winter.txt",girlWinter);
            }

            else{
                showVersion(*version);
                cout<<"Invalid Choice!!";
                system("pause");
            }
            system("pause");
        }

        else if(*choice == 4){
            showVersion(*version);
            deleteData delt;
            string del;
            cout<<"\t\tDelete By ID: ";
            cin>>del;
            del="ID: "+del;

            delt.searchForPerson(del);
        }

        else if(*choice == 5){
            more stat;
            system("cls");
            stat.aboutSizes();
            cout<<"\t";
            system("pause");
            system("cls");
        }

        else if(*choice==6){
            if(*version==1)
                *version=2;
            else
                *version=1;
        }

        goto again;
    }

    else{
    system("cls");
    cout<<"\t\tWrong Password try again !!"<<endl<<"\t\t";
    system("pause");
    system("cls");
    goto pass;
    }

}