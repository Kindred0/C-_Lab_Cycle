#include <iostream>
using namespace std;
class MATRIX
{
    float **element;
    int row;
    int coloumn;
    int digit=0;
    void getdigit(int);
    int noofdigit(int);
    void printspace(int);
    public:
    MATRIX(){};
    MATRIX(int,int);
    ~MATRIX();
    void matrix_input(void);
    friend MATRIX matrix_add(MATRIX,MATRIX);
    friend MATRIX matrix_traspose(MATRIX);
    friend MATRIX matrix_mult(MATRIX,MATRIX);
    friend float matrix_determinant(MATRIX);
    friend int matrix_trace(MATRIX);
    void display(void);
};
MATRIX::MATRIX(int a,int b)
{
    if(a<0)
    a=a*-1;
    else if(a=0)
    a=1;
    if(b<0)
    b=b*-1;
    else if(b=0)
    b=1;
    row=a;
    coloumn=b;
    element=new float*[row];
    cout<<"Array of pointers dynamically constructed";
    for(int i=0;i<row;i++)
    {
        element[i]=new float[coloumn];
        cout<<"Array of floating point numbers successfully created at the location "<<i;
    }
}
MATRIX::~MATRIX()
{
    for(int i=0;i<row;i++)
    delete[] element[i];
    delete[] element;
}
void MATRIX::matrix_input(void)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<coloumn;j++)
        {
            cout<<"\nEnter the element at row = "<<i+1<<" and coloumn = "<<j+1<<" : ";
            cin>>element[i][j];
            getdigit(element[i][j]);
        }
    } 
}
void MATRIX::display(void)
{ 
    int i,j;  
    for(i=0;i<row;i++)
    {
        cout<<"\n[ ";
        for(j=0;j<coloumn;j++)
        {
            cout<<element[i][j];
            printspace(digit-noofdigit(element[i][j])+1);
        }
        cout<<"]";
    }
}
MATRIX matrix_add(MATRIX A,MATRIX B)
{
    int i,j;
    MATRIX C;
    if((A.row==B.row)&&(A.coloumn==B.coloumn))
    {
        C.row=A.row;
        C.coloumn=A.coloumn;
        for(i=0;i<C.row;i++)
        {
            for(j=0;j<C.coloumn;j++)
            {
                C.element[i][j]=A.element[i][j]+B.element[i][j];
                C.getdigit(C.element[i][j]);
            }
        }
    }
    else 
    cout<<"\nNumber of rows and coloumns not the same therefore not possible to find the sum.";
    return C;
}
MATRIX matrix_traspose(MATRIX A)
{
    int i,j;
    MATRIX B;
    B.row=A.coloumn;
    B.coloumn=A.row;
    B.digit=A.digit;
    for(i=0;i<B.row;i++)
    {
        for(j=0;j<B.coloumn;j++)
        {
            B.element[i][j]=A.element[j][i];
        }
    }
    return B;
}
MATRIX matrix_mult(MATRIX A,MATRIX B)
{
    int i,j,k;
    MATRIX C;
    float sum;
    if(A.coloumn==B.row)
    {
        C.row=A.row;
        C.coloumn=B.coloumn;
        for(i=0;i<A.row;i++)
        {
            for(j=0;j<B.coloumn;j++)
            {
                sum=0;
                for(k=0;k<A.coloumn;k++)
                {
                    sum=sum+(A.element[i][k]*B.element[k][j]);
                }  
                C.element[i][j]=sum;
                C.getdigit(C.element[i][j]);
            }
        }
    }
    else
    cout<<"\nNot possible to find the product of the given matrices.";
    return C;
}
float matrix_determinant(MATRIX A)
{
    float eeta;
    for(int i=0;i<A.coloumn-1;i++)
    {
        for(int j=i+1;j<A.coloumn;j++)
        {
            if(A.element[i][j]!=0)
            {
                eeta=A.element[i][i]/A.element[j][i];
                for(int k=0;k<A.coloumn;k++)
                {
                    A.element[j][k]=A.element[i][k]-eeta*A.element[j][k];
                }
            }
        }
    }
    float determinant=1;
    for(int i=0;i<A.coloumn;i++)
    determinant=determinant*A.element[i][i];
    return determinant;
}
int matrix_trace(MATRIX A)
{
    int trace=0;
    if(A.row==A.coloumn)
    {
        for(int i=0;i<A.row;i++)
        trace=trace+A.element[i][i];
    }
    else
    cout<<"Row and Coloumn Not same";
    return trace;   
}
int MATRIX::noofdigit(int a)
{
    int i=0;
    if(a<=0)
    i=1;
    while(a!=0)
    {
        a=a/10;
        i=i+1;
    }
    return i;
}
void MATRIX::getdigit(int a)
{
    if(noofdigit(a)>digit)
    digit=noofdigit(a);
}
void MATRIX::printspace(int x)
{
    for(int i=0;i<x;i++)
    cout<<" ";
}
int main()
{
    MATRIX A,B,C;
    int row1,coloumn1,row2,coloumn2,action;
    l4:
    cout<<"\n List of actions\n\n Find the traspose of a matrix 		= 1\n Find the sum of two matrix 		= 2\n Find the product of two matrix 	= 3\n Find the determinant of matrix 	= 4\n Find the trace of the matrix  =5";
    cout<<"\n\n Enter the action : ";
    cin>>action;
    switch (action)
    {
    case 1 :cout<<"\nEnter the number of rows : ";
            cin>>row1;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn1;
            A=MATRIX(row1,coloumn1);
            A.matrix_input();
            A.display();
            B=matrix_traspose(A);
            cout<<"\nTranspose of the given matrix = ";
            B.display();
            break;
    case 2 :l1:
            cout<<"\nFirst Matix : ";
            cout<<"\nEnter the number of rows : ";
            cin>>row1;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn1;
            A=MATRIX(row1,coloumn1);
            A.matrix_input();
            A.display();
            cout<<"\nSecond Matrix";
            cout<<"\nEnter the number of rows : ";
            cin>>row2;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn2;
            B=MATRIX(row2,coloumn2);
            B.matrix_input();
            B.display();
            if((row1==row2)&&(coloumn1==coloumn2))
            {
                C=matrix_add(A,B);
                cout<<"\nSum of the given matrices = ";
                C.display();
            }
            else 
            {
                cout<<"\nThe two matrices are not similar ,try again";
                goto l1;
            }
            break;
    case 3 :l2:
            cout<<"\nFirst Matix : ";
            cout<<"\nEnter the number of rows : ";
            cin>>row1;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn1;
            A=MATRIX(row1,coloumn1);
            A.matrix_input();
            A.display();
            cout<<"\nSecond Matrix";
            cout<<"\nEnter the number of rows : ";
            cin>>row2;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn2;
            B=MATRIX(row2,coloumn2);
            B.matrix_input();
            B.display();
            if(coloumn1==row2)
            {
                C=matrix_mult(A,B);
                cout<<"\nMatrix product of the given matrix = ";
                C.display();
            }
            else 
            {
                cout<<"\nThe given matrix cannot be multiplied, try again";
                goto l2;
            }
            break;
    case 4 :l3:
            cout<<"\nEnter the number of rows : ";
            cin>>row1;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn1;
            A=MATRIX(row1,coloumn1);
            A.matrix_input();
            A.display();
            if(row1==coloumn1)
            {
                cout<<"\nDeterminant of the given matrix = "<<matrix_determinant(A);
            }
            else
            {
                cout<<"\nThe matrix is not sqaure matrix so cannot find determinant, try again";
                goto l3;
            }
            break;
    case 5 :cout<<"Enter the number of rows/coloumns    : ";
            cin>>row1;
            A=MATRIX(row1,row1);
            A.matrix_input();
            A.display();
            cout<<"\nTrace of the matrix is   : ";
            cout<<matrix_trace(A);
            break;
    default:cout<<"Invalid action, try again";
            goto l4;
            break;
    }
    return 0;
}
