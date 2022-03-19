#include <iostream>
using namespace std;
class Matrix
{
    int row,colmn;
    float **element;
    public:
    Matrix()
    {
        row=0;
        colmn=0;
        element=new float*[1];
    }
    ~Matrix();
    void create(void);
    void create(int,int);
    void operator+(const Matrix &);
    void operator*(const Matrix &);
    void display(void);
};
void Matrix::create()
{
    delete[] element;
    cout<<"\nEnter row\t: ";
    cin>>row;
    cout<<"\nEnter coloumn\t: ";
    cin>>colmn;
    cout<<"\n";
    element=new float*[row];
    for(int i=0;i<colmn;i++)
    {
        element[i]=new float[row];
        for(int j=0;j<row;j++)
        {
            cout<<"Enter at ["<<i+1<<"]["<<j+1<<"]\t: ";
            cin>>element[i][j];
        }
    }
}
void Matrix::create(int r,int c)
{
    delete[] element;
    row=r;
    colmn=c;
    element=new float*[row];
    for(int i=0;i<row;i++)
    {
        element[i]=new float[colmn];
    }
}
Matrix::~Matrix()
{
    for(int i=0;i<row;i++)
        delete[] element[i];
    delete element;
}
void Matrix::operator+(const Matrix &B)
{
    Matrix C;
    if((row==B.row)&&(colmn==B.colmn))
    {
        C.create(row,row);
        for(int i=0;i<C.row;i++)
        {
            for(int j=0;j<C.colmn;j++)
            {
                C.element[i][j]=element[i][j]+B.element[i][j];
            }
        }
        C.display();
    }
    else 
    cout<<"\nNumber of rows and coloumns not the same therefore not possible to find the sum\n";
}
void Matrix::operator*(const Matrix &B)
{
    Matrix C;
    float sum;
    if(row==B.colmn)
    {
        C.create(colmn,B.row);
        for(int i=0;i<colmn;i++)
        {
            for(int j=0;j<B.row;j++)
            {
                sum=0;
                for(int k=0;k<row;k++)
                {
                    sum=sum+(element[i][k]*B.element[k][j]);
                }  
                C.element[i][j]=sum;
            }
        }
        C.display();
    }
    else
    cout<<"\nNot possible to find the product of the given matrices\n";
}
void Matrix::display(void)
{
    cout<<"\n";
    for(int i=0;i<colmn;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<element[i][j]<<"\t";
        }
        cout<<"\n";
    }   
}
int main()
{
    Matrix A,B;
    cout<<"\nMatrix A\t:\n";
    A.create();
    A.display();
    cout<<"\nMatrix B\t:\n";
    B.create();
    B.display();
    cout<<"\nA + B = ";
    A+B;
    cout<<"\nA * B = ";
    A*B;
    return 0;
}