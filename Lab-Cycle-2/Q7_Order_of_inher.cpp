#include <iostream>
using namespace std;
class alpha
{
    protected:
    int x;
    public:
    alpha(void)
    {
        cout<<"\nThe alpha constructor is called";
    }
    alpha(int a)
    {
        x=a;
        cout<<"\nThe alpha constructor is called";        
    }
};
class beta
{
    protected:
    int y;
    public:
    beta(void)
    {
        cout<<"\nThe beta constructor is called";
    }
    beta(int a)
    {
        y=a;
        cout<<"\nThe beta constructor is called";
    }
};
class gamma:public alpha,public beta
{
    int z,total;
    public:
    gamma(void)
    {
        cout<<"\nThe gamma constructor is called";
    }
    gamma(int a,int b,int c):beta(a),alpha(b)
    {
        z=c;
        cout<<"\nThe gamma constructor is called";
    }
    void display(void)
    {
        total=x+y+z;
        cout<<"\nTotal\t: "<<total<<endl;
    }
};
int main()
{
    int x,y,z;
    cout<<"Enter three numbers\t: ";
    cin>>x>>y>>z;
    gamma g(x,y,z);
    g.display();
    return 0;
}