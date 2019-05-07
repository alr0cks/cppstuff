#include<iostream>       
using namespace std;

class gnode           
{
	int vertex;
	string user;
	gnode *next;
	friend class graph;    
};

class graph
{
private: 					
	gnode *head[20];
public:						
	int n;
	graph()
	{
		n=0;
		cout<<" Enter number of friends in the group: ";
		cin>>n;
		for (int i=0;i<n;i++)
		{
			head[i]=new gnode;
			head[i]->vertex=i;
			cout<<"\n Name of user is: ";
			cin>>head[i]->user;
		}
	}
void create();                  			
void display();								
void DFS_R();								
void DFS_R(int v,int a[]);			
void DFS_NR(int v);							
void BFS_NR(int v);							
};

void graph::display()                     
{
	cout<<"\n The users are: \n";
	for(int i=0;i<n;i++)
	{
		cout<<" \t "<<head[i]->vertex<<" \t "<<head[i]->user<<"\n";
	}
}
void graph :: create()        
{
gnode *temp;
int choice;
int v;
display();
for(int i=0;i<n;i++)
{
	cout<<" Enter friends of user \t \t: "<<head[i]->vertex<<"\n";
	temp=head[i];
	do
	{
		cout<<" Enter ID of friend:";
		cin>>v;
		if(v==i)
		{
			cout<<"Cannot be friends with your own account \n";
		}
		else
		{
		gnode *curr;
		curr = new gnode;
		curr->vertex=v;
		curr->user=head[v]->user;
		temp->next=curr;
		temp=temp->next;
		}
		cout<<"Do you want to add more friends of user 1. YES 0. NO";
		cin>>choice;
	}while(choice==1);
}
}

void graph :: DFS_R()       
{
	int a[20];
	int v;
	for(int i=0;i<n;i++)
	{
		a[i]=0;
	}
	cout<<" Enter starting User ID ";
	cin>>v;
	DFS_R(v,a);
}							


void graph :: DFS_R(int v,int a[])			
{
	gnode *temp;
	temp=head[v]->next;
	cout<<head[v]->vertex<<"\t"<<head[v]->user<<"\n";
	a[v]=1;
	if(a[temp->vertex]==0)
	{
		DFS_R(temp->vertex,a);
	}
	else
	{
		temp=temp->next;
		if(temp!=NULL && a[temp->vertex]==0)
		{
			DFS_R(temp->vertex,a);
		}
	}
} 													

class queue											
{
	int front,rear;
	int data[30];
public:
	queue();
	void insert(int);
	int remove();
	int empty();
	friend class graph;                     
};


queue::queue()					
{
	front=rear=-1;
}								


void queue::insert(int temp)					
{
	rear++;
	data[rear]=temp;
}												

int queue::remove()						
{
	if(empty()==0)
	{
	front++;
	return(data[front]);
	}
	else
		return 0;
}											

int queue::empty()						
{
	if(front == rear )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}								


class stack									
{
	int top;
	int data[30];
public : stack()
{
	top=-1;
}
void pushh(int temp);
int popp();
int emptyy();
friend class graph;
}S;

void stack :: pushh(int temp)					
{
	top = top+1;
	data[top]=temp;
}				

int stack::emptyy()								
{
	if (top==-1)
	{
		return 1;
	}
	else
		return 0;
}					

int stack::popp()							
{

	int temp;
	if(emptyy()!=1)
	{
		temp=data[top];
		top=top-1;
	}
	return temp;
}					

void graph :: DFS_NR(int v)						
{
	stack S;
	int a[20];
	for(int i=0;i<n;i++)
		{
			a[i]=0;
		}
	S.pushh(v);
	a[v]=1;
	do
	{
		v=S.popp();
		gnode * temp=head[v]->next;
		cout<<head[v]->vertex<<"\t"<<head[v]->user<<"\n";
		while(temp!=NULL)
		{
			if(a[temp->vertex]==0)
			{
				S.pushh(temp->vertex);
				a[temp->vertex]=1;
			}
			temp=temp->next;
		}
	}while(S.emptyy()==0);
	cout<<endl;
}												

void graph :: BFS_NR(int v)							
{
	queue Q;
	int a[20];
	for(int i=0;i<n;i++)
		{
			a[i]=0;
		}
	Q.insert(v);
	a[v]=1;
	while(Q.empty()==0)
	{
		v=Q.remove();
		cout<<head[v]->vertex<<"\t"<<head[v]->user<<"\n";
		a[v]=1;
		gnode *temp=head[v]->next;
		while(temp!=NULL)
		{
			if(a[temp->vertex]==0)
			{
				Q.insert(temp->vertex);
				a[temp->vertex]=1;
			}
			temp=temp->next;
		}
	}
	cout<<endl;
}									

int main()						
{
	graph G;                   
	int choice;
	int y;
	int v;
	cout<<" \n GRAPH CREATION \n ";
	G.create();
	do
	{
	cout<<" What do you wish to perform \n 1. Recursive DFS \n 2. Non-Recursive DFS \n 3. Non-recursive BFS \n:";
	cin>>choice;
	switch(choice)
	{
	case 1: G.DFS_R();
			break;
	case 2:
			{
				cout<<" Enter starting User ID:";
				cin>>v;
				G.DFS_NR(v);
				break;
			}
	case 3:{
				cout<<" Enter starting User ID:";
				cin>>v;
				G.BFS_NR(v);
				break;
			}
	default : cout<<"INVALID CHOICE!!";
	}
	cout<<"Would you like to continue? 1. YES 0. NO";
	cin>>y;
	}while(y==1);
return 0;
}
