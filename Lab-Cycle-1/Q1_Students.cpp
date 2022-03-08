#include <iostream>
#include <cstring>
using namespace std;
class student
{
    private:
    char *Name;
    int Roll_no; 
    int Mark1,Mark2,Mark3,total_mark;;
    static int out_of_mark;   
    public:
    static void update_total(int a)
    {
		out_of_mark=a;
	}
    ~student()
	{
		delete Name;
		cout<<"Successfully deleted";
	}
    void input(char*, int);
    void display(void);
    void calcGrade(void);
};
int student::out_of_mark=100;
void student::input(char* name, int roll_no)
{
    Name=new char[strlen(name)+1];
    strcpy(Name,name);
    Roll_no=roll_no;
    cout<<"Subject 1\t\t: ";
    cin>>Mark1;
    cout<<"Subject 2\t\t: ";
    cin>>Mark2;
    cout<<"Subject 3\t\t: ";
    cin>>Mark3;
    if(Mark1<0)
    Mark1=Mark1*-1;
    if(Mark2<0)
    Mark2=Mark2*-1;
    if(Mark3<0)
    Mark3=-1*Mark3;
    if(Mark1>out_of_mark)
    Mark1=out_of_mark;
    if(Mark2>out_of_mark)
    Mark2=out_of_mark;
    if(Mark3=out_of_mark)
    Mark3=out_of_mark;
}
void student::display(void)
{
    cout<<"\nName\t\t\t: "<<Name<<"\nRoll Number\t\t: "<<Roll_no;
    calcGrade();
    cout<<"\n";
}
void student::calcGrade(void)
{
    total_mark=Mark1+Mark2+Mark3;
    cout<<"\nGrade\t\t\t: ";
    switch (total_mark/((out_of_mark*3)/10))
    {
        case 0:cout<<"E";
            break;
        case 1:cout<<"E+";
            break;
        case 2:cout<<"D";
            break;
        case 3:cout<<"D+";
            break;
        case 4:cout<<"C";
            break;
        case 5:cout<<"C+";
            break;
        case 6:cout<<"B";
            break;
        case 7:cout<<"B+";
            break;
        case 8:cout<<"A";
            break;
        case 9:cout<<"A+";
            break;
        case 10:cout<<"A+";
            break;
        default:cout<<"A+";
            break;    
    }
}
int main()
{
	int total;
    char firstname[30],secondname[30];
    student *list;
    int number_of_students, rollno;
    cout<<"\nEnter total mark\t\t\t: ";
    cin>>total;
    student::update_total(total); 
    cout<<"\nEnter the total number of students\t: ";
    cin>>number_of_students;
    list=new student[number_of_students];
    for(int i=0; i<number_of_students; i++)
    {
        cout<<"\nRollno\t\t\t: ";
        cin>>rollno;
        cout<<"Enter First Name\t: ";
        cin>>firstname;
        cout<<"Enter Second Name\t: ";
        cin>>secondname;
        strcat(firstname," ");
        strcat(firstname,secondname);
        list[i].input(firstname, rollno);
    }
    for(int i=0; i<number_of_students; i++)
    list[i].display();
    delete[] list;
    return 0;
}
