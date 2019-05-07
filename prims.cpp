#include<iostream>
using namespace std;

class graph
{
 string name[20];
 int ver;
 int edge;
 int cost[20][20];
 public:
        graph()
        {
          int i,j;
          for(i=0;i<20;i++)
          {
            for(j=0;j<20;j++)
              cost[i][j]=999;
          }
        }
        void create_adj_MAT();
        void createN_adj_MAT();
        void disp_adj_MAT();
        void prims();
};

void graph::create_adj_MAT()
{
   int i,j;
   cout<<"Enter no. of Vertices:";
   cin>>ver;
   for(i=0;i<ver;i++)
   {  
     for(j=0;j<ver;j++)
     {
        if(j<=i)
        {     
        cout<<"Enter cost of edge "<<i<<" & "<<j<<" :";
        cin>>cost[i][j];
        cost[j][i]=cost[i][j];
        }
     }
   }   
}

void graph::createN_adj_MAT()
{
   int a,b;    
  int c;
  cout<<"\nEnter the no. of vertices: ";
  cin>>ver;
  cout<<"Enter the no. of edges: ";
  cin>>edge;
  int cnt=0;
  while(cnt<edge)
  {
    cout<<"\nEnter the starting & ending Vertices: ";
    cin>>a>>b;
    cout<<"\nEnter the cost: ";
    cin>>c;
    cost[a][b]=c;
    cost[b][a]=c;
    cnt++;
  }
}


void graph::disp_adj_MAT()
{
   int i,j;
   cout<<endl;
   cout<<"\nEntered matrix is:\n\n";
   for(j=0;j<ver;j++)
        cout<<"   "<<j<<"\t"; 
   cout<<endl;
   for(j=0;j<ver;j++)
        cout<<"_______";
   cout<<endl;
   for(i=0;i<ver;i++)
   {
    cout<<i<<"| ";
     for(j=0;j<ver;j++)
     {
        cout<<cost[i][j]<<"\t";
     }
     cout<<endl;
   }
}

void graph::prims()
{
  int sv,i,j,r,min,k;
  int t[edge][2],nearest[ver];
  int mincost=0;
  cout<<"\nEnter the starting vertex : ";
  cin>>sv;
  nearest[sv]=-1;
  for(i=0;i<ver;i++)
  {
    if(nearest[i]!=sv)
    {
      nearest[i]=sv;
    }
  }
  r=0;
  for(i=0;i<ver;i++)
  {
    min=0;
    for(k=0;k<ver;k++)
    {
      if(nearest[k]!=1 && cost[k][nearest[k]]<min)
      {
        j=k;
        min=cost[k][nearest[k]];
      }
    }
    t[r][0]=j;
    t[r][1]=nearest[j];
    r=r+1;
    mincost=mincost+cost[j][nearest[j]];
    nearest[j]=-1;
    for(k=0;k<ver;k++)
    {
      if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
      {
        nearest[k]=j;
      }
    }
  }
  cout<<"\nSpanning Distance : "<<mincost<<endl;
}


int main()
{
  graph g;
  int ch;
  do
  { 
  cout<<"Enter the choice to perform operations on Graph:\n";
  cout<<"1.Create Adjcency list\n";
  cout<<"2.Display Adjcency list\n";
  cout<<"3.Spanning Distance using Prims Algorithm\n";
  cout<<"4.Exit\n";
  cout<<"\nChoice:";
  cin>>ch;
   switch(ch)
   {
   case 1:g.createN_adj_MAT();
  	  g.disp_adj_MAT();
	  break;
   case 2:g.disp_adj_MAT();
	  break;
   case 3:g.prims();
	  break;
   case 4:break;
   default:"\nInvalid OptionS\n";
  }
 }while(ch!=4);
  return 0;

}
