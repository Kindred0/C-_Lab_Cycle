#include <iostream>
#include <cstring>
using namespace std;
class item
{
    int code,quantity;
    float price,total;
    string name;
    public:
    void getdata(void)
    {
        cout<<"\nCode\t\t: ";
        cin>>code;
        cout<<"Name\t\t: ";
        cin>>name;
        cout<<"Price\t\t: ";
        cin>>price;
        cout<<"Quantity\t: ";
        cin>>quantity;
        total=price*quantity;
    }
    void printdata(void)
    {
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
    int action,code,n=0,stop=0;
    float total=0;
    while(stop==0)
    {
        cout<<"\n\n1\t: Add an item to the cart\n2\t: Delete an item from the cart\n3\t: Show order\n4\t: Create the bill";
        cout<<"\nEnter the action\t: ";
        cin>>action;
        if(action==1)
        {
            if(n==0)
            {
                order=new item[1];
                order[0].getdata();
                n=n+1;
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
                order[n].getdata();
                n=n+1;
                sort(order,n);
            }
        }
        else if(action==2)
        {
            if(n==0)
            {
                cout<<"\nNo items added to the cart yet, Add an item to your cart first";
            }
            else
            {
                cout<<"\nEnter the code numberof the item to be deleted\t: ";
                cin>>code;
                for(int i=0;i<n;i++)
                {
                    if(code==order[i].putcode())
                    {
                        order[i].printdata();
                        cout<<"\nDeleted successfully";
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
                        stop=1;
                        sort(order,n);
                        break;
                    }    
                }
                if(stop==0)
                {
                    cout<<"\nNo such item have added to the cart,Try again";
                }
                stop=0;
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
                total=total+order[i].puttotal();
            }
            cout<<"\n\nTotal\t\t: "<<total;
            cout<<"\n\nThank you for the purchase\n";
            delete[] order;
            cout<<"order deleted successfully";
            return 0;
        }
        else
        {
            cout<<"\nInvalid input,Try again";
        }
    }
}