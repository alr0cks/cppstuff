/*assignment 4(a)
hamming code
name-Shivani barsainya
div-06
roll no:203667
*/


#include<iostream>

using namespace std;
int main()
{
int a[10],b[10];
int i,index,p1,p2,p4;
cout<<"PLEASE ENTER DATA:";                 //accepting data elements from user
cin>>a[2]>>a[4]>>a[5]>>a[6];

a[0]=a[2]^a[4]^a[6];                         //even parity bits 
a[1]=a[2]^a[5]^a[6];
a[3]=a[4]^a[5]^a[6];

cout<<"\nTRANSMITTED DATA:\n";                //enter tranmitted data
for(i=0;i<7;i++)
{
cout<<a[i]<<"\t";

}
cout<<endl;


cout<<"PLEASE ENTER RECEIVED DATA:\n";        //enter received data
for(i=0;i<7;i++)
{
cin>>b[i];
}


p1=b[0]^b[2]^b[4]^b[6];
p2=b[1]^b[2]^b[5]^b[6];
p4=b[3]^b[4]^b[5]^b[6];

index=p1+2*p2+4*p4;

if(index==0)
{
cout<<"\n NO ERROR WHILE TRANMISSION OF DATA\n";       //when received and transmitted data is same
}
else
{
	if(b[index-1]==0)
 	{
 		b[index-1]=1;
 	}
 	else
 		b[index-1]=0;
 	cout<<"\nINDEX POSITION OF CORRUPTED BIT:"<<index;       //position of the corrupted bit
	cout<<"\nCORRECTED RECEIVED DATA:\n";                    //corrected received data when bit is corrupted
	for(i=0;i<7;i++)
	{
		cout<<b[i]<<"\t";
	}
cout<<endl;
}

return 0;
}
/*
output
student@student:~$ ./a.out
PLEASE ENTER DATA:1
1
1
0

TRANSMITTED DATA:
0	0	1	0	1	1	0	
PLEASE ENTER RECEIVED DATA:
0
0
1
0
1
1
0

 NO ERROR WHILE TRANMISSION OF DATA
student@student:~$ ./a.out
PLEASE ENTER DATA:1
0
1
1

TRANSMITTED DATA:
0	1	1	0	0	1	1	
PLEASE ENTER RECEIVED DATA:
0
1
0
0
0
1
1

INDEX POSITION OF CORRUPTED BIT:3
CORRECTED RECEIVED DATA:
0	1	1	0	0	1	1	
*/
