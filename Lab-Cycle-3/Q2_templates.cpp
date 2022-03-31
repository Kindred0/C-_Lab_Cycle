#include <iostream>
using namespace std;
template <class type>
class vector
{
    type x,y,z;
    public:
    vector(void)
    {
        x=0;y=0;z=0;
    }
    vector(type a,type b,type c)
    {
        x=a;y=b;z=c;
    }
    void display(void)
    {
        cout<<x<<"i + "<<y<<"j + "<<z<<"k";
    }
    vector<type> operator+(vector<type> A)
    {
        vector<type> B;
        B.x=x+A.x;
        B.y=y+A.y;
        B.z=z+A.z;
        return B;
    }
};
int main()
{
    int action=0;
    while(action==0)
    {
        cout<<"\n1\t: Integer Vector\n2\t: Floating Point Vector\n3\t: Double Vector\n4\t: Character Vector (Vector of Unknowns)";
        cout<<"\nEnter the type of the vector\t: ";
        cin>>action;
        if(action==1)
        {
            int a,b,c;
            cout<<"\nEnter each components respectively of the vector A\t: ";
            cin>>a>>b>>c;
            vector<int> A(a,b,c);
            cout<<"A\t= ";
            A.display();
            cout<<"\nEnter each components respectively of the vector B\t: ";
            cin>>a>>b>>c;
            vector<int> B(a,b,c);
            cout<<"B\t= ";
            B.display();
            A=A+B;
            cout<<"\nA + B\t= ";
            A.display();
        }
        else if(action==2)
        {
            float a,b,c;
            cout<<"\nEnter each components respectively of the vector A\t: ";
            cin>>a>>b>>c;
            vector<float> A(a,b,c);
            cout<<"A\t= ";
            A.display();
            cout<<"\nEnter each components respectively of the vector B\t: ";
            cin>>a>>b>>c;
            vector<float> B(a,b,c);
            cout<<"B\t= ";
            B.display();
            A=A+B;
            cout<<"\nA + B\t= ";
            A.display();
        }
        else if(action==3)
        {
            double a,b,c;
            cout<<"\nEnter each components respectively of the vector A\t: ";
            cin>>a>>b>>c;
            vector<double> A(a,b,c);
            cout<<"A\t= ";
            A.display();
            cout<<"\nEnter each components respectively of the vector B\t: ";
            cin>>a>>b>>c;
            vector<double> B(a,b,c);
            cout<<"B\t= ";
            B.display();
            A=A+B;
            cout<<"\nA + B\t= ";
            A.display();
        }
        else if(action==4)
        {
            char a,b,c;
            cout<<"\nEnter each components respectively of the vector A\t: ";
            cin>>a>>b>>c;
            vector<char> A(a,b,c);
            cout<<"A\t= ";
            A.display();
        }
        else
        {
            cout<<"Invalid action, Try again";
            action=0;
        }
    }
    cout<<endl;
    return 0;
}