#include <iostream>
using namespace std;
class sample
{
    int **d_array;
    int row,coloumn;
    public:
    sample(){}
    sample(int,int);
    ~sample();
    void getelement(void);
    void display(void);
};
sample::sample(int r,int c)
{
    row=r;
    coloumn=c;
    d_array=new int*[row];
    cout<<"\nArray of pointers of length "<<row<<" is created with constructors"<<endl;
    for(int i=0;i<row;i++)
    {
        d_array[i]=new int[coloumn];
        cout<<"\nArray of integer of length "<<coloumn<<" is dynamically created at location "<<i;
    }
}
sample::~sample(void)
{
    for(int i=0;i<row;i++)
    {
        delete d_array[i];
        cout<<"\nThe dynamically created integer array at location "<<i<<" is successfully deleted";
    }
    delete[] d_array;
    cout<<"\nThe pointer array is successfully deleted using the destructor";
}
void sample::getelement(void)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<coloumn;j++)
        {
            cout<<"\nEnter at ["<<i<<"]["<<j<<"]\t: ";
            cin>>d_array[i][j];
        }
    }
}
void sample::display(void)
{
    cout<<"{ ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<coloumn;j++)
        {
            cout<<d_array[i][j]<<" ";
        }
        cout<<"| ";
    }
    cout<<"}";
}
int main()
{
    int row,coloumn;
    cout<<"\nEnter rows and coloumns respectively\t: ";
    cin>>row>>coloumn;
    sample s(row,coloumn);
    s.getelement();
    cout<<"\n";
    s.display();
    cout<<"\n";
    return 0;
}
