#include <iostream>
using namespace std;
class complex
{
    float real,image;
    public:
    void input(void);
    void display(void);
    complex(){};
    complex(float r,float i)
    {
        real=r;
        image=i;
    }
    friend complex operator+(complex,complex);
};
complex operator+(complex a,complex b)
{
    return complex((a.real+b.real),(a.image+b.image));
}
void complex::input(void)
{
    cout<<"\nEnter the real part 		: ";
    cin>>real;
    cout<<"\nEnter the imaginary part 	: ";
    cin>>image;
}
void complex::display(void)
{
    cout<<real<<" + "<<image<<"i\n";
}
int main()
{
    complex z1,z2,z3;
    z1.input();
    cout<<"\nZ1 				= ";
    z1.display();
    z2.input();
    cout<<"\nZ2 				= ";
    z2.display();
    z3=z1+z2;
    cout<<"\nZ3 				= Z1 + Z2\n "<<"\nZ3 				= ";
    z3.display();
    return 0;
}
