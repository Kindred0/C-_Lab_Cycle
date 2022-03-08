#include <iostream>
using namespace std;
bool str_compare(string string1,string string2)
{
    if(string1==string2)
    return true;
    else 
    return false;
}
string str_concate(string string1, string string2)
{
    return string1+" "+string2;
} 
int str_length(string str)
{
    int i=0;
    while(str[i]!='\0')
    i++;
    return i;
}
int main()
{
    string string1, string2;
    cout<<"Enter two strings ";
    cin>>string1>>string2;
    cout<<str_compare(string1,string2)<<"\n"<<str_concate(string1,string2)<<"\n"<<str_length(string1)<<"\n"<<str_length(string2);
    return 0;
}
