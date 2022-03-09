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
    complex sum(complex);
    void display(void);
};
void complex::display(void)
{
    if(real!=0)
    {
        if(image>0)
        cout<<real<<" + "<<image<<"i";
        else if(image<0)
        cout<<real<<" - "<<image*-1<<"i";
        else
        cout<<real;
    }
    else
    cout<<image<<"i";
}
complex::complex(const complex &a,const complex &b)
{
    real=a.real+b.real;
    image=a.image+b.image;
}
complex complex::sum(complex a)
{
    complex b;
    b.real=real+a.real;
    b.image=image+a.image;
    return b;
}
int main()
{
    complex A,B,C,D;
    float r,i;
    cout<<"\nEnter the real and imaginary part of complex Z1 : ";
    cin>>r>>i;
    A=complex(r,i);
    cout<<"\nZ1 = ";
    A.display();
    cout<<"\nEnter the real and imaginary part of complex Z2 : ";
    cin>>r>>i;
    B=complex(r,i);
    cout<<"\nZ2 = ";
    B.display();
    C=A.sum(B);
    cout<<"\nZ1 		= ";
    A.display();
    cout<<"\nZ2 		= ";
    B.display();
    cout<<"\nZ1 + Z2 	= ";
    C.display();
    D=complex(A,C);
    cout<<"\nZ1 + Z3 	= ";
    D.display();
    cout<<"\n";
    return 0;
}
