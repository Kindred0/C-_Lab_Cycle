#include <iostream>
#include <cmath>
using namespace std;
class vector
{
    int x,y,z;
    public:
    vector()
    {
        x=0;y=0;z=0;
    }
    vector(int a,int b,int c)
    {
        x=a;y=b;z=c;
    }
    float operator*(vector);          
    friend ostream & operator<<(ostream &,vector &);  
    friend istream & operator>>(istream &,vector &);  
};
float vector::operator*(vector A)
{
    return x*A.x+y*A.y+z*A.z;
}
ostream & operator<<(ostream &dout,vector &A)
{
    if(A.y>=0 && A.z>=0)
        cout<<A.x<<"i + "<<A.y<<"j + "<<A.z<<"k";
    else if(A.y<=0 && A.z>=0)
        cout<<A.x<<"i - "<<A.y*-1<<"j + "<<A.z<<"k";
    else if(A.y>=0 && A.z<=0)
        cout<<A.x<<"i + "<<A.y<<"j - "<<A.z*-1<<"k";
    else 
        cout<<A.x<<"i - "<<A.y*-1<<"j - "<<A.z*-1<<"k";
    return dout;
}
istream & operator>>(istream &din,vector &A)
{
    cin>>A.x>>A.y>>A.z;
    return din;
}
int main()
{
    vector A,B;
    cout<<"\nEnter the respective components of vector A\t: ";
    cin>>A;
    cout<<"\nA = ";
    cout<<A;
    cout<<"\n\nEnter the respective components of vector B\t: ";
    cin>>B;
    cout<<"\nB = ";
    cout<<B;
    cout<<"\n\nA * B\t = ";
    cout<<A*B<<"\n"<<endl;
    return 0;
}