#include <iostream>
#include <cstring>
using namespace std;
class Account
{
    int acc_no;
    float balance;
    string cust_name, acc_type;
    public:
    void new_account(void);
    void withdraw(int);
    void balance_enquiry(void);
    void deposit(int);
    void acc_statement(void);
    int check(void);
};
void Account::new_account(void)
{
    string secondname;
    cout<<"\nAccount Number\t: ";
    cin>>acc_no;
    cout<<"First Name\t: ";
    cin>>cust_name;
    cout<<"Second Name\t: ";
    cin>>secondname;
    cust_name=cust_name+" "+secondname;
    cout<<"Intital Balance\t: ";
    cin>>balance;
    cout<<"Type of Account\t: ";
    cin>>acc_type;
}
void Account::balance_enquiry(void)
{
    cout<<"\nNew balance\t: "<<balance;
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
    int action,Acc_no,n=0,amount,i,stop=0;
    char tryagain;
    Account *list,*templist;
    list=new Account[1];
    while(stop==0)
    {
        cout<<"\n\n1\t: Create a new account\n2\t: Account Inquiry\n3\t: Deposit amount\n4\t: Withdraw amount\n5\t: Exit";
        cout<<"\nEnter the action\t: ";
        cin>>action;
        if(action==1)
        {
            if(n==0)
            {
                list[0].new_account();
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
                list[n].new_account();
                n=n+1;
            }
        }
        else if(action==2)
        {
            if(n==0)
            {
                cout<<"\nNo accounts created yet, Create an account first";
            }
            else
            {
                cout<<"\nEnter the account number\t: ";
                cin>>Acc_no;
                for(i=0;i<n;i++)
                {
                    if(Acc_no==list[i].check())
                    {
                        list[i].acc_statement();
                        break;
                    }
                }
                if(i==n)
                {
                    cout<<"\nNo such account is created, Try again";
                }
            }
        }
        else if(action==3)
        {
            if(n==0)
            {
                cout<<"\nNo accounts created yet, Create an account first";
            }
            else
            {
                cout<<"\nEnter the account number\t: ";
                cin>>Acc_no;
                for(i=0;i<n;i++)
                {
                    if(Acc_no==list[i].check())
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
                }
            }
        }
        else if(action==4)
        {
            if(n==0)
            {
                cout<<"\nNo accounts created yet, Create an account first";
            }
            else
            {
                cout<<"\nEnter the account number\t: ";
                cin>>Acc_no;
                for(i=0;i<n;i++)
                {
                    if(Acc_no==list[i].check())
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
                }
            }
        }
        else if(action==5)
        stop=1;
    }
    cout<<"Program is closed\nA total of "<<n<<" Accounts have been created\n";
    delete[] list;
    return 0;
}
