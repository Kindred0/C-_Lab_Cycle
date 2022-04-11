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
    void getquantity(int n)
    {
        quantity = n;
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
        total = price * quantity;
        return total;
    }
    int putquantity(void)
    {
        return quantity;
    }
    void change_quantity(int);
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
void item::change_quantity(int a)
{   
    quantity = quantity - a;
}
int main()
{
    item *stock,*tempstock, *order, *temporder;
    int action1,action2,code,n=0,m=0,stop=0,quantity;
    float total=0;
    while(stop==0)
    {
        cout<<"\n\nSTOCK";
        cout<<"\n_________________________________________________________________________________________________________________________________________";
        cout<<"\n\n1\t: Add an item to the stock\n2\t: Remove an item from the stock\n3\t: Show stock\n4\t: Create a new order\n5\t: Exit";
        cout<<"\n_________________________________________________________________________________________________________________________________________";
        cout<<"\n\nEnter the action\t: ";
        cin>>action1;
        if(action1==1)
        {
            if(n==0)
            {
                stock=new item[1];
                stock[0].getdata();
                n=n+1;
            }
            else 
            {
                tempstock=new item[n];
                for(int i=0;i<n;i++)
                {
                    tempstock[i]=stock[i];
                }
                delete[] stock;
                stock=new item[n+1];
                for(int i=0;i<n;i++)
                {
                    stock[i]=tempstock[i];
                }
                delete[] tempstock;
                stock[n].getdata();
                n=n+1;
                sort(stock,n);
            }
        }
        else if(action1==2)
        {
            if(n==0)
            {
                cout<<"\nNo items added to the stock yet, Add an item to your stock first";
            }
            else
            {
                cout<<"\nEnter the code number of the item to be removed\t: ";
                cin>>code;
                for(int i=0;i<n;i++)
                {
                    if(code == stock[i].putcode())
                    {
                        stock[i].printdata();
                        cout<<"\n\nEnter the amount of items to be removed\t : ";
                        cin>>quantity;
                        stock[i].change_quantity(quantity);
                        cout<<"\nDeleted successfully";
                        if(stock[i].putquantity() <= 0)
                        {
                            stock[i]=stock[n-1];
                            n=n-1;
                            tempstock=new item[n];
                            for(int i=0;i<n;i++)
                            {
                                tempstock[i]=stock[i];
                            }
                            delete[] stock;
                            stock=new item[n];
                            for(int i=0;i<n;i++)
                            {
                                stock[i]=tempstock[i];
                            }
                            delete[] tempstock;
                            
                            sort(stock,n);
                        }
                        stop=1;
                        break;
                    }    
                }
                if(stop==0)
                {
                    cout<<"\nNo such item have added to the stock,Try again";
                }
                stop=0;
            }
        }
        else if(action1==3)
        {
            cout<<"\n________________________________________________________________________________________________________";
            cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
            for(int i=0;i<n;i++)
            {
                stock[i].printdata();
            }
            cout<<"\n________________________________________________________________________________________________________";
        }
        else if(action1==4 && n != 0)
        {
            while(stop == 0)
            {
                cout<<"\n\nORDER";
                cout<<"\n\n_________________________________________________________________________________________________________________________________________";
                cout<<"\n1\t: Add an item to the order\n2\t: Remove an item from the order\n3\t: Show the order\n4\t: Process the order\n5\t: Exit";
                cout<<"\n_________________________________________________________________________________________________________________________________________";
                cout<<"\nEnter an action\t: ";
                cin>>action2;
                if(action2 == 1)
                {
                    if(m==0)
                    {
                        order = new item[1];
                        while(stop == 0)
                        {
                            cout<<"\nEnter the code number of the item to be added\t: ";
                            cin>>code;
                            for(int i=0;i<n;i++)
                            {
                                
                                if(code == stock[i].putcode())
                                {
                                    cout<<"Pirnted";
                                    order[0] = stock[i];
                                    stop = 1;
                                    cout<<"\nEnter the quantity\t: ";
                                    cin>>quantity;
                                    if(quantity > stock[i].putquantity())
                                    {
                                        quantity = stock[i].putquantity();
                                        cout<<"\nNot enough items in the stock";
                                    }
                                    order[0].getquantity(quantity);
                        
                                    break;
                                }
                            }
                            if(stop == 0)
                            {
                                cout<<"\nNo such item in the stock";
                            }
                        }
                        stop = 0;
                        m=m+1;
                    }
                    else 
                    {
                        temporder=new item[m];
                        for(int i=0;i<m;i++)
                        {
                            temporder[i]=order[i];
                        }
                        delete[] order;
                        order=new item[m+1];
                        for(int i=0;i<m;i++)
                        {
                            order[i]=temporder[i];
                        }
                        delete[] temporder;
                        while(stop == 0)
                        {
                            cout<<"\nEnter the code number of the item to be added\t: ";
                            cin>>code;
                            for(int i=0;i<n;i++)
                            {
                                if(code == stock[i].putcode())
                                {
                                    order[m] = stock[i];
                                    cout<<"\nEnter the quantity\t: ";
                                    cin>>quantity;
                                    if(quantity > stock[i].putquantity())
                                    {
                                        quantity = stock[i].putquantity();
                                        cout<<"\nNot enough item in the stock";                                        
                                    }
                                    order[m].getquantity(quantity);
                                    stop = 1;
                                }
                            }
                            if(stop == 0)
                            {
                                cout<<"\nNo such item in the stock";
                            }
                        }
                        stop = 0;
                        
                        m=m+1;
                        sort(order,m);
                    }    
                }
                else if(action2 == 2)
                {
                    if(m==0)
                    {
                        cout<<"\nNo items added to the order yet, Add an item to your order first";
                    }
                    else
                    {
                        cout<<"\nEnter the code number of the item to be removed\t: ";
                        cin>>code;
                        for(int i=0;i<m;i++)
                        {
                            if(code==order[i].putcode())
                            {
                                order[i].printdata();
                                cout<<"\n\nEnter the amount of items to be removed\t :";
                                cin>>quantity;
                                order[i].change_quantity(quantity);
                                cout<<"\nDeleted successfully";
                                if(order[i].putquantity() <= 0)
                                {
                                    order[i]=order[m-1];
                                    m=m-1;
                                    temporder=new item[m];
                                    for(int i=0;i<m;i++)
                                    {
                                        temporder[i]=order[i];
                                    }
                                    delete[] order;
                                    order=new item[m];
                                    for(int i=0;i<m;i++)
                                    {
                                        order[i]=temporder[i];
                                    }
                                    delete[] temporder;
                                    
                                    sort(order,m);
                                }
                                stop=1;
                                break;
                            }    
                        }
                        if(stop==0)
                        {
                            cout<<"\nNo such item have added to the order,Try again";
                        }
                        stop=0;
                    }
                }
                else if(action2 == 3)
                {
                    cout<<"\n________________________________________________________________________________________________________";
                    cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
                    for(int i=0;i<m;i++)
                    {
                        order[i].printdata();
                    }    
                    cout<<"\n________________________________________________________________________________________________________";
                }
                else if(action2 == 4)
                {
                    total = 0;
                    cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
                    for(int i=0;i<m;i++)
                    {
                        order[i].printdata();
                        total=total+order[i].puttotal();
                    }
                    cout<<"\n\nTotal\t\t: "<<total;
                    cout<<"\n\nThank you for the purchase\n";
                    for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(order[i].putcode()==stock[j].putcode())
                            {
                                stock[j].change_quantity(order[i].putquantity());
                                if(stock[i].putquantity() <= 0)
                                {
                                    stock[i]=stock[n-1];
                                    n=n-1;
                                    tempstock=new item[n];
                                    for(int i=0;i<n;i++)
                                    {
                                        tempstock[i]=stock[i];
                                    }
                                    delete[] stock;
                                    stock=new item[n];
                                    for(int i=0;i<n;i++)
                                    {
                                        stock[i]=tempstock[i];
                                    }
                                    delete[] tempstock;
                                    stop=1;
                                    sort(stock,n);
                                }
                                break;
                            }
                        }
                    }
                    delete[] order;
                    stop = 1;
                }
                else if(action2 == 5)
                {
                    stop = 1;
                }
                else 
                {
                    cout<<"\nInvalid input, Try again";
                }
            }
            stop = 0;
            /*cout<<"\nCode\t\t\t\tName\t\t\t\tPrice\t\t\t\tQuantity";
            for(int i=0;i<n;i++)
            {
                stock[i].printdata();
                total=total+stock[i].puttotal();
            }
            cout<<"\n\nTotal\t\t: "<<total;
            cout<<"\n\nThank you for the purchase\n";
            delete[] stock;
            cout<<"stock deleted successfully";
            return 0;*/
        }
        else if(action1 == 4 && n == 0)
        {
            cout<<"There is no item in the stock";
        }
        else if(action1 == 5)
        {
            cout<<"Program Closed";
            delete[] stock;
            return 0;
        }
        else
        {
            cout<<"\nInvalid input,Try again";
        }
    }
}