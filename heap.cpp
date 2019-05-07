
#include <iostream>
using namespace std;
#define max 10

class student
{
	string name;
	int marks;
	friend class heap;
};

class heap
{
	student heap_array[max];
	int min_max;
	int n;                 
public:
	heap()
	{

	}
	void heap_create();     
	void heap_display();
	void heap_insert(int index);
	void extract_minmax();
};

void heap::heap_display()
{
	cout<<"NAME\t\tMARKS\n";
	for(int i=0;i<n;i++)
	{
		cout<<heap_array[i].name<<"\t\t"<<heap_array[i].marks<<endl;
	}
}

void heap::heap_create()
{
	student s;
	cout<<"Enter total number of students: ";
	cin>>n;
	cout<<"SELECT: 1)MAXIMUM HEAP 2)MINIMUM HEAP?(1/0)";
	cin>>min_max;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the student name: ";
		cin>>s.name;
		cout<<"Enter the marks: ";
		cin>>s.marks;
		cout<<"\n";
		heap_array[i]=s;
		heap_insert(i);
	}
}

void heap::heap_insert(int index)
{
	int i=index; student s=heap_array[index];
	if(min_max==1)
	{
		while(i>1 && s.marks>heap_array[i/2].marks)
		{
			heap_array[i]=heap_array[i/2];
			i=i/2;
		}
	}
	if(min_max==0)
	{
		while(i>1 && s.marks<heap_array[i/2].marks)
		{
			heap_array[i]=heap_array[i/2];
			i=i/2;
		}
	}
	heap_array[i]=s;
}

void heap::extract_minmax()
{
	if(min_max==1)
	{
		cout<<"max Displayed: NAME: "<<heap_array[0].name<<"\n"<<"MARKS: "<<heap_array[1].marks;
	}
	if(min_max==0)
	{
		cout<<"min Displayed: NAME: "<<heap_array[0].name<<"\n"<<"MARKS: "<<heap_array[1].marks;
	}
}

int main()
{
	heap h;
	char ch;
	int op=0;
	cout<<"DETAILS OF STUDENT\n";
	do
	{
		cout<<" HEAP: 1)CREATE HEAP  2)DISPLAY HEAP  3)DISPLAY MAX/MIN\n";
		cout<<"Enter option: ";
		cin>>op;
		switch(op)
		{
			case 1: h.heap_create();
					break;

			case 2: h.heap_display();
					break;

			case 3: h.extract_minmax();
					break;

			default:cout<<"INVALID OPTION!";
		}
		cout<<"\nDo you want to continue?";
		cin>>ch;
	}while(ch=='y' || 'Y');
	return 0;
}
