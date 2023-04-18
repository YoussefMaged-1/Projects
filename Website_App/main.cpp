#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <direct.h> 
using namespace std;
class header{
private:
    string htmlCode,cssCode;
    int headerNumber;
    string intToString(unsigned long num){
        switch(num){
            case 1:
                return "1";
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
        }
        return "5";
    }
public:
    void chooseHeader(vector<string> pageName){
        cout<<"Header1:\n"
                    "--------------------------\n"
                    "| picture |\n"
                    "--------------------------\n"
                    "| Home | contact | About |\n"
                    "--------------------------\n"
                    "Header2:\n"
                    "--------------------------\n"
                    "| Home | contact | About |\n"
                    "--------------------------\n";
        cin>>headerNumber;
        while(headerNumber!=1&&headerNumber!=2){
            cout<<"please enter acorrect number: ";
            cin>>headerNumber;
        }
        generateCode(pageName);
    }
    void generateCode(vector<string> pageName){
        cssCode="table.headertable{width:80%;margin-left:auto;margin-right:auto;}";
        cssCode+="td.headertd{border:1px solid black;color:black;text-align:center;font-size:20px;}a.headera{text-decoration:none;color:black;}";
        htmlCode="<table class=\"headertable\">";
        if(headerNumber==1){
            cssCode+="img.headerimg{width:auto;height:auto;}";
            string pictureFileName;
            cout<<"pictureFileName: ";
            cin>>pictureFileName;
            htmlCode+="<tr><td class=\"headertd\"colspan=\""+intToString(pageName.size())+"\"><img class=\"headerimg\"src=\""+pictureFileName;
            htmlCode+="\"></td></tr>";
        }
        htmlCode+="<tr>";
        htmlCode+="<td class=\"headertd\">""<a class=\"headera\"href=\"index.html\"/>"+pageName[0]+"</a></td>";
        for(int i=1;i<pageName.size();++i)
            htmlCode+="<td class=\"headertd\">""<a class=\"headera\"href=\""+pageName[i]+".html\"/>"+pageName[i]+"</a></td>";
            htmlCode+="</tr></table>";
        }
    string getHtml(){
        return htmlCode;
    }
    string getCss(){
        return cssCode;
    }
};
class footer{
private:
    string htmlCode,cssCode;
public:
    void chooseFooter(string websiteName){
        int footerNumber;
        cout<<"Footer 1:\n"
                    "-----------------------------------\n"
                    " (website Name) all rights reserve \n"
                    "-----------------------------------\n"
                    "Footer 2:\n"
                    "-----------------------------------\n"
                    "| (Footer background color) |\n"
                    " (website Name) all rights reserved\n"
                    "-----------------------------------\n"
                    "Enter footer number: ";
        cin>>footerNumber;
        while(footerNumber!=1&&footerNumber!=2){
            cout<<"Please, Enter the correct Number: ";
            cin>>footerNumber;
        }
        generateCode(footerNumber,websiteName);
    }
    void generateCode(int footerNumber,string websiteName){
        string footerColor,textColor;
        htmlCode="<br><br><footer><div class=\"footerdiv\">";
        htmlCode+=websiteName;
        htmlCode+=" all rights reserved</div></footer>";
        cssCode="footer{margin-left:auto;margin-right:auto;}div.footerdiv{text-align:center;left:0;bottom:0;width:100%; ";
        if(footerNumber==2){
            cout<<"Footer color: ";
            cin>>footerColor;
            cssCode+="background-color: "+footerColor+";";
            cout<<"Enter text color: ";
            cin>>textColor;
            cssCode+="color: "+textColor+";";
            cssCode+="position:fixed;";
        }
        cssCode+="}";
    }
    string getHtml(){
        return htmlCode;
    }
    string getCss(){
        return cssCode;
    }
};
class page{
private:
    string htmlCode,cssCode;
public:
    void choosePage(string headerHtml,string footerHtml,string pageName,string backgroundColor){
        int pageNumber;
        cout<<"Page 1:\n"
                    "---------------------------------------\n"
                    "| Youtube video | Youtube video |\n"
                    "---------------------------------------\n"
                    "Page 1:\n"
                    "---------------------------------------\n"
                    "| Youtube video | Text |\n"
                    "---------------------------------------\n"
                    "choose Number: ";
        cin>>pageNumber;
        generateCode(headerHtml,footerHtml,pageName,pageNumber,backgroundColor);
    }
    void generateCode(string headerHtml,string footerHtml,string pageName,int pageNumber,string backgroundColor){
        htmlCode="<html><head><title>";
        htmlCode+=pageName+"</title>";
        htmlCode+="<link rel=\"stylesheet\"href=\"css\\header.css\">";
        htmlCode+="<link rel=\"stylesheet\"href=\"css\\footer.css\">";
        string videoLink;
        cssCode="body{background-color: "+backgroundColor+";}table.pagetable{margin-left:auto;margin-right:auto;width:80%;}td.pagetd{color:white;text-align: center;}iframe{width:100%;}";
        htmlCode+="<style>"+cssCode+"</style></head>";
        htmlCode+="<body><br>"+headerHtml+"<br><br>";
        htmlCode+="<table class=\"pagetable\">";
        int rows;
        cout<<"Enter rows: ";
        cin>>rows;
        for(int r=0;r<rows;++r){
            htmlCode+="<tr><td class=\"pagetd\">";
            cout<<"Enter video Link: ";
            cin>>videoLink;
            htmlCode+="<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"+videoLink+"\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>";
            htmlCode+="</td><td class=\"pagetd\">";
            if(pageNumber==1){
                cout<<"Enter video Link: ";
                cin>>videoLink;
                htmlCode+="<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"+videoLink+"\" ----title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>";
            }
            else if(pageNumber==2){
                string text;
                cout<<"Enter text: ";
                getchar();
                getline(cin,text);
                htmlCode+=text;
            }
        htmlCode+="</td></tr>";
            }
                htmlCode+="</table>"+footerHtml+"</body></html>";
    }
    string getHtml(){
        return htmlCode;
    }
};
class website{
private:
    vector<string> pageName;
    string websiteName,backgroundColor;
public:
    void createWebsite(){
        int numberOfPages;
        string temp;
        cout<<"Website Name: ";
        cin>>websiteName;
        cout<<"Number of pages: ";
        cin>>numberOfPages;
        for(int i=0;i<numberOfPages;++i){
            cout<<"Page: "<<i+1<<" Name: ";
            cin>>temp;
            pageName.push_back(temp);
        }
        cout<<"background Color: ";
        cin>>backgroundColor;
        header h;
        h.chooseHeader(pageName);
        footer f;
        f.chooseFooter(websiteName);
        _mkdir(websiteName.c_str());
        string cssFolder=websiteName;
        cssFolder+="//css";
        _mkdir(cssFolder.c_str());
        string cssFile=cssFolder;
        cssFile+="//header.css";
        ofstream headerCssFile(cssFile);
        headerCssFile<<h.getCss();
        headerCssFile.close();
        cssFile=cssFolder;
        cssFile+="//footer.css";
        ofstream footerCssFile(cssFile);
        footerCssFile<<f.getCss();
        footerCssFile.close();
        for(int i=0;i<numberOfPages;++i){
            page p;
            cout<<pageName[i]<<"details: ";
            p.choosePage(h.getHtml(),f.getHtml(),pageName[i],backgroundColor);
            string file=websiteName;
            if(i==0)
                file+="//index.html";
            else
                file+="//"+pageName[i]+".html";
            ofstream pageHtml(file);
            pageHtml<<p.getHtml();
            pageHtml.close();
        }
    }
};
int main(){
    website w;
    w.createWebsite();
}
