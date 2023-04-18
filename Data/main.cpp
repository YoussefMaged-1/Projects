#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<limits>
#include<cctype>
#include<windows.h>
using namespace std;
fstream S("S_Size.txt");
fstream M("M_Size.txt");
fstream L("L_Size.txt");
fstream XL("XL_Size.txt");
fstream XXL("XXL_Size.txt");

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

class addData{
private:
    string name, cellNumber,secondCellNumber, address, shirtSize,dateOfBirth;
    int ID;
public:

    //constructor
    addData(){
        secondCellNumber="No Family Number";
        address="No Address";
        dateOfBirth="No Date";
    }   

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

    void setMainNumber(string mainPhone){

        again:
        if(mainPhone.size()<=13&&mainPhone.size()>10){
            cellNumber=mainPhone;
        }
        else
        {
            cout<<"\t\tInvalid Phone number! try again: ";
            cin>>mainPhone;
            goto again;
        }
    }

    void setSecondNumber(string second){
        again:
        if(second.size()<=13&&second.size()>0){
            secondCellNumber=second;
        }
         else
        {
            cout<<"\t\tInvalid Phone number! try again";
            cin>>second;
            goto again;
        }
    }

    void setAddress(string add){
        check:
        if(add.size()>=2||add.size()<30){
            address=add;
        }
        else{
            system("cls");
            cout<<"\t\tInvalid address! enter the address again: ";
            getline(cin,add);
            goto check;
        }
    }

    void setShirtSize(string size){
        again:

            for (int i=0;i<size.size();i++)
            {
                size[i]=toupper(size[i]);
            }

            if (size =="S")
            {
                shirtSize="S";
            }

            else if(size=="M")
            {
                shirtSize="M";
            }

            else if(size=="L")
            {
                shirtSize="L";
            }

            else if(size=="XL")
            {
                shirtSize="XL";
            }

            else if(size=="XXL")
            {
                shirtSize="XXL";
            }

            else 
            {
                
                cout<<"\t\tInvalid shirt size! try again: ";
                getline(cin,size);
                goto again;
                
                
            }

    }

    bool setID(int id){
        int c=0;
        while(id<=0||id>=500&&c<1)
        {
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

    void setDate(){
        int day,month,year;
        newDate:
        system("cls");
        cout<<"\t\tEnter "<<name<<"'s date of birth: ";
        while ( !(scanf("%d%*c%d%*c%d",&day,&month,&year)))
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout<<"\tEnter "<<name<<"'s date of birth: ";
        }
        if( day>=1 && day<=31 && month>=1 && month<=12 && year>1900 && year<2022){                
                dateOfBirth=to_string(day);
                dateOfBirth+="/";
                dateOfBirth+=to_string(month);
                dateOfBirth+="/";
                dateOfBirth+=to_string(year);
        }
        else{
            system("cls");
            cout<<"\tInvalid date !!try again ";
            system("pause");
            goto newDate;
        }
    }

    void print(string nameOfFile,string size,fstream & pointer){

        pointer.open(nameOfFile,ios::app|ios::in);
        if(pointer.is_open())
        {
            pointer<<"ID: "<<ID<<endl
            <<"---------------------------------------\n"
            <<"Name: "<<name<<endl
            <<"---------------------------------------\n"
            <<"Shirt Size: "<<size<<endl
            <<"---------------------------------------\n"
            <<"Phone Number: "<<cellNumber<<endl
            <<"---------------------------------------\n"
            <<"Family Number: "<<secondCellNumber<<endl
            <<"---------------------------------------\n"
            <<"Address: "<<address<<endl
            <<"---------------------------------------\n"
            <<"Date of Birth: "<<dateOfBirth<<endl
            <<"=======================================\n"
            <<"=======================================\n"
            <<"=======================================\n";
        }
        else
        {
        cout<<"\t\tSomething went wrong!!\n";
        system("pause");
        }
        pointer.close();
    }

    void printToFile(){
        S.close();
        M.close();
        L.close();
        XL.close();
        XXL.close();
        if(shirtSize=="S")
        {
            print("S_Size.txt","Small",S);
        }

        else if(shirtSize=="M"){
            print("M_Size.txt","Medium",M);
        }

        else if(shirtSize=="L"){
            print("L_Size.txt","Large",L);
        }
        else if(shirtSize=="XL"){
            print("XL_Size.txt","XLarge",XL);
        }

        else if(shirtSize=="XXL"){
            print("XXL_Size.txt","XXLarge",XXL);
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
        //using this function to know if ID number repeated or not while doing update or new one
        return count;
    }

    void search(string fileName,fstream & pointer,string id,int justSearch){
        system("cls");
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
                if (vecFile[i]==id||count<14&&count>0)
                {
                    count++;
                    if(justSearch==1)
                        cout<<vecFile[i]<<endl;
                }
            }
        }
        pointer.close();
    }

