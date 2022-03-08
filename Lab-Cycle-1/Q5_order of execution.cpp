#include <iostream>
using namespace std;
class sample
{
    int *array;
    int size;
    public:
    sample(){}
    sample(int);
    ~sample();
    void getelement(void);
    void display(void);
};
sample::sample(int n)
{
    size=n;
    array=new int[size];
    cout<<"\nConstructor is called during execution"<<endl;
}
sample::~sample(void)
{
    delete[] array;
    cout<<"\n\nSuccesfully deleted"<<endl<<"\nDestructor is called after execution";
}
void sample::getelement(void)
{
    for(int i=0;i<size;i++)
    {
        cout<<"\nEnter element : ";
        cin>>array[i];
    }
}
void sample::display(void)
{
	cout<<endl;
    for(int i=0;i<size;i++)
    cout<<array[i]<<" ";
}
int main()
{
    int size;
    cout<<"\nEnter the size of the array : ";
    cin>>size;
    sample s(size);
    s.getelement();
    s.display();
    return 0;
}
