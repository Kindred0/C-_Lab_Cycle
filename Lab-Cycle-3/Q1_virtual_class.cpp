#include <iostream>
#include <cstring> 
using namespace std;
class employee 
{
    protected:
    string name;
    int e_code;
    public:
    float virtual find_salary()=0;
    void virtual get_data()=0;
    void virtual show_data()=0;
};
class manager:public employee
{
    float static base_pay;
    float DA,IT;
    public:
    void get_data(void);
    float find_salary(void)
    {
        return (base_pay+(base_pay*DA/100)-(base_pay*IT/100));
    }
    void virtual show_data(void);
};
float manager::base_pay=25000.00;
void manager::get_data(void)
{
    cout<<"\nName\t\t: ";
    cin>>name;
    cout<<"Code\t\t: ";
    cin>>e_code;
    cout<<"DA\t\t: ";
    cin>>DA;
    if(DA>25)
    DA=25;
    if(DA<1)
    DA=1;
    cout<<"IT\t\t: ";
    cin>>IT;
    if(IT<0)
    IT=0;
    if(IT>20)
    IT=20;
}
void manager::show_data(void)
{
    cout<<"\nName\t\t: "<<name;
    cout<<"\nEmployer Code\t: "<<e_code;
    cout<<"\nPosition\t: Manager";
    cout<<"\nSalary\t\t: "<<find_salary();
}
class clerk:public employee
{
    float static base_pay;
    float MA;
    public:
    void get_data(void);
    float find_salary(void)
    {
        return base_pay+MA;
    }
    void show_data(void);
};
float clerk::base_pay=22000.00;
void clerk::get_data(void)
{
    cout<<"\nName\t\t: ";
    cin>>name;
    cout<<"Code\t\t: ";
    cin>>e_code;
    cout<<"MA\t\t: ";
    cin>>MA;
    if(MA>7000)
    MA=7000;
    if(MA<500)
    MA=500;
}
void clerk::show_data(void)
{
    cout<<"\nName\t\t: "<<name;
    cout<<"\nEmployer Code\t: "<<e_code;
    cout<<"\nPosition\t: Clerk";
    cout<<"\nSalary\t\t: "<<find_salary();
}
class accountant:public employee
{
    float static base_pay;
    float DA,MA;
    public:
    void get_data(void);
    float find_salary(void)
    {
        return (base_pay+MA+((base_pay*DA)/100));
    }
    void show_data(void);
};
float accountant::base_pay=18000.00;
void accountant::get_data(void)
{
    cout<<"\nName\t\t: ";
    cin>>name;
    cout<<"Code\t\t: ";
    cin>>e_code;
    cout<<"MA\t\t: ";
    cin>>MA;
    if(MA>7000)
    MA=7000;
    if(MA<500)
    MA=500;
    cout<<"DA\t\t: ";
    cin>>DA;
    if(DA>25)
    DA=25;
    if(DA<1)
    DA=1;
}
void accountant::show_data(void)
{
    cout<<"\nName\t\t: "<<name;
    cout<<"\nEmployer Code\t: "<<e_code;
    cout<<"\nPosition\t: accountant";
    cout<<"\nSalary\t\t: "<<find_salary();
}
int main()
{
    employee *e;
    int action=0;
    while(action==0)
    {
        cout<<"\n1\t: Manager\n2\t: Clerk\n3\t: accountant";
        cout<<"\nEnter your position\t: ";
        cin>>action;
        if(action==1)
        e = new manager; 
        else if(action==2)
        e = new clerk;
        else if(action==3)
        e = new accountant;
        else
        {
            cout<<"\nInvalid Action, Try Again";
            action=0;
        }
    }
    e->get_data();
    e->show_data();
    cout<<endl;
    return 0;
}