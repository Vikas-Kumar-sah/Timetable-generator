#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<process.h>
#include<fstream>

using namespace std;


void exitf(char name[20])
{if(strcmp(name,"exit") == 0)
	exit(0);
}

class Class
{
public:
int cid;
char cname[20];
static int in_cid;
int c_tt[6][8];
char c;
void init();
};

void Class :: init()
{
cid = in_cid;
in_cid++;

cout<<"Class id : "<<cid;
cout<<"\t Please enter the class name : ";

gets(cname);
exitf(cname);

for(int i=0;i<6;++i)
    for(int j=0;j<8;++j)
    c_tt[i][j] = -2;
}


int Class::in_cid = 0;

class Teacher
{
    char teacher_name[30];
    char subject_name [12];
    int uid;

    static int in_uid;

    int no_of_classes;


public:
    int tid;
    char tname[30];
    char sname[30];
    int maxpd[6];
    int tt[6][8];

    struct tclass
    {
    int cid;
    int ppw;
    //int maxpd;
    }classes[8];

    void noc(); //to input no_of_classes;
    void init(); //to assign teacher_id;

};

int Teacher::in_uid = 0;

void Teacher::noc()
{

    cout<<endl;

    for(int i=0;i<no_of_classes;++i)
    {


	cout<<endl;

	cout<<"Enter details for assigned Class no. " << i+1 <<" : "<<endl;
	cout<<endl;

	cout<<"Enter the class id : " ;
	cin>>classes[i].cid;
	cout<<"Enter the no. of periods per week : ";
	cin>>classes[i].ppw;

	cout<<endl;

    }


    cout<<endl;
}

void Teacher::init()
{   for(int i=0;i<6;i++)
       {
       maxpd[i] = 2;
       for(int j=0;j<8;j++)
		tt[i][j] = -2;
       }
    for(int k=0;k<8;k++)
	classes[k].cid = -1;

    cout<<endl;
    cout<<"Please enter the teacher name : "  ;
    gets(teacher_name);
    exitf(teacher_name);

    cout<<"Enter the subject name : "  ;
    gets(subject_name);
    exitf(subject_name);

    cout<<endl;
    cout<<"Enter the no. of classes assigned to "<<teacher_name<<" : ";
    cin>>no_of_classes;

    uid = in_uid;
    in_uid ++;
    tid = uid;

    strcpy(tname,teacher_name);
    strcpy(sname,subject_name);

    cout<<endl;
}

void dis_cidna(int n,Class a[])
{
for(int i=0;i<n;i++)
{cout<<"Class ID:"<<a[i].cid<<" Class:"<<a[i].cname <<"    ";
 if((i+1)%3 == 0)
 cout<<endl;
}

}

int no_of_teachers,no_of_classes;
int main()
{   void thefn(Teacher teachers[]);
    void disp_tt(Teacher teachers[],Class tclasses[]);
    void ctt(Teacher teachers[],Class tclasses[]);
    void disp_ctt(Teacher teachers[],Class tclasses[]);
    void fwrite(Teacher teachers[],Class tclasses[]);
    void readt();

    system("cls");

    char ch = 'Y';

    while(ch=='Y')
    {   system("cls");
	Teacher teachers[10];
	Class tclasses[40];
	cout<<"Main Menu : "<<"\n\n";
	cout<<"1. Create new timetables "<<endl;
	cout<<"2. View timetables "<<endl;
	cout<<"3. Exit "<<"\n\n";

	int choice;

	cout<<"Enter your choice : ";
	cin>>choice;

	if(choice == 1)
	{   system("cls");
	    cout<<"Enter the no. of classes for which timetable is to be created: ";
	    cin>>no_of_classes;
	    cout<<endl;

	    for(int a=0;a<no_of_classes;++a)
	    {
	    tclasses[a].init();
	    }

	    system("cls");

	    cout<<"Please enter the no. of teachers : " ;
	    cin>>no_of_teachers;
	    cout<<endl;

	    system("cls");

	    for(int i=0;i<no_of_teachers;++i)
	    {

	    cout<<"Please enter details for teacher no. "<<i+1<<" : "<<endl;
	    teachers[i].init();

	    system("cls");
	    dis_cidna(no_of_classes,tclasses);
	    teachers[i].noc();
	    system("cls");
	    }

	    thefn(teachers);
	    cout<<endl;

	    disp_tt(teachers,tclasses);

	    ctt(teachers,tclasses);
	    disp_ctt(teachers,tclasses);
	    fwrite(teachers,tclasses);

	    cout<<"\n\n\n";
	    cout<<"Go back to main menu?(Y/N) ";
	    cin>>ch;
	}
	else if(choice == 2)
	{
	    system("cls");
	    readt();

	    cout<<"\n\n\n";
	    cout<<"Go back to main menu?(Y/N)";
	    cin>>ch;
	}
	else
	    exit(0);
    }


    getch();
    return 0;

}

