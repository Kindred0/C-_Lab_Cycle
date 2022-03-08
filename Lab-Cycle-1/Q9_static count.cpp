#include <iostream>
using namespace std;
class sample
{
    int a,b;
    public:
    static int count;
    static void updatecount(void);
    static void showcount(void);
    sample(void);
    sample(int);
    sample(int,int);
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
void sample::display(void)
{
    cout<<"x : "<<a<<endl<<"y : "<<b<<endl;
}
int main()
{
    int a,b;
    sample s1;
    cout<<"Sample object A : "<<endl;
    s1.display();
    sample::showcount();
    cout<<"Enter a number : "<<endl;
    cin>>a;
    sample s2(a);
    cout<<"Sample object B : "<<endl;
    s2.display();
    sample::showcount();
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    sample s3(a,b);
    cout<<"Sample object C : "<<endl;
    s3.display();
    sample::showcount();
    return 0;
}
