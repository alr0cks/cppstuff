#include<iostream>
using namespace std;
#define MAX 10

class Student
{
	int rollno;
	string name;
	char grade;
	public:
	friend class Hashing;
	Student()
	{
		rollno=-1;
		name="---";
		grade='-';
	}
};

class Hashing
{
	Student hashtable[MAX];
	public:
	void linear_without();
	void display();
};

void Hashing::linear_without()
{
	int rn;
	string name;
	char grade;
	char ch;
	int loc;
	
	do
	{
		cout<<"Enter the details of the Student: "<<endl;
		cout<<"Rollno: "<<endl;;
		cin>>rn;
		cout<<"name: "<<endl;
		cin>>name;
		cout<<"Grade: "<<endl;
		cin>>grade;
	
		loc=rn%MAX;	
		if(hashtable[loc].rollno==-1)
		{
			hashtable[loc].rollno=rn;
			hashtable[loc].name=name;
			hashtable[loc].grade=grade;	
		
		}
		
		else
		{
			int flag=0;
			int i=1;
			i=(loc+1)%MAX;
			while(i!=loc)
			{
				if(hashtable[i].rollno==-1)
				{
	                                                                                                                                                                         				hashtable[i].rollno=rn;
					hashtable[i].name=name;
					hashtable[i].grade=grade;	
					flag=1;	
					break;
					
		
				}
				
				else
				{
					i=(i+1)%MAX;
				}	
			
			}
			
			if(flag==0)
			{
				cout<<"Hash Table is full"<<endl;
			}
		
		}
	
	
	

		cout<<"Do you wish to continue(y/n) ";
		cin>>ch;
	}while(ch=='y');



 }



void Hashing::display()
{
	int i;
	cout<<"Hash Table"<<endl;
	cout<<"\tRollno\t\tName\t\tGrade"<<endl;
	for(i=0;i<MAX;i++)
	{
		cout<<i<<"\t"<<hashtable[i].rollno<<"\t\t"<<hashtable[i].name<<"\t\t"<<hashtable[i].grade<<"\t\t"<<endl;
	}

}

int main()
{
	Hashing s;
	s.display();
	s.linear_without();
	s.display();
return 0;
}
