#include <iostream>
using namespace std;
class MATRIX
{
    float element[10][10];
    int row;
    int coloumn;
    int digit=0;
    void getdigit(int);
    int noofdigit(int);
    void printspace(int);
    public:
    void matrix_input(int,int);
    friend MATRIX matrix_add(MATRIX,MATRIX);
    friend MATRIX matrix_traspose(MATRIX);
    friend MATRIX matrix_mult(MATRIX,MATRIX);
    friend float matrix_determinant(MATRIX);
    friend int matrix_trace(MATRIX);
    void display(void);
};
void MATRIX::matrix_input(int r,int c)
{
    if((r>0)&&(c>0))
    {
        int i,j;
        row=r;
        coloumn=c;
        for(i=0;i<row;i++)
        {
            for(j=0;j<coloumn;j++)
            {
                cout<<"\nEnter the element at row = "<<i+1<<" and coloumn = "<<j+1<<" : ";
                cin>>element[i][j];
                getdigit(element[i][j]);
            }
        }
    }
    else 
    cout<<"\nInvalid input";
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
        for(int j=1;j<A.coloumn;j++)
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
    int i;
    for(i=0;a!=0;i++)
    a=a/10;
    if(i==0)
    i=i+1;
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
    cout<<"\n List of actions\n\n Find the traspose of a matrix 		= 1\n Find the sum of two matrix 		= 2\n Find the product of two matrix 	= 3\n Find the determinant of matrix 	= 4";
    cout<<"\n\n Enter the action : ";
    cin>>action;
    switch (action)
    {
    case 1 :cout<<"\nEnter the number of rows : ";
            cin>>row1;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn1;
            A.matrix_input(row1,coloumn1);
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
            A.matrix_input(row1,coloumn1);
            A.display();
            cout<<"\nSecond Matrix";
            cout<<"\nEnter the number of rows : ";
            cin>>row2;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn2;
            B.matrix_input(row2,coloumn2);
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
            A.matrix_input(row1,coloumn1);
            A.display();
            cout<<"\nSecond Matrix";
            cout<<"\nEnter the number of rows : ";
            cin>>row2;
            cout<<"\nEnter the number of coloumns : ";
            cin>>coloumn2;
            B.matrix_input(row2,coloumn2);
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
            A.matrix_input(row1,coloumn1);
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
            A.matrix_input(row1,row1);
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
