#include <iostream>
using namespace std;
class class2;
class class1
{
    int x,y;
    public:
    friend void swap(class1 &,class2 &);
    void input(int,int);
    void display(void);
};
class class2
{
    int a,b;
    public:
    friend void swap(class1 &,class2 &);
    void input(int,int);
    void display(void);
};
void swap(class1 &p,class2 &s)
{
    int temp;
    temp=p.x;
    p.x=s.a;
    s.a=temp;
    temp=p.y;
    p.y=s.b;
    s.b=temp;
}
void class1::input(int u,int v)
{
    x=u;
    y=v;
}
void class1::display(void)
{
    cout<<"X : "<<x<<endl<<"Y : "<<y<<endl;
}
void class2::input(int u,int v)
{
    a=u;
    b=v;
}
void class2::display(void)
{
    cout<<"A : "<<a<<endl<<"B : "<<b<<endl;
}
int main()
{
    class1 var1;
    class2 var2;
    int u,v;
    cout<<"Enter Number 1 : ";
    cin>>u;
    cout<<"Enter Number 2 : ";
    cin>>v;
    var1.input(u,v);
    cout<<"Enter Number 3 : ";
    cin>>u;
    cout<<"Enter Number 4 : ";
    cin>>v;
    var2.input(u,v);
    cout<<"\nBefore swap"<<endl;
    var1.display();
    var2.display();
    swap(var1,var2);
    cout<<"\nAfter swap"<<endl;
    var1.display();
    var2.display();
    return 0;
}
