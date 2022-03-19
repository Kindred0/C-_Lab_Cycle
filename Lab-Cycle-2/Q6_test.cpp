#include <iostream>
#include <cstring>
using namespace std;
class student
{
    protected:
    string name;
    int rollno;
    public:
    student(){}
    student(string N,int r){name=N,rollno=r;}
};
class test:private virtual student
{
    protected:
    float physics,chemistry,maths;
    public:
    test(){}
    test(string N,int r, float p,float c,float m):student(N,r)
    {
        if(p>100)
        p=100;
        if(c>100)
        c=100;
        if(m>100)
        m=100;
        if(p<0)
        p=-p;
        if(c<0)
        c=-c;
        if(m<0)
        m=-m;
        physics=p;chemistry=c;maths=m;
    }
};
class sports:public virtual student
{
    protected:
    float score;
    public:
    sports(){}
    sports(string N,int r,float s):student(N,r)
    {
        if(s>100)
        s=100;
        if(s<0)
        s=-s;
        score=s;
    }
};
class result:private test,private sports
{
    float total=physics+chemistry+maths+score;
    public:
    result(){};
    result(string N,int r,float p,float c,float m,float s):test(N,r,p,c,m),sports(N,r,s)
    {
        name=N,rollno=r;
    }
    void display(void)
    {
        cout<<"\nRollno\t\t: "<<rollno;
        cout<<"\nName\t\t: "<<name;
        cout<<"\nTotal score\t: "<<total<<"/"<<400<<endl;
    }
};
int main()
{
    string firstname,secondname;
    int roll_no;
    float mark1,mark2,mark3,mark4;
    cout<<"Enter name\t: ";
    cin>>firstname>>secondname;
    firstname=firstname+" "+secondname;
    cout<<"Enter roll no\t: ";
    cin>>roll_no;
    cout<<"Enter marks\nPhysics\t\t: ";
    cin>>mark1;
    cout<<"Chemistry\t: ";
    cin>>mark2;
    cout<<"Maths\t\t: ";
    cin>>mark3;
    cout<<"Sports\t\t: ";
    cin>>mark4;
    result r1(firstname,roll_no,mark1,mark2,mark3,mark4);
    r1.display();
    return 0;
}