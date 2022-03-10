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
    void sum(const Matrix &,const Matrix &);
    void product(const Matrix &,const Matrix &);
    int determinant(void);
    int trace(void);
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
void Matrix::sum(const Matrix &A,const Matrix &B)
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
        C.display();
    }
    else 
    cout<<"\nNumber of rows and coloumns not the same therefore not possible to find the sum\n";
}
void Matrix::product(const Matrix &A,const Matrix &B)
{
    Matrix C;
    float sum;
    if(A.row==B.colmn)
    {
        C.create(A.colmn,B.row);
        for(int i=0;i<A.colmn;i++)
        {
            for(int j=0;j<B.row;j++)
            {
                sum=0;
                for(int k=0;k<A.row;k++)
                {
                    sum=sum+(A.element[i][k]*B.element[k][j]);
                }  
                C.element[i][j]=sum;
            }
        }
        C.display();
    }
    else
    cout<<"\nNot possible to find the product of the given matrices\n";
}
int Matrix::determinant(void)
{

    float eeta;
    for(int i=0;i<colmn-1;i++)
    {
        for(int j=1;j<colmn;j++)
        {
            if(element[i][j]!=0)
            {
                eeta=element[i][i]/element[j][i];
                for(int k=0;k<colmn;k++)
                {
                    element[j][k]=element[i][k]-eeta*element[j][k];
                }
            }
        }
    }
    display();
    float determinant=1;
    for(int i=0;i<colmn;i++)
    determinant=determinant*element[i][i];
    return determinant;
}
int Matrix::trace(void)
{
    int trace=0;
    if(row==colmn)
    {
        for(int i=0;i<row;i++)
        trace=trace+element[i][i];
    }
    else
    cout<<"Row and Coloumn Not same\n";
    return trace; 
}
int main()
{
    Matrix A,B,C;
    int action;
    cout<<"\n1\t: Transpose of a matrix\n2\t: Sum of two matrices\n3\t: Product of two matrices\n4\t: Determinant of a matrix\n5\t: Trace of a matrix";
    cout<<"\nEnter the action\t: ";
    cin>>action;
    switch (action)
    {
    case 1:
        A.create();
        cout<<"\nA =";
        A.display();
        cout<<"\nA transpose =";
        A.transpose();
        break;
    case 2:
        A.create();
        cout<<"\nA =";
        A.display();
        B.create();
        cout<<"\nB =";
        B.display();
        cout<<"\nA+B =";
        C.sum(A,B);
        break;
    case 3:
        A.create();
        cout<<"\nA =";
        A.display();
        B.create();
        cout<<"\nB =";
        B.display();
        cout<<"\nA*B =";
        C.product(A,B);
        break;
    case 4:
        A.create();
        cout<<"\nA =";
        A.display();
        cout<<"\nDeterminant of matrix\t= "<<A.determinant();
        break;
    case 5:
        A.create();
        cout<<"\nA =";
        A.display();
        cout<<"\nTrace of the matrix\t= "<<A.trace();
    default:
        cout<<"\nInvalid input, Try again";
        break;
    }
    return 0;
}