#include <iostream>
#include <cstring>
using namespace std;
class student
{
    private:
    char *Name;
    int Roll_no; 
    int *Mark;
    int no_of_subjects=3;   
    static int total_mark;
    public:
    static void update_total(int a)
    {
		total_mark=a;
	}
    student()
    {
		Mark=new int[no_of_subjects];
	}
    ~student()
	{
		delete Name;
		delete Mark;
		cout<<"Successfully deleted";
	}
    void input(char*, int);
    void display(void);
    void calcGrade(void);
};
int student::total_mark=100;
void student::input(char* name, int roll_no)
{
    Name=new char[strlen(name)+1];
    strcpy(Name,name);
    Roll_no=roll_no;
    for(int i=0;i<no_of_subjects;i++)
    {
        cout<<"\nEnter mark of subject "<<i+1<<" : ";
        cin>>Mark[i];
        if(Mark[i]>total_mark)
        Mark[i]=total_mark;
    }
}
void student::display(void)
{
    cout<<"\n Name : "<<Name<<"\n Roll Number : "<<Roll_no;
    calcGrade();
    cout<<"\n";
}
void student::calcGrade(void)
{
    for(int i=0;i<no_of_subjects;i++)
    {
        cout<<"\n Subject "<<i+1<<" : ";
        switch (Mark[i]/(total_mark/10))
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
        default:
            break;
        }
    }
}
int main()
{
	int total;
    char firstname[30],secondname[30];
    student *list;
    int number, rollno;
    cout<<"\nEnter total mark : ";
    cin>>total;
    student::update_total(total); 
    cout<<"\nEnter the total number of students : ";
    cin>>number;
    list=new student[number];
    for(int i=0; i<number; i++)
    {
        cout<<"\nRollno : ";
        cin>>rollno;
        cout<<"\nEnter First Name : ";
        cin>>firstname;
        cout<<"Enter Second Name : ";
        cin>>secondname;
        strcat(firstname," ");
        strcat(firstname,secondname);
        list[i].input(firstname, rollno);
    }
    for(int i=0; i<number; i++)
    list[i].display();
    delete[] list;
    return 0;
}
