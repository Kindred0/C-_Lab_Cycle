#include <iostream>
using namespace std;
class Time
{
    int hours, minutes, seconds;
    public:
    void input(void);
    void display(void);
    void sum(Time,Time);
};
void Time::display(void)
{
    cout<<"\n"<<hours<<" hours "<<minutes<<" minutes and "<<seconds<<" seconds ";
}
void Time::input(void)
{
    cout<<"Enter seconds\t: ";
    cin>>seconds;
    cout<<"Enter minutes\t: ";
    cin>>minutes;
    cout<<"Enter hours\t: ";
    cin>>hours;
    minutes=minutes+(seconds/60);
    seconds=seconds%60;
    hours=hours+(minutes/60);
    minutes=minutes%60;
}
void Time::sum(Time t1,Time t2)
{
    seconds=t1.seconds+t2.seconds;
    minutes=seconds/60;
    seconds=seconds%60;
    minutes=minutes+t1.minutes+t2.minutes;
    hours=minutes/60;
    minutes=minutes%60;
    hours=hours+t1.hours+t2.hours;
}
int main()
{
    Time t1,t2,t3;
    cout<<"\nTime 1\n";
    t1.input();
    t1.display();
    cout<<"\n\nTime 2\n";
    t2.input();
    t3.sum(t1,t2);
    t2.display();
    cout<<"\n\nThe time is "<<endl;
    t3.display();
    cout<<"\n";
    return 0;
}
