#include <iostream>
#include <math.h>
using namespace std;
float area(int angle, float length, float breadth) // Area of a parrellogram
{
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
    return (3.14*major*minor);
}
float area(double radius)// Area of circle
{
    return (3.14*radius*radius);
}
float area(float a, float b, float c) // Area of a triangle with three sides
{
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
float area(float base, float side, int angle) // Area of trianlge with two sides and an angle between them
{
    return (base*side*sin(angle)/2);
}
int main()
{
    int action, angle;
    float side1, side2, side3;
    double side4, side5;
    cout<<" Actions\n\n";
    cout<<" Parrellogram \t\t\t\t= 1 \n Rectangle \t\t\t\t= 2 \n Square \t\t\t\t= 3 \n Ellipse \t\t\t\t= 4 \n Circle \t\t\t\t= 5 \n Triangle with three sides \t\t= 6 \n Triangle with two sides and an angle \t= 7";
    cout<<"\n\n Enter the shape to find the area \t= ";
    cin>>action;
    switch(action)
    {
        case 1: cout<<"\n Base      : ";
                cin>>side1;
                cout<<"\n Side      : ";
                cin>>side2;
                cout<<"\n Angle     : ";
                cin>>angle;
                cout<<"\n Area is   : "<<area(angle, side1, side2)<<endl;
                break;
        case 2: cout<<"\n Length    : ";
                cin>>side1;
                cout<<"\n Breadth   : ";
                cin>>side2;
                cout<<"\n Area is   : "<<area(side1, side2)<<endl;
                break;
        case 3: cout<<"\n Side      : ";
                cin>>side1;
                cout<<"\n Area is   : "<<area(side1)<<endl;
                break;
        case 4: cout<<"\n Major     : ";
                cin>>side4;
                cout<<"\n Minor     : ";
                cin>>side5;
                cout<<"\n Area is   : "<<area(side4, side5)<<endl;
                break;
        case 5: cout<<"\n Radius    : ";
                cin>>side4;
                cout<<"\n Area is   : "<<area(side4)<<endl;
                break;
        case 6: cout<<"\n side 1    : ";
                cin>>side1;
                cout<<"\n side 2    : ";
                cin>>side2;
                cout<<"\n side 3    : ";
                cin>>side3;
                cout<<"\n Area is   : "<<area(side1, side2, side3)<<endl;
                break;
        case 7: cout<<"\n Base      : ";
                cin>>side1;
                cout<<"\n Side      : ";
                cin>>side2;
                cout<<"\n Angle     : ";
                cin>>angle;
                cout<<"\n Area is   : "<<area(angle, side1, side2)<<endl;
                break;
        default:cout<<"\n Invalid input";
                break;
    }
    return 0;
}

