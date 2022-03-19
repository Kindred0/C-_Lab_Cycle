#include <iostream>
#include <cmath>
using namespace std;
class vector
{
    int x,y,z;
    float magnitude;
    public:
    vector(){};
    vector(int,int,int);
    bool operator==(vector);
    bool operator!=(vector);
    bool operator<(vector);
    bool operator<=(vector);
    bool operator>(vector);
    bool operator>=(vector);
    void display(void);
};
vector::vector(int a,int b,int c)
{
    x=a;y=b;z=c;
    magnitude=x*x+y*y+z*z;
    magnitude=sqrt(magnitude);
}
bool vector::operator==(vector A)
{
    if(((magnitude==A.magnitude)&&(x==A.x))&&((y==A.y)&&(z==A.z)))
    return true;
    else
    return false;
}
bool vector::operator!=(vector A)
{
    if(magnitude!=A.magnitude)
    return true;
    else
    return false;
}
bool vector::operator<(vector A)
{
    if(magnitude<A.magnitude)
    return true;
    else
    return false;
}
bool vector::operator<=(vector A)
{
    if(magnitude<=A.magnitude)
    return true;
    else
    return false;
}
bool vector::operator>(vector A)
{
    if(magnitude>A.magnitude)
    return true;
    else
    return false;
}
bool vector::operator>=(vector A)
{
    if(magnitude>=A.magnitude)
    return true;
    else
    return false;
}
void vector::display(void)
{
    if(y>=0 && z>=0)
        cout<<x<<"i + "<<y<<"j + "<<z<<"k";
    else if(y<=0 && z>=0)
        cout<<x<<"i - "<<y*-1<<"j + "<<z<<"k";
    else if(y>=0 && z<=0)
        cout<<x<<"i + "<<y<<"j - "<<z*-1<<"k";
    else 
        cout<<x<<"i - "<<y*-1<<"j - "<<z*-1<<"k";
}
int main()
{
    int a,b,c;
    cout<<"Enter three components of the vector 1\t: \n";
    cin>>a>>b>>c;
    vector v1(a,b,c);
    cout<<"\nEnter three componets of the vector 2\t: \n";
    cin>>a>>b>>c;
    vector v2(a,b,c);
    cout<<"\nVector 1\t: ";
    v1.display();
    cout<<"\nVector 2\t: ";
    v2.display();
    if(v1==v2)
    cout<<"\nThe vector are equal";
    else if(!(v1!=v2))
    cout<<"\nThe magnitude of the vectors are equal";
    else if(v1>v2)
    cout<<"\nThe magnitude of the vector 1 is greater";
    else
    cout<<"\nThe magnitude of the vector 2 is greater";
    cout<<endl;
    return 0;
}