    void searchSmall(string sea,int justSearch){
        count=0;
        search("S_Size.txt",S,sea,justSearch);
        if(count==0){
            searchMedium(sea,justSearch);
        }
    }

    void searchMedium(string sea,int justSearch){
        search("M_Size.txt",M,sea,justSearch);
        if(count==0){
            searchLarge(sea,justSearch);
        }
    }

    void searchLarge(string sea,int justSearch){
        search("L_Size.txt",L,sea,justSearch);
        if(count==0){
            searchXL(sea,justSearch);
        }
    }

    void searchXL(string sea,int justSearch){
        search("XL_Size.txt",XL,sea,justSearch);
        if(count==0){
            searchXXL(sea,justSearch);
        }
    }

    void searchXXL(string sea,int justSearch){
        search("XXL_Size.txt",XXL,sea,justSearch);
        if(count==0){
            system("cls");
            cout<<"\t\t\tID Is Not Found!"<<endl;
        }
    }
};

class updateData: public searchData{
private:
    string correct_word,container,dateOfBirth;
    vector<string> vecFile;
    int count=0,stop=0,find=0,findMember=0,wrong=0,ID,Date,day,month,year,sel;
public:

    int getSelect(){
        return sel;
    }

    void showOptions(){
        updateData up;
        string word;
        int select;
        cout<<"\t\tUpdate By ID: ";
        cin>>word;
        word="ID: "+word;
        system("cls");
                cout<<
            "\t\t* * * * * * * * * * * * * * * * *\n"
            "\t\t*                               *\n"
            "\t\t*      1)Update Name            *\n"
            "\t\t*                               *\n"
            "\t\t*      2)Update ID              *\n"
            "\t\t*                               *\n"
            "\t\t*      3)Update Phone Number    *\n"
            "\t\t*                               *\n"
            "\t\t*      4)Update Family Number   *\n"
            "\t\t*                               *\n"
            "\t\t*      5)Update Address         *\n"
            "\t\t*                               *\n"
            "\t\t*      6)Update Date of Birth   *\n"
            "\t\t*                               *\n"
            "\t\t*      7)Update Shirt Size      *\n"
            "\t\t*                               *\n"
            "\t\t* * * * * * * * * * * * * * * * *\n";
    cout<<"\t\tSelect number: ";
        while ( !(cin >> select))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\tInvalid input; please re-enter: ";
        }
        if(select<=7&&select>0){
            up.updateSmall(word,select);
        }
        else {
            system("cls");
            cout<<"\t\tWrong Choice!! "<<endl;
            system("pause");
            return ;
            
        }
    }

    void deleteMember(string word,string fileName,fstream &pointer){
        container="";
        vecFile.clear();
        pointer.open(fileName,ios::in|ios::app);
        ofstream d ("del.txt");
        fstream del("del.txt");
        if (del.is_open())
        {   
            while(getline(pointer,container))
            {
                vecFile.push_back(container);
            }
            for (int i=0;i<vecFile.size();i++)
            {
                if (vecFile[i]==word)
                {
                    findMember++;
                }
            }
            if(findMember)
            {
                for(int i=0;i<vecFile.size();i++){
                    if(vecFile[i]!=word){

                        del<<vecFile[i]<<endl;
                    }
                    else{
                        for(int j=0;j<=13;j++){
                            i++;
                        }
                    }

                }
                pointer.close();
                del.close();
                d.close();
                pointer.open(fileName,ios::out);
                del.open("del.txt",ios::in);
                vecFile.clear();
                container="";
                while(getline(del,container))
                {
                    vecFile.push_back(container);
                }
                for(int i=0;i<vecFile.size();i++){
                    pointer<<vecFile[i]<<endl;
                }
                del.close();
                d.close();
                pointer.close();
                remove("del.txt");
            }
        }
    }

    void choice(int select,string word){
        sel=select;
        cin.ignore();
        if(select==1){
            upName(word);
        }
        else if(select==2){
            upID(word);
        }
        else if(select==3){
            upPhoneNum(word);
        }
        else if(select==4){
            upFamilyNum(word);
        }
        else if(select==5){
            upAddress(word);
        }
        else if(select==6){
            upDate(word);
        }
        else if(select==7){
            upShirtSize(word);
        }
    }

    void findInFile(string fileName,fstream &pointer,string word,int select,string pointerName){        
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        system("cls");
        pointer.close();
        pointer.open(fileName,ios::in|ios::app);
        if (pointer.is_open())
        {   
            while(getline(pointer,container))
            {
                vecFile.push_back(container);
            }
            for (int i=0;i<vecFile.size();i++)
            {
                if (vecFile[i]==word||count<14&&count>0)
                {
                    count++;
                    cout<<"\t\t"<<vecFile[i]<<endl;
                }
            }
            if(count==14){
                choice(select,word);
                pointer.close();
                t.close();
                temp.close();
                if(select==7){
                    pointer.open(fileName,ios::out|ios::app);
                    temp.open("temp.txt",ios::in|ios::app);
                }
                else {
                    pointer.open(fileName,ios::out);
                    temp.open("temp.txt",ios::in);
                }
                vecFile.clear();
                container="";
                while(getline(temp,container))
                {
                    vecFile.push_back(container);
                }
                if(select!=7){
                    for(int i=0;i<vecFile.size();i++){
                        pointer<<vecFile[i]<<endl;
                    }
                    t.close();
                    temp.close();
                    pointer.close();
                    remove("temp.txt");
                    system("cls");
                }
                else if(select==7&&wrong==0&&correct_word!=pointerName){

                    pointer.close();
                    
                    if(correct_word=="S"||correct_word=="SMALL"){
                        S.open("S_Size.txt",ios::out|ios::app);
                        for(int i=0;i<vecFile.size();i++){
                            S<<vecFile[i]<<endl;
                        }
                        S.close();
                    }
                    else if(correct_word=="M"||correct_word=="MEDIUM"){
                        M.open("M_Size.txt",ios::out|ios::app);
                        for(int i=0;i<vecFile.size();i++){
                            M<<vecFile[i]<<endl;
                        }
                        M.close();
                    }
                    else if(correct_word=="L"||correct_word=="LARGE"){
                        L.open("L_Size.txt",ios::out|ios::app);
                        for(int i=0;i<vecFile.size();i++){
                            L<<vecFile[i]<<endl;
                        }
                        L.close();
                    }
                    else if(correct_word=="XL"||correct_word=="XLarge"){
                        XL.open("XL_Size.txt",ios::out|ios::app);
                        for(int i=0;i<vecFile.size();i++){
                            XL<<vecFile[i]<<endl;
                        }
                        XL.close();
                    }
                    else if(correct_word=="XXL"||correct_word=="XXLarge"){
                        XXL.open("XXL_Size.txt",ios::out|ios::app);
                        for(int i=0;i<vecFile.size();i++){
                            XXL<<vecFile[i]<<endl;
                        }
                        XXL.close();
                    }
                    deleteMember(word,fileName,pointer);
                    t.close();
                    temp.close();
                    remove("temp.txt");
                    system("cls");
                }
            }
        }
        else{
            cout<<"\t\tThere's Something Went Wrong with data!!"<<endl;
        }
    }
    
    void upName(string word){
        
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New Name: ";
        getline(cin,correct_word);
        if(correct_word.size()>1){
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("Name: ")!=string::npos){
                        temp<<"Name: "+correct_word<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }
    
    void upID(string word){
        
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New ID: ";
        while ( !(cin >> ID))
            {
                system("cls");
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\tInvalid input; please re-enter: ";
            }
        searchSmall("ID: "+to_string(ID),0);
        if(ID>0&&getCount()==0){

            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("ID: ")!=string::npos){
                        temp<<"ID: "+to_string(ID)<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }
    
    void upPhoneNum(string word){
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New Phone Number: ";
        getline(cin,correct_word);
        if(correct_word.size()<=13&&correct_word.size()>10){
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("Phone Number: ")!=string::npos){
                        temp<<"Phone Number: "+correct_word<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }

    void upFamilyNum(string word){
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New Family Number: ";
        getline(cin,correct_word);
        if(correct_word.size()<=13&&correct_word.size()>10){
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("Family Number: ")!=string::npos){
                        temp<<"Family Number: "+correct_word<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }

    void upAddress(string word){
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New Address: ";
        getline(cin,correct_word);
        if(correct_word.size()>2){
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("Address: ")!=string::npos){
                        temp<<"Address: "+correct_word<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }

    void upDate(string word){
        ofstream t ("temp.txt");
        fstream temp ("temp.txt");
        cout<<"\t\tEnter The New Date of Birth: ";
        while ( !(scanf("%d%*c%d%*c%d",&day,&month,&year)))
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout<<"Enter The New Date of Birth: ";
        }
        if( day>=1 && day<=31 && month>=1 && month<=12 && year>1900 && year<2022){                
            dateOfBirth=to_string(day);
            dateOfBirth+="/";
            dateOfBirth+=to_string(month);
            dateOfBirth+="/";
            dateOfBirth+=to_string(year);
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                stop++;
                if(stop>0&&stop<=14)
                {
                    if(vecFile[i].find("Date of Birth: ")!=string::npos){
                        temp<<"Date of Birth: "+dateOfBirth<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
                else{
                    temp<<vecFile[i]<<endl;
                }
                }
        }
        else{
            for(int i=0;i<vecFile.size();i++){
                temp<<vecFile[i]<<endl;
            }
            wrong++;
        }
        t.close();
        temp.close();
    }
    
    void upShirtSize(string word){
        cout<<"\t\tEnter The New Shirt Size: ";
        getline(cin,correct_word);
        for (int i=0;i<correct_word.size();i++)
        {
            correct_word[i]=toupper(correct_word[i]);
        }
        if(correct_word=="S"||correct_word=="M"||correct_word=="L"||correct_word=="XL"||correct_word=="XXL"){

            ofstream t ("temp.txt");
            fstream temp ("temp.txt");
            //writing the only info of ID
            for(int i=0;i<vecFile.size();i++){
                if(vecFile[i]==word)
                    find++;
                if(find>0&&stop<=14)
                {
                    stop++;
                    if(vecFile[i].find("Size: ")!=string::npos){
                        temp<<"Size: "+correct_word<<endl;
                    }
                    else{
                        temp<<vecFile[i]<<endl;
                    }
                }
            }
            t.close();
            temp.close();
        }
        else{
            wrong ++;
        }

    }
    
    
    void updateSmall(string word,int select){
        vecFile.clear();
        container="";
        S.close();
        findInFile("S_Size.txt",S,word,select,"S");
        S.close();
        if(count==0){
            updateMedium(word,select);
        }
        else{
            if(select!=7&&count>0&&wrong==0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else if (select==7&&wrong==0&&count>0){
                cout<<"\tUpdated Successfully! "<<endl;
                cout<<"\t";
                system("pause");
            }
            else{
                cout<<"\tInvalid Update!"<<endl<<"\t";
                remove("temp.txt");
                cout<<"\t";
                system("pause");
            }
            
            }
    }

    void updateMedium(string word,int select){
        M.close();
        vecFile.clear();
        container="";
        findInFile("M_Size.txt",M,word,select,"M");
        M.close();
        if(count==0){
            updateLarge(word,select);
        }
        else{
            if(select!=7&&count>0&&wrong==0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else if (select==7&&wrong==0&&count>0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else{
                cout<<"\tInvalid Update!"<<endl<<"\t";
                remove("temp.txt");
                system("pause");
            }
            
            }
    }

    void updateLarge(string word,int select){
        L.close();
        vecFile.clear();
        container="";
        findInFile("L_Size.txt",L,word,select,"L");
        L.close();
        if(count==0){
            updateXL(word,select);
        }
        else{
            if(select!=7&&count>0&&wrong==0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else if (select==7&&wrong==0&&count>0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else{
                cout<<"\tInvalid Update!"<<endl<<"\t";
                remove("temp.txt");
                system("pause");
            }
            
            }
    }

    void updateXL(string word,int select){
        XL.close();
        vecFile.clear();
        container="";
        findInFile("XL_Size.txt",XL,word,select,"XL");
        XL.close();
        if(count==0){
            updateXXL(word,select);
        }
        else{
            if(select!=7&&count>0&&wrong==0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else if (select==7&&wrong==0&&count>0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else{
                cout<<"\tInvalid Update!"<<endl<<"\t";
                remove("temp.txt");
                system("pause");
            }
            }
    }

    void updateXXL(string word,int select){
        XXL.close();
        vecFile.clear();
        container="";
        findInFile("XXL_Size.txt",XXL,word,select,"XXL");
        XXL.close();
        if(count==0){
           system("cls");
           cout<<"\tID Is NOt Found!! "<<endl<<"\t";
           system("pause");
        }
        else{
            if(select!=7&&count>0&&wrong==0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else if (select==7&&wrong==0&&count>0){
                cout<<"\tUpdated Successfully! "<<endl<<"\t";
                system("pause");
            }
            else{
                cout<<"\tInvalid Update!"<<endl<<"\t";
                remove("temp.txt");
                system("pause");
            }
            }
    }

};

class list{
private:
    vector<string> listData;
    string line;
public:

    void listSize(string fileName,fstream & pointer){
        pointer.close();
        pointer.open(fileName,ios::in);
        if(pointer.is_open()){
            system("cls");
            while(getline(pointer,line)){
                listData.push_back(line);
            }
            if(listData.size()==0){
                system("cls");
                cout<<"\t\tNo One In This Size"<<endl;
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
                    if(vecFile[i]==deleted||count<=15&&count>0){
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
                system("cls");
                cout<<"Deleted Successfully! "<<endl;
            }
        }  
        else{
            cout<<"Something went wrong with files"<<endl;
        }
        pointer.close();
    }

    void deleteSmall(string deleted){
        deletePersons("S_Size.txt",S,deleted);
        if(findMember==0){
            deleteMedium(deleted);
        }
        else {
            system("cls");
            cout<<"\t\tDeleted Successfully!"<<endl;
        }
    }

    void deleteMedium(string deleted){
        deletePersons("M_Size.txt",M,deleted);
        if(findMember==0){
            deleteLarge(deleted);
        }
        else {
        system("cls");
        cout<<"\t\tDeleted Successfully!"<<endl;
        }
    }

    void deleteLarge(string deleted){
        deletePersons("L_Size.txt",L,deleted);
        if(findMember==0){
            deleteXLarge(deleted);
        }
        else {
        system("cls");
        cout<<"\t\tDeleted Successfully!"<<endl;
        }
    }

    void deleteXLarge(string deleted){
        deletePersons("XL_Size.txt",XL,deleted);
        if(findMember==0){
            deleteXXLarge(deleted);
        }
        else {
        system("cls");
        cout<<"\t\tDeleted Successfully!"<<endl;
        }
    }

    void deleteXXLarge(string deleted){
        deletePersons("XXL_Size.txt",XXL,deleted);
        if(findMember==0){
            system("cls");
            cout<<"\t\tID IS Not Found"<<endl;
        }
        else {
        system("cls");
        cout<<"\t\tDeleted Successfully!"<<endl;
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
        countSizes("S_Size.txt",S);
        cout<<"\tIn Small Size: "<<counter<<endl;
        cout<<"\t----------------------------------------"<<endl;
        countSizes("M_Size.txt",M);
        cout<<"\tIn Medium Size: "<<counter<<endl;
        cout<<"\t----------------------------------------"<<endl;
        countSizes("L_Size.txt",L);
        cout<<"\tIn Large Size: "<<counter<<endl;
        cout<<"\t----------------------------------------"<<endl;
        countSizes("XL_Size.txt",XL);
        cout<<"\tIn XLarge Size: "<<counter<<endl;
        cout<<"\t----------------------------------------"<<endl;
        countSizes("XXL_Size.txt",XXL);
        cout<<"\tIn XXL Size: "<<counter<<endl;
        cout<<"\t----------------------------------------"<<endl;
        cout<<"\t----------------------------------------"<<endl;
        cout<<"\tOverall you have: "<<overAll<<endl<<endl;
    }
};

int main(){
    S.close();
    M.close();
    L.close();
    XL.close();
    XXL.close();
    pass:
    if (checkPassword()=="ym11t")
    {
        start:
        system("cls");
        int addPersons=0;
        string choice;
        cout<<
                "\t\t* * * * * * * * * * * * * * * * *\n"
                "\t\t*                               *\n"
                "\t\t*      1)Add new member         *\n"
                "\t\t*                               *\n"
                "\t\t*      2)Update data            *\n"
                "\t\t*                               *\n"
                "\t\t*      3)Search By ID           *\n"
                "\t\t*                               *\n"
                "\t\t*      4)List                   *\n"
                "\t\t*                               *\n"
                "\t\t*      5)Delete                 *\n"
                "\t\t*                               *\n"                                
                "\t\t*      6)Statistics             *\n"
                "\t\t*                               *\n"
                "\t\t* * * * * * * * * * * * * * * * *\n";
        cout<<"\t\tChoose number: ";
        cin>>choice;
        if(choice=="1")
        {
            
            cout<<"\t\thow many persons will you add?\n";
            cout<<"\t\t";
            while ( !(cin >> addPersons))
                {
                    cin.clear(); //clear bad input flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                    cout << "\t\tInvalid input; please re-enter: ";
                }

            addData newData[addPersons]; 
            searchData search[addPersons];
            for (int i=0;i<addPersons;i++){
                string name, cellNumber,secondCellNumber, address, shirtSize;
                int ID,day,month,year;
                system("cls");
                cin.ignore();
                cout<<"\tEnter the #"<<i+1<<" name: ";
                getline(cin,name);
                newData[i].setName(name);

                system("cls");
                again:
                char secondNum;
                cout<<"Enter "<<name<<"'s phone number: ";
                getline(cin,cellNumber);
                if(cellNumber.size()>0){
                    newData[i].setMainNumber(cellNumber);
                }
                else{
                    system("cls");
                    cout<<"Please check that you add phone number \n";
                    goto again;
                }
                system("cls");
                cout<<"if "<<name<<" has second number / family number enter (Y)/(N): ";
                cin>>secondNum;
                cin.ignore();
                if(secondNum=='y'||secondNum=='Y')
                {
                    system("cls");
                    cout<<"\t\tEnter the second number: ";
                    getline(cin,secondCellNumber);
                    newData[i].setSecondNumber(secondCellNumber);
                }
                    
                system("cls");
                char haveAdd;
                cout<<"Do you have "<<name<<"'s address ? (Y)/(N)";
                cin>>haveAdd;
                if(haveAdd=='y'||haveAdd=='Y')
                {
                    system("cls");
                    cin.ignore();
                    cout<<"\t\tenter "<<name<<"'s address: ";
                    getline(cin,address);
                    newData[i].setAddress(address);
                }
                else
                cin.ignore();
                system("cls");
                cout<<"\t\tShirt size: ";
                getline(cin,shirtSize);
                for (int i=0;i<shirtSize.size();i++)
                {
                    shirtSize[i]=toupper(shirtSize[i]);
                }
                newData[i].setShirtSize(shirtSize);
                id:
                system("cls");
                cout<<"ID of "<<name<<":";
                while ( !(cin >> ID))
                {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\tInvalid input; please re-enter: ";
                }
                if(newData[i].setID(ID)){
                    search[i].searchSmall("ID: "+to_string(ID),0);
                    if(search[i].getCount()>=1){
                        system("cls");
                        cout<<"\tThe ID is already registered"<<endl<<"\t";
                        system("pause");
                        goto id;
                    }

                }
                system("cls");
                char date;
                cout<<"Do you have "<<name<<"'s date of birth ? (Y)/(N)";
                cin>>date;
                if(date=='y'||date=='Y'){

                    newData[i].setDate(); 
                }
                newData[i].printToFile();
            }
        }

        else if(choice=="2"){
            searchData search;
            updateData up;
            up.showOptions();
            goto start;
            
        }

        else if(choice=="3"){
            searchData search;
            string scan;
            cout<<"\t\tSearch By ID: ";
            cin>>scan;
            scan="ID: "+scan;
            search.searchSmall(scan,1);
            cout<<"\t\t\t";
            system("pause");
            system("cls");
        }

        else if(choice=="4"){
            list show;
            string size;
            system("cls");
            cout<<"\t\tEnter the size: ";
            cin.ignore();
            getline(cin,size);
            for (int i=0;i<size.size();i++)
            {
                size[i]=toupper(size[i]);
            }

            if(size=="S"||size=="SMALL"){
                show.listSize("S_Size.txt",S);
            }

            else if(size=="M"||size=="MEDIUM"){
                show.listSize("M_Size.txt",M);
            }

            else if (size=="L"||size=="LARGE"){
                show.listSize("L_Size.txt",L);
            }

            else if(size=="XL"||size=="XLarge"){
                show.listSize("XL_Size.txt",XL);
            }
            else if(size=="XXL"||size=="XXLarge"){
                show.listSize("XXL_Size.txt",XXL);
            }
            else{
                system("cls");
                cout<<"\t\tWrong size!! ";
            }
            system("pause");
            system("cls");
        }
        
        else if(choice=="5"){
            deleteData delt;
            string del;
            cout<<"\t\tDelete By ID: ";
            cin>>del;
            del="ID: "+del;
            delt.deleteSmall(del);
            system("pause");
        }
        
        else if(choice=="6"){
            more stat;
            system("cls");
            stat.aboutSizes();
            cout<<"\t";
            system("pause");
            system("cls");
        }
        goto start;
    }
    else{
        system("cls");
        cout<<"\t\tWrong Password try again !!"<<endl<<"\t\t";
        system("pause");
        system("cls");
        goto pass;
    }
}