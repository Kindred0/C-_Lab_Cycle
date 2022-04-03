#include <iostream>
using namespace std;
class test
{
    float x,y;
    public:
    test(){};
    test(float a,float b){x=a;y=b;}
    float devide(void)
    {
        if((x+y)==0)
        throw("\nZero Devision");
        return x/(x+y);
    }
};
int main()
{
    int a,b;
    cout<<"Enter two numbers\t: ";
    cin>>a>>b;
    test t(a,b);
    try
    {
        cout<<t.devide();
    }
    catch(char const* a)
    {
        cout<<a<<"\nProgram terminated"<<endl;
    }
    cout<<endl;
    return 0;
}