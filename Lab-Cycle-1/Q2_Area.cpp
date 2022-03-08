#include <iostream>
#include <math.h>
using namespace std;
float area(int angle, float length, float breadth) // Area of a parrellogram
{
    angle=angle*(float(355)/113)/180;
    return (length*breadth*sin(angle));
}
float area(float length, float breadth) // Area of rectangle
{
    return (length*breadth);
}
float area(float side) // Area of square
{
    return (side*side);
} 
float area(double major, double minor) //Area of ellipse
{
    return ((float(355)/113)*major*minor);
}
float area(double radius)// Area of circle
{
    return ((float(355)/113)*radius*radius);
}
float area(float a, float b, float c) // Area of a triangle with three sides
{
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
float area(float base, float side, int angle) // Area of trianlge with two sides and an angle between them
{
    angle=angle*(float(355)/113)/180;
    return (base*side*sin(angle)/2);
}
int main()
{
    int action, angle;
    float side1, side2, side3;
    double side4, side5;
    cout<<"Actions\n\n";
    cout<<"1\t: Parellogram\n2\t: Rectangle\n3\t: Square\n4\t: Ellipse\n5\t: Circle\n6\t: Triangle with three sides\n7\t: Triangle with two sides and angle\n";
    cout<<"\n\nEnter the shape to find the area \t= ";
    cin>>action;
    switch(action)
    {
        case 1: cout<<"\nBase              : ";
                cin>>side1;
                cout<<"\nSide              : ";
                cin>>side2;
                cout<<"\nAngle in degree   : ";
                cin>>angle;
                cout<<"\nArea is   : "<<area(angle, side1, side2)<<endl;
                break;
        case 2: cout<<"\nLength    : ";
                cin>>side1;
                cout<<"\nBreadth   : ";
                cin>>side2;
                cout<<"\nArea is   : "<<area(side1, side2)<<endl;
                break;
        case 3: cout<<"\nSide      : ";
                cin>>side1;
                cout<<"\nArea is   : "<<area(side1)<<endl;
                break;
        case 4: cout<<"\nMajor     : ";
                cin>>side4;
                cout<<"\nMinor     : ";
                cin>>side5;
                cout<<"\nArea is   : "<<area(side4, side5)<<endl;
                break;
        case 5: cout<<"\nRadius    : ";
                cin>>side4;
                cout<<"\nArea is   : "<<area(side4)<<endl;
                break;
        case 6: cout<<"\nside 1    : ";
                cin>>side1;
                cout<<"\nside 2    : ";
                cin>>side2;
                cout<<"\nside 3    : ";
                cin>>side3;
                cout<<"\nArea is   : "<<area(side1, side2, side3)<<endl;
                break;
        case 7: cout<<"\nBase              : ";
                cin>>side1;
                cout<<"\nSide              : ";
                cin>>side2;
                cout<<"\nAngle in degree   : ";
                cin>>angle;
                cout<<"\nArea is   : "<<area(angle, side1, side2)<<endl;
                break;
        default:cout<<"\nInvalid input";
                break;
    }
    return 0;
}

