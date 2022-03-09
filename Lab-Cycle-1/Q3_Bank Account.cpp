#include <iostream>
#include <cstring>
using namespace std;
class Account
{
    int acc_no;
    float balance;
    string cust_name, acc_type;
    public:
    Account(){}
    Account(int,string,float,string);
    Account(const Account &);
    void new_account(int,string,float,string);
    void withdraw(int);
    void balance_enquiry(void);
    void deposit(int);
    void acc_statement(void);
    int check(void);
};
Account::Account(const Account &A)
{
    acc_no=A.acc_no;
    cust_name=A.cust_name;
    balance=A.balance;
    acc_type=A.acc_type;
}
Account::Account(int number,string name,float bal,string type)
{
    acc_no=number;
    cust_name=name;
    balance=bal;
    acc_type=type;
}
void Account::new_account(int number,string name,float bal,string type)
{
    acc_no=number;
    cust_name=name;
    balance=bal;
    acc_type=type;
}
void Account::balance_enquiry(void)
{
    cout<<"\n\nbalance left : "<<balance;
}
void Account::withdraw(int debit)
{
    if (debit<0)
    debit=-1*debit;
	if((balance-debit)>500)
    {
        balance=balance-debit;
        cout<<"The amount of "<<debit<<" is successfully withdrawn";
    }
    else
    cout<<"\nInsufficient balance";
}
void Account::deposit(int credit)
{
    if (credit<0)
    credit=-1*credit;
    balance=balance+credit;
    cout<<"The amount of "<<credit<<" is successfully deposited";
}
void Account::acc_statement(void)
{
    cout<<"\nAccount Number 	: "<<acc_no<<"\nCustomer Name 	: "<<cust_name<<"\nAccount type 	: "<<acc_type<<"\nBalance 	: "<<balance;
}
int Account::check(void)
{
    return acc_no;
}
int main()
{
    int action,n=0,Acc_No,amount,i;
    string name,secondname,type;
    char tryagain;
    Account *list,*templist;
    list=new Account;
    l1:
    cout<<"\n1\t: Create a new account\n2\t: Account Inquiry\n3\t: Deposit amount\n4\t: Withdraw amount";
    cout<<"\nEnter the action\t: ";
    cin>>action;
    if(action==1)
    {
        if(n==0)
        {
            list=new Account[1];
            cout<<"\nAccount Number\t: ";
            cin>>Acc_No;
            cout<<"First Name\t: ";
            cin>>name;
            cout<<"Second Name\t: ";
            cin>>secondname;
            name=name+" "+secondname;
            cout<<"Intital Balance\t: ";
            cin>>amount;
            cout<<"Type of Account\t: ";
            cin>>type;
            list[0].new_account(Acc_No,name,amount,type);
            n=n+1;
        }
        else
        {
            templist=new Account[n];
            for(i=0;i<n;i++)
            {
                templist[i]=Account(list[i]);
            }
            delete[] list;
            list=new Account[n+1];
            for(i=0;i<n;i++)
            {
                list[i]=Account(templist[i]);
            }
            delete[] templist;
            cout<<"\nAccount Number\t: ";
            cin>>Acc_No;
            cout<<"First Name\t: ";
            cin>>name;
            cout<<"Second Name\t: ";
            cin>>secondname;
            name=name+" "+secondname;
            cout<<"Intital Balance\t: ";
            cin>>amount;
            cout<<"Type of Account\t: ";
            cin>>type;
            list[n].new_account(Acc_No,name,amount,type);
            n=n+1;
        }
    }
    else if(action==2)
    {
        if(n==0)
        {
            cout<<"\nNo accounts created yet, Create an account first";
            goto l1;
        }
        l2:
        cout<<"\nEnter the account number\t: ";
        cin>>Acc_No;
        for(i=0;i<n;i++)
        {
            if(Acc_No==list[i].check())
            {
                list[i].acc_statement();
                break;
            }
        }
        if(i==n)
        {
            cout<<"\nNo such account is created, Try again";
            goto l2;
        }
    }
    else if(action==3)
    {
        if(n==0)
        {
            cout<<"\nNo accounts created yet, Create an account first";
            goto l1;
        }
        l3:
        cout<<"\nEnter the account number\t: ";
        cin>>Acc_No;
        for(i=0;i<n;i++)
        {
            if(Acc_No==list[i].check())
            {
                list[i].acc_statement();
                cout<<"\nEnter the amount to deposit\t: ";
                cin>>amount;
                list[i].deposit(amount);
                list[i].balance_enquiry();
                break;
            }
        }
        if(i==n)
        {
            cout<<"\nNo such account is created, Try again";
            goto l3;
        }
    }
    else if(action==4)
    {
        if(n==0)
        {
            cout<<"\nNo accounts created yet, Create an account first";
            goto l1;
        }
        l4:
        cout<<"\nEnter the account number\t: ";
        cin>>Acc_No;
        for(i=0;i<n;i++)
        {
            if(Acc_No==list[i].check())
            {
                list[i].acc_statement();
                cout<<"\nEnter the amount to withdraw\t: ";
                cin>>amount;
                list[i].withdraw(amount);
                list[i].balance_enquiry();
                break;
            }
        }
        if(i==n)
        {
            cout<<"\nNo such account is created, Try again";
            goto l4;
        }
    }
    else 
    {
        cout<<"\nInvalid action, Try again";
        goto l1;
    }
    cout<<"\nDo you wish to do anther process?\n(Type y for yes and n for no)";
    cin>>tryagain;
    if(tryagain=='y')
    goto l1;
    cout<<"Program is closed\nA total of "<<n<<" Accounts have been created";
    delete[] list;
    return 0;
}
