//96369 2003-03-23 22:18:19 Accepted 1212 C++ 00:00.00 440K Century Ghost 
#include<iostream.h>
#include<math.h>
/*
#include<fstream.h>
ifstream cin("in.txt");
ofstream cout("out.txt");
*/
const double conang=3.1415926535897;
double d[100];
double a[100];

int main()
{
	cout<<"Problem 6 by team x"<<endl;
	while(cin>>a[0])
	{
		
		int ang=1;int i;
		int dis=0;char ch;
		while(1)
		{
			cin.get(ch);
			if(ch=='\n')	break;
			if(ang==dis)	cin>>a[ang++];
			else	cin>>d[dis++];
		}
//		for(i=0;i<ang;i++)	cout<<a[i]<<" ";
//		cout<<endl;
//		for(i=0;i<dis;i++)	cout<<d[i]<<" ";
//		cout<<endl;
		double pipe=0;
		double peak[100];
		for(i=0;i<ang;i++)
			a[i]=a[i]*conang/180;
		peak[0]=d[0]*sin(a[0]);
		pipe=d[0]*cos(a[0]);
		for(i=1;i<dis;i++)
		{

			peak[i]=peak[i-1]+d[i]*sin(a[i]);
			pipe+=d[i]*cos(a[i]);
		}
		pipe+=peak[i-1]*(1.0/tan(-a[i]));
		cout<<endl;
		for(i=0;i<dis;i++)
		{	cout.precision(1);			
			cout.setf(ios::fixed|ios::showpoint);
			cout<<"Altitude of peak "<<(i+1)<<" =";
			cout.width(7);
			cout<<peak[i]<<endl;
		}
		cout<<"Pipeline length    =";
		cout.precision(1);
		cout.setf(ios::fixed|ios::showpoint);
		cout.width(7);
		cout<<pipe<<endl;
	}
	cout<<"End of problem 6 by team x"<<endl;
	return 0;
}

		