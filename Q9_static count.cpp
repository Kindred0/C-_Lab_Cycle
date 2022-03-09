#include <iostream>
using namespace std;
class sample
{
    int a,b;
    static int count;
    public:
    static void showcount(void);
    static void updatecount(void);
    sample(void);
    sample(int);
    sample(int,int);
    ~sample();
    void display(void);
};
int sample::count=0;
void sample::updatecount(void)
{
    count=count+1;
}
void sample::showcount(void)
{
    cout<<"The number of sample object created : "<<count<<endl;
}
sample::sample(void)
{
    updatecount();
    a=0;
    b=0;
}
sample::sample(int x)
{
    updatecount();
    a=x;
    b=x;
}
sample::sample(int x,int y)
{
    updatecount();
    a=x;
    b=y;
}
sample::~sample()
{
    count=count-1;
}
void sample::display(void)
{
    cout<<"x : "<<a<<endl<<"y : "<<b<<endl;
}
int main()
{
    int a,b,n=0;
    char action='y';
    sample *list,*templist;
    list=new sample[1];
    cout<<"\nEnter two numbers\t: ";
    cin>>a>>b;
    list[1]=sample(a,b);
    cout<<"\nDo you want to create a new object?\n(Type y for yes and n for no)\n";
    cin>>action;
    while(action=='y')
    {
        templist=new sample[n];
        for(int i=0;i<n;i++)
        {
            templist[i]=list[i];
        }
        delete[] list;
        list=new sample[n+1];
        for(int i=0;i<n;i++)
        {
            list[i]=templist[i];
        }
        delete[] templist;
        cout<<"\nEnter two number\t: ";
        cin>>a>>b;
        list[n]=sample(a,b);
        cout<<"\nDo you want to create a new object?\n(Type y for yes and n for no)\n";
        cin>>action;
    }
    sample::showcount();
    return 0;
}

