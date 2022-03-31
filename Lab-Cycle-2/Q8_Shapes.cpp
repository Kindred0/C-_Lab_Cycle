#include <iostream>
using namespace std;
class shape
{
    protected:
    float side1, side2;
    public:
    float virtual getarea()=0;
    void virtual get_data()=0;
};
class square:public shape
{
    public:
    void get_data(void)
    {
        cout<<"\nSide\t: ";
        cin>>side1;
        side2=side1;
    }
    float getarea(void)
    {
        return side1*side2;
    }
};
class rectangle:public shape
{
    public:
    void get_data(void)
    {
        cout<<"\nLength\t: ";
        cin>>side1;
        cout<<"Breadth\t: ";
        cin>>side2;
    }
    float getarea(void)
    {
        return side1*side2;
    }
};
class circle:public shape
{
    public:
    void get_data(void)
    {
        cout<<"\nRadius\t: ";
        cin>>side1;
        side2=side1;
    }
    float getarea(void)
    {
        return side1*side2*3.14;
    }
};
class ellipse:public shape
{
    public:
    void get_data(void)
    {
        cout<<"\nMajor Axis\t: ";
        cin>>side1;
        cout<<"Minor Axis\t: ";
        cin>>side2;
    }
    float getarea(void)
    {
        return side1*side2*3.14;
    }
};
int main()
{
    shape *p;
    float side1,side2;
    int action=0;
    while(action==0)
    {
        cout<<"\n1\t: Square\n2\t: Rectangle\n3\t: Circle\n4\t: Ellipse\nEnter the action\t: ";
        cin>>action;
        switch(action)
        {
            case 1 :p=new square;
                    break;
            case 2 :p=new rectangle;
                    break;
            case 3 :p=new circle;
                    break;
            case 4 :p=new ellipse;
                    break;
            default:cout<<"\nInvalid action, try again";
                    action=0;
                    break;
        }
    }
    p->get_data();
    cout<<"\nArea\t: "<<p->getarea()<<endl;
    return 0;
}
