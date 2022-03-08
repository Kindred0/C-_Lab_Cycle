#include <iostream>
using namespace std;
class complex 
{
    float  image;
    float real;
    public:
    complex(){};
    complex(float x)
    {
        image=x;
        real=x;
    }
    complex(float r,float i)
    {
        real=r;
        image =i;
    }
    complex(const complex &,const complex &);
    complex operator+(complex);
    void display(void)
    {
        cout<<real<<" + "<<image<<"i"<<endl;
    }
};
complex::complex(const complex &a,const complex &b)
{
    real=a.real+b.real;
    image=a.image+b.image;
}
complex complex::operator+(complex a)
{
    complex b;
    b.real=real+a.real;
    b.image=image+a.image;
    return b;
}
int main()
{
    float r,i;
    cout<<"\nEnter the real and imaginary part of complex Z1 : "<<endl;
    cin>>r>>i;
    complex A(r,i);
    cout<<"\nZ1 = ";
    A.display();
    cout<<"\nEnter the real and imaginary part of complex Z2 : "<<endl;
    cin>>r>>i;
    complex B(r,i);
    cout<<"\nZ2 = ";
    B.display();
    complex C;
    C=A+B;
    cout<<"\nZ1 		= ";
    A.display();
    cout<<"\nZ2 		= ";
    B.display();
    cout<<"\nZ1 + Z2 	= ";
    C.display();
    complex D(A,C);
    cout<<"\nZ1 + Z3 	= ";
    D.display();
    return 0;
}
