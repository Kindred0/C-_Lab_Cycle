#include <iostream>
#include <cstring>
using namespace std;
class String
{
    char *str;
    int length;
    public:
    String(void){};
    String(char*);
    String(String &);
    ~String(); 
    friend int Str_compare(String,String);
    friend int Str_length(String);
    friend void Str_concate(String,String);
    void display(void)
    {
        cout<<str;
    }
};
String::String(char* str1)
{
    length=0;
    for(int i=0;str1[i]!='\0';i++)
    length=length+1;
    str=new char[length+1];
    for(int i=0;i<=length;i++)
    str[i]=str1[i];
}
String::String(String &S)
{
    length=S.length;
    str=new char[length+1];
    strcpy(str,S.str);
}
String::~String()
{
    delete str;
}
int Str_length(String S)
{
    return S.length;
}
int Str_compare(String S1,String S2)
{
    if(S1.length!=S2.length)
    return 0;
    for(int i=0;i<S1.length;i++)
    {
        if(S1.str[i]!=S2.str[i])
        {
            return 0;
        }
    }
    return 1;
}
void Str_concate(String S1,String S2)
{
    int i;
    String S3;
    S3.length=S1.length+S2.length;
    S3.str=new char[S3.length+1];
    for(i=0;i<S1.length;i++)
    {
        S3.str[i]=S1.str[i];
    }
    int j=0;
    for(i=i;i<=S3.length;i++)
    {
        S3.str[i]=S2.str[j];
        j=j+1;
    }
    S3.display();
    cout<<endl;
}
int main()
{
    char name[30];
    cout<<"\nEnter your first name\t: ";
    cin>>name;
    String Firstname(name);
    Firstname.display();
    cout<<"\nLength is\t\t: "<<Str_length(Firstname);
    cout<<"\nEnter your second name\t: ";
    cin>>name;
    String Secondname(name);
    Secondname.display();
    cout<<"\nLength is\t\t: "<<Str_length(Secondname);
    if(Str_compare(Firstname,Secondname)==1)
        cout<<"\n\nThe names are same"<<endl;
    else
        cout<<"\n\nThe names are not same"<<endl;
    cout<<"\nFull name is \t: ";
    Str_concate(Firstname,Secondname);
    return 0;
}
