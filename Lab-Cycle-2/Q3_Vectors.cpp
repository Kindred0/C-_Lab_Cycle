#include <iostream>
#include <cmath>
using namespace std;
class vector
{
    int x,y,z;
    public:
    vector(){}
    vector(int,int,int);
    float operator*();          //* gives magnitude of the vector
    float operator<<(vector);   //<< gives the dot product of two vectors
    vector operator>>(vector);  //>> gives the cross product
    void display(void);
};
void vector::display(void)
{
    cout<<x<<"i + "<<y<<"j + "<<z<<"k";
}
vector::vector(int a,int b,int c)
{
    x=a;y=b;z=c;
}
float vector::operator*()
{
    return sqrt(x*x+y*y+z*z);
}
float vector::operator<<(vector A)
{
    float dot_product=x*A.x+y*A.y+z*A.z;
    return dot_product;
}
vector vector::operator>>()