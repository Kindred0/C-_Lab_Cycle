#include <iostream>
#include <cstring>
using namespace std;
class person
{
    protected:
    string name;
};
class employee:public person
{
    protected:
    float salary;
    int e_code;
};
class Room
{
    protected:
    int standard;
    char division;
};
class teacher:public employee, public Room
{
    int MA,DA;
    public:
    void get_data(void);
    void put_data(void)
    {
        cout<<"\nName\t\t\t: "<<name;
        cout<<"\nCode\t\t\t: "<<e_code;
        cout<<"\nTeaching Class\t\t: "<<standard<<division;
        cout<<"\nSalary\t\t\t: "<<salary;
    }
};
void teacher::get_data(void)
{
    cout<<"\nName\t\t\t: ";
    cin>>name;
    cout<<"Code\t\t\t: ";
    cin>>e_code;
    cout<<"Teaching Standard\t: ";
    cin>>standard;
    cout<<"Teaching division\t: ";
    cin>>division;
    cout<<"MA\t\t\t: ";
    cin>>MA;
    if(MA>7000)
    MA=7000;
    if(MA<500)
    MA=500;
    cout<<"DA\t\t\t: ";
    cin>>DA;
    if(DA>25)
    DA=25;
    if(DA<1)
    DA=1;
    salary=22000+(22000*DA/100)+MA;
}
int main()
{
    teacher T;
    T.get_data();
    T.put_data();
    cout<<endl;
    return 0;
}