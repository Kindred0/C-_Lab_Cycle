#include <iostream>
#include <cstring>
using namespace std;
class Account
{
    int acc_no;
    float balance;
    char *cust_name, *acc_type;
    public:
    Account(){}
    Account(int,char*,float,char*);
    ~Account();
    void new_account(int,char*,float,char*);
    void withdraw(int);
    void balance_enquiry(void);
    void deposit(int);
    void acc_statement(void);
    int check(void);
};
Account::Account(int number,char* name,float bal,char* type)
{
    acc_no=number;
    cust_name=new char[strlen(name)+1];
    strcpy(cust_name,name);
    balance=bal;
    acc_type=new char[strlen(type)+1];
    strcpy(acc_type,type);
}
Account::~Account()
{
    delete[] cust_name;
    delete[] acc_type;
}
void Account::new_account(int number,char* name,float bal,char* type)
{
    acc_no=number;
    cust_name=new char[strlen(name)+1];
    strcpy(cust_name,name);
    balance=bal;
    acc_type=new char[strlen(type)+1];
    strcpy(acc_type,type);
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
    balance=balance-debit;
    else
    cout<<"\nInsufficient balance";
}
void Account::deposit(int credit)
{
    if (credit<0)
    credit=-1*credit;
    balance=balance+credit;
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
    Account *list;
    int number_of_accounts, Acc_Number, action=0, amount;
    char firstname[30],type[30],secondname[30];
    cout<<"\nEnter the number of accounts 				: ";
    cin>>number_of_accounts;
    list=new Account[number_of_accounts];
    for(int i=0; i<number_of_accounts; i++)
    {
		cout<<"Account "<<i;
        cout<<"\nEnter Account Number 					: ";
        cin>>Acc_Number;
        cout<<"\nEnter First Name 					: ";
        cin>>firstname;
        cout<<"\nEnter second Name 					: ";
        cin>>secondname;
        strcat(firstname," ");
        strcat(firstname,secondname);
        cout<<"\nEnter the initial amount of balance 			: ";
        cin>>amount;
        cout<<"\nEnter the type of account 				: ";
        cin>>type;
        list[i].new_account(Acc_Number,firstname,amount,type);
    }
    l2:
    cout<<"\nEnter the Account Number to do the Transaction 		: ";
    cin>>Acc_Number;
    for(int i=0; i<number_of_accounts; i++)
    {
        if(Acc_Number==list[i].check())
        {
            list[i].acc_statement();
            l1:
            cout<<"\n\nWhat is the action (type 1 for withdraw and 2 for deposit) to be done 	: ";
            cin>>action;
            if(action==1)
            {
                cout<<"\nEnter the amount to withdraw 	: ";
                cin>>amount;
                list[i].withdraw(amount);
                list[i].balance_enquiry();
            }
            else if(action==2)
            {
                cout<<"\nEnter the amount to deposit 	: ";
                cin>>amount;
                list[i].deposit(amount);
                list[i].balance_enquiry();
            }						
            else 
            {
                cout<<"\nInvalid action";
                goto l1;
            }
        }
    }
    if (action==0)
	{
		cout<<"\nInvalid Account Number, Try again";
		goto l2;
	}
	delete[] list;
    return 0;
}
