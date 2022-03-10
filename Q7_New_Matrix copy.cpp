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
    void transpose(void);
    friend Matrix sum(const Matrix &,const Matrix &);
    void product(Matrix,Matrix);
    int determinatn(void);
    int trace(void);
    void display(void);
};
void Matrix::create()
{
    delete[] element;
    cout<<"\nEnter row\t: ";
    cin>>row;
    cout<<"\nEnter coloumn\t:  ";
    cin>>colmn;
    cout<<row<<colmn;
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
    cout<<"destructor called";
    for(int i=0;i<row;i++)
        delete[] element[i];
    delete element;
}
void Matrix::transpose(void)
{
    cout<<"\n";
    for(int j=0;j<row;j++)
    {
        for(int i=0;i<colmn;i++)
        {
            cout<<element[i][j]<<"\t";
        }
        cout<<"\n";
    }
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
Matrix sum(const Matrix &A,const Matrix &B)
{
    Matrix C;
    if((A.row==B.row)&&(A.colmn==B.colmn))
    {
        C.create(A.row,B.row);
        for(int i=0;i<C.row;i++)
        {
            for(int j=0;j<C.colmn;j++)
            {
                C.element[i][j]=A.element[i][j]+B.element[i][j];
            }
        }
    }
    else 
    cout<<"\nNumber of rows and coloumns not the same therefore not possible to find the sum.";
    return C;
}
int main()
{
    Matrix A,B,C;
    A.create();
    cout<<"A =";
    A.display();
    cout<<"A transpose =";
    A.transpose();
    B.create();
    cout<<"B =";
    B.display();
    cout<<"C =";
    C=sum(A,B);
    C.display();
    return 0;
}