#include <iostream>
#include <cstring>
using namespace std;
class item
{
    int code,quantity;
    float price,total;
    string name;
    public:
    void getdata(int a,string b,float c,int d)
    {
        code=a;
        price=c;
        name=b;
        quantity=d;
        total=price*quantity;
        }
    void printdata(void){
        cout<<"\n"<<code<<"\t\t\t\t"<<name<<"\t\t\t\t"<<price<<"\t\t\t\t"<<quantity;
    }
    int putcode(void)
    {
        return code;
    }
    float puttotal(void)
    {
        return total;
    }
};
void sort(item* list,int n)
{
    int large;
    int pos;
    int m=n;
    item tempitem;
    for(int j=0;j<n;j++)
    {
        large=list[0].putcode();
        pos=0;
        for(int i=0;i<m;i++)
        {
            if(large<list[i].putcode())
            {
                large=list[i].putcode();
                pos=i;
            }
        }
        tempitem=list[pos];
        list[pos]=list[m-1];
        list[m-1]=tempitem;
        m=m-1;
    }
}
int main()
{
    item *order,*temporder;
    string name;
    int action,n=0,code,quantity;
    float price,total=0;
    l1:
    cout<<"\n\n1\t: Add an item to the cart\n2\t: Delete an item from the cart\n3\t: Show order\n4\t: Create the bill";
    cout<<"\nEnter the action\t: ";
    cin>>action;
    if(action==1)
    {
        if(n==0)
        {
            order=new item[1];
            cout<<"\nCode\t\t: ";
            cin>>code;
            cout<<"\nName\t\t: ";
            cin>>name;
            cout<<"\nPrice\t\t: ";
            cin>>price;
            cout<<"\nQuantity\t:";
            cin>>quantity;
            order[0].getdata(code,name,price,quantity);
            n=n+1;
            total=total+order[0].puttotal();
        }
        else 
        {
            temporder=new item[n];
            for(int i=0;i<n;i++)
            {
                temporder[i]=order[i];
            }
            delete[] order;
            order=new item[n+1];
            for(int i=0;i<n;i++)
            {
                order[i]=temporder[i];
            }
            delete[] temporder;
            cout<<"\nCode\t:";
            cin>>code;
            cout<<"\nName\t: ";
            cin>>name;
            cout<<"\nPrice\t: ";
            cin>>price;
            cout<<"\nQuantity: ";
            cin>>quantity;
            order[n].getdata(code,name,price,quantity);
            n=n+1;
            total=total+order[n].puttotal();
            sort(order,n);
        }
    }
    else if(action==2)
    {
        if(n==0)
        {
            cout<<"No items added to the cart yet, Add an item to your cart first";
            goto l1;
        }
        cout<<"\nEnter the code numberof the item to be deleted";
        cin>>code;
        for(int i=0;i<n;i++)
        {
            if(code==order[i].putcode())
            {
                order[i].printdata();
                cout<<"\nDeleted successfully";
                total=total-order[i].puttotal();
                order[i]=order[n-1];
                n=n-1;
                temporder=new item[n];
                for(int i=0;i<n;i++)
                {
                    temporder[i]=order[i];
                }
                delete[] order;
                order=new item[n];
                for(int i=0;i<n;i++)
                {
                    order[i]=temporder[i];
                }
                delete[] temporder;
                sort(order,n);               
            }
        }
    }
    else if(action==3)
    {
        cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
        for(int i=0;i<n;i++)
        {
            order[i].printdata();
        }
    }
    else if(action==4)
    {
        cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
        for(int i=0;i<n;i++)
        {
            order[i].printdata();
        }
        cout<<"\nTotal\t\t\t\t\t\t\t\t: "<<total;
        cout<<"\nThank you for the purchase\n";
        return 0;
    }
    else
    {
        cout<<"\nInvalid input,Try again";
        goto l1;
    }
    goto l1;
}