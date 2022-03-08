#include <iostream>
#include <cstring>
using namespace std;
class shoppinglist
{
    int total_item_no,order_item_no,*item_code,order[25],order_item_amount[25];
    float *item_price,total_price;
    string *item_name;
    void sort(void);
    void sort_order(void);
    void add_order_item(void);
    void delete_order_item(void);
    public:
    float get_total_price(void);
    shoppinglist(void);
    shoppinglist(int);
    void displaylist(void);
    void displayorder(void);
    void get_order(int);
    void confirm_order(void);
    ~shoppinglist();
};
shoppinglist::shoppinglist(void)
{
    cout<<"Enter total number of items : ";
    cin>>total_item_no;
    item_code=new int[total_item_no];
    item_price=new float[total_item_no];
    item_name=new string[total_item_no];
    for(int i=0;i<total_item_no;i++)
    {
		cout<<"\nItem\t: "<<i+1;
        cout<<"\n\nItem Code      : ";
        cin>>item_code[i];
        cout<<"\nItem Name      : ";
        cin>>item_name[i];
        cout<<"\nItem Price     : ";
        cin>>item_price[i];
    }
    sort();
}
shoppinglist::shoppinglist(int n)
{
    total_item_no=n;
    item_code=new int[n];
    item_price=new float[n];
    item_name=new string[n];
    for(int i=0;i<n;i++)
    {
		cout<<"\nItem	       : "<<i+1;
        cout<<"\n\nItem Code      : ";
        cin>>item_code[i];
        cout<<"\nItem Name      : ";
        cin>>item_name[i];
        cout<<"\nItem Price     : ";
        cin>>item_price[i];
    }
    sort();
}
shoppinglist::~shoppinglist()
{
    delete[] item_code;
    delete[] item_name;
    delete[] item_price;
    cout<<"\nDeleted Successfully";
}
void shoppinglist::sort(void)
{
    int n,m,large,pos;
    float temp_price;
    string temp_name;
    n=total_item_no;
    m=total_item_no;
    for(int i=0;i<n;i++)
    {
        large=item_code[0];
        pos=0;
        temp_name=item_name[0];
        temp_price=item_price[0];
        for(int j=0;j<m;j++)
        {
            if(large<item_code[j])
            {
                large=item_code[j];
                pos=j;
                temp_name=item_name[j];
                temp_price=item_price[j];
            }
        }
        item_code[pos]=item_code[m-1];
        item_code[m-1]=large;
        item_name[pos]=item_name[m-1];
        item_name[m-1]=temp_name;
        item_price[pos]=item_price[m-1];
        item_price[m-1]=temp_price;
        m=m-1;
    }
}
void shoppinglist::sort_order(void)
{
    int n,m,large,pos,temp_amount;
    n=order_item_no;
    m=order_item_no;
    for(int i=0;i<n;i++)
    {
        large=order[0];
        pos=0;
        temp_amount=order_item_amount[0];
        for(int j=0;j<m;j++)
        {
            if(large<order[j])
            {
                large=order[j];
                pos=j;
                temp_amount=order_item_amount[j];
            }
        }
        order[pos]=order[m-1];
        order[m-1]=large;
        order_item_amount[pos]=order_item_amount[m-1];
        order_item_amount[m-1]=temp_amount;
        m=m-1;
    }
}
void shoppinglist::displaylist(void)
{
    cout<<"\nCode\t\t\t\tName\t\t\t\tPrice";
    for(int i=0;i<total_item_no;i++)
    {
        cout<<"\n"<<item_code[i]<<"\t\t\t\t"<<item_name[i]<<"\t\t\t\t"<<item_price[i];
    }
}
void shoppinglist::get_order(int n)
{
    order_item_no=n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Code     :";
        cin>>order[i];
        cout<<"\nEnter Amount   :";
        cin>>order_item_amount[i];
    }
    sort_order();
}
float shoppinglist::get_total_price(void)
{
	total_price=0.0;
    for(int i=0;i<order_item_no;i++)
    {
        for(int j=0;j<total_item_no;j++)
        {
            if(order[i]==item_code[j])
            total_price=total_price+(item_price[j]*order_item_amount[i]);
        }
    }
    return total_price;
}
void shoppinglist::displayorder(void)
{
    cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tAmount";
    for(int i=0;i<order_item_no;i++)
    {
        for(int j=0;j<total_item_no;j++)
        {
            if(order[i]==item_code[j])
            {
                cout<<"\n"<<item_code[j]<<"\t\t\t\t"<<item_name[j]<<"\t\t\t\t"<<item_price[j]<<"\t\t\t\t"<<order_item_amount[i];
            }
        }
    }
}
void shoppinglist::confirm_order(void)
{   
    char action;
    displayorder();
    cout<<"\nContinue with this order ?  (y or n)  ";
    cin>>action;
    if(action=='n')
    {
        l1:
        cout<<"\nAdd new item to the order = y"<<"\nDelete an item from the list = n"<<"\nEnter the action  = ";
        cin>>action;
        if(action=='y')
        add_order_item();
        else if(action=='n')
        delete_order_item();
        else
        {
			cout<<"\nInvalid action, Do it again : ";
			goto l1;
		}
        cout<<"\nDo you wish to it again ?";
        cin>>action;
        if(action=='y')
        goto l1;
    }
    displayorder();
}
void shoppinglist::add_order_item(void)
{
    order_item_no=order_item_no+1;
    cout<<"\nEnter Item code        :";
    cin>>order[order_item_no-1];
    cout<<"\nEnter no of said item  :";
    cin>>order_item_amount[order_item_no-1];
    sort_order();
}
void shoppinglist::delete_order_item(void)
{
    int request;
    cout<<"\nEnter the Item code of the Item to be deleted : ";
    cin>>request;
    for(int i=0;i<order_item_no;i++)
    {
        if(request==order[i])
        {
            order[i]=order[order_item_no-1];
            order_item_amount[i]=order_item_amount[order_item_no-1];
            break;
        }
    }
    order_item_no=order_item_no-1;
}
int main()
{
    int number;
    cout<<"Menu Creation";
    cout<<"\nEnter the total amount of items : ";
    cin>>number;
    shoppinglist list(number);
    list.displaylist();
    cout<<"\nEnter the number of items in the purchase order        :";
    cin>>number;
    list.get_order(number);
    list.confirm_order();
    cout<<"\nTotal cost is :"<<list.get_total_price();
    return 0;
}

