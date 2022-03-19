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
    float operator*();          //* gives magnitude of the vector
    float operator<<(vector);   //<< gives the dot product of two vectors
    vector operator>>(vector);  //>> gives the cross product of two vectors
    void display(void);
};
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
float vector::operator*()
{
    return sqrt(x*x+y*y+z*z);
}
float vector::operator<<(vector A)
{
    float dot=x*A.x+y*A.y+z*A.z;
    return dot;
}
vector vector::operator>>(vector A)
{
    vector cross;
    cross.x=(y*A.z)-(z*A.y);
    cross.y=(z*A.x)-(x*A.z);
    cross.z=(x*A.y)-(y*A.x);
    return cross;
}
int main()
{
    vector A,B,Cross;
    float dot;
    int i,j,k;
    cout<<"\nEnter components of vector A\t: ";
    cin>>i>>j>>k;
    A=vector(i,j,k);
    cout<<"A = \n";
    A.display();
    cout<<"\nMagintude of A\t: "<<*A;
    cout<<"\n\nEnter components of vector B\t: ";
    cin>>i>>j>>k;
    B=vector(i,j,k);
    cout<<"B = \n";
    B.display();
    cout<<"\nMagintude of B\t: "<<*B;
    dot=A<<B;
    cout<<"\n\nA . B = "<<dot;
    Cross=A>>B;
    cout<<"\n\nA * B = ";
    Cross.display();
    cout<<"\n\nMagintude of the resultant vector\t: "<<*Cross<<"\n";
    return 0;
}