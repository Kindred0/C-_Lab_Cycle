#include <iostream>
using namespace std;
class complex
{
    int real,image;
    public:
    complex(){}
    complex(int,int);
    void display(void);
    friend complex operator+(complex,complex);
    friend complex operator*(complex,complex);
};
complex::complex(int r,int i)
{
    real=r;
    image=i;
}
void complex::display(void)
{
    if(image>0)
    cout<<real<<" + "<<image<<"i";
    else if(image<0)
    cout<<real<<" - "<<image*-1<<"i";
    else 
    cout<<real;
}
complex operator+(complex A,complex B)
{
    complex C;
    C.real=A.real+B.real;
    C.image=A.image+B.image;
    return C;
}
complex operator*(complex A,complex B)
{
    complex C;
    C.real=(A.real*B.real)-(A.image*B.image);
    C.image=(A.real*B.image)+(A.image*B.real);
    return C;
}
int main()
{
    complex C;
    int real,image;
    cout<<"\nEnter the real and image respectively of the first complex\t: \n";
    cin>>real>>image;
    complex A(real,image);
    cout<<"\nEnter the real and image respectively of the second complex\t: \n";
    cin>>real>>image;
    complex B(real,image);
    cout<<"\nFirst Complex\t: ";
    A.display();
    cout<<"\nSecond Complex\t: ";
    B.display();
    C=A+B;
    cout<<"\nA + B = ";
    C.display();
    C=A*B;
    cout<<"\nA * B = ";
    C.display();
    cout<<endl;
    return 0;
}