void thefn(Teacher teachers[])
{


srand(time(NULL));

for(int i=0;i<no_of_teachers;i++)
{

    for(int k=0;k<8;++k)
	{

	if(teachers[i].classes[k].cid != -1)
		{

		int cc_ppw = teachers[i].classes[k].ppw;
		int cc_cid = teachers[i].classes[k].cid;

		while(cc_ppw > 0 )
			{

			int rrow = rand() % 6;
			int rcol = rand() % 8;

			int isavail = 1;
			if(teachers[i].tt[rrow][rcol] != -2)
				isavail = 0;

			if(teachers[i].maxpd[rrow] == 0)
				isavail = 0;

			for(int l=0;l<no_of_teachers;++l)
				if(teachers[l].tt[rrow][rcol] == cc_cid)
				isavail =0;

			if(isavail == 1)
			{teachers[i].tt[rrow][rcol] = cc_cid;
			 cc_ppw -=1;
			 teachers[i].maxpd[rrow] -=1 ;
			 }
			}
		}
	}
}
}

void disp_tt(Teacher teachers[],Class tclasses[])
{
int i=0;
char next = 'y';

	while(next =='y')
	{
	cout<<"Time table for : "<<teachers[i].tname<<endl;

	for(int k=0;k<6;++k)
		{for(int l=0;l<8;++l)
		  {int c_cid = teachers[i].tt[k][l];
		   if(c_cid!= -2)
		   {char c[20];
		   strcpy(c,tclasses[c_cid].cname);
		   cout<<c[0]<<c[1]<<c[2]<<c[3]<<c[4]<<"|";
		   }
		   else
		   cout<<"     |";
		   }

		 cout<<endl;}

	cout<<endl;
	cout<<"______________________________________";
	cout<<endl;
	cout<<"Go to next Teacher's Timetable?(y/n)";
	cin>>next;
	++i;
	}
}

void ctt(Teacher teachers[],Class tclasses[])
{

for(int k=0;k<no_of_classes;++k)
{
    for(int i=0;i<6;++i)
    {
	for(int j=0;j<8;++j)
	{
		for(int l=0;l<no_of_teachers;++l)
		{
		    if(teachers[l].tt[i][j] == tclasses[k].cid)
			{tclasses[k].c_tt[i][j] = teachers[l].tid;
		       //	cout<<i<<" "<<j<<" "<<teachers[l].sname;
			}
		}
	}
    }

}

}

void disp_ctt(Teacher teachers[],Class tclasses[])
{
int i=0;
char next = 'y';

	while(next =='y' && i<no_of_classes)
	{
	cout<<"Time table for : "<<tclasses[i].cname<<endl;
	fstream file(tclasses[i].cname,ios::out);

	for(int k=0;k<6;++k)
		{for(int l=0;l<8;++l)
		  {int c_tid = tclasses[i].c_tt[k][l];
		   if(c_tid != - 2)
		   {char a[20];
		    strcpy(a,teachers[c_tid].sname);
		   cout<<a[0]<<a[1]<<a[2]<<a[3]<<"|";

		   }
		   else
		   {cout<<"    |";

		   }
		  }

		 cout<<endl;}

	cout<<endl;
	cout<<"______________________________________";
	cout<<endl;
	cout<<"Go to next Class' Timetable?(y/n)";
	cin>>next;
	++i;
	}

}

void fwrite(Teacher teachers[],Class tclasses[]){
for(int i=0;i<no_of_classes;++i)
{
	fstream file(tclasses[i].cname,ios::out);

	for(int k=0;k<6;++k)
		{for(int l=0;l<8;++l)
		  {int c_tid = tclasses[i].c_tt[k][l];
		   if(c_tid != - 2)
		   {char a[5];
		    strcpy(a,teachers[c_tid].sname);

		   file<<a[0]<<a[1]<<a[2]<<a[3]<<"|";
		   }
		   else
		   file<<"    |";
	    }
	    file<<endl;
	    }
}           }

void readt()
{
    char name[6];
    char a,b,c,d,e;
    cout<<"Please enter the name of class : ";
    gets(name);
    fstream file(name,ios::in);
    cout<<"Created file"<<endl;

    for(int k=0;k<6;++k)
       {for(int l=0;l<8;++l)
	   { file>>a>>b>>c>>d>>e;
	    cout<<a<<b<<c<<d<<e;
	    }
	cout<<endl;
	}

}
