#include <iostream>
using namespace std;
class base
{
    protected:
    int x;
    public:
    base(){}
    base(int a)
    {
        x=a;
    }
};
class d1:public base
{
    protected:
    int y,z;
    public:
    d1(){}
    d1(int a,int b,int c):base(a)
    {
        y=b,z=c;
    }
};
class d2:public d1
{   
    int total;
    public:
    d2(){}
    d2(int a,int b,int c):d1(a,b,c)
    {
        total=x+y+z;
    }
    void display(void)
    {
        cout<<"\nTotal is\t: "<<total<<endl;
    }
};
class d3:public d1
{
    float average;
    public:
    d3(){}
    d3(int a,int b,int c):d1(a,b,c)
    {
        average=float(x+y+z)/3;
    }
    void display(void)
    {
        cout<<"\nAverage is\t: "<<average<<endl;
    }
};
int main()
{
    int x,y,z;
    cout<<"Enter three numbers\t: ";
    cin>>x>>y>>z;
    d2 A(x,y,z);
    d3 B(x,y,z);
    A.display();
    B.display();
    return 0;
}