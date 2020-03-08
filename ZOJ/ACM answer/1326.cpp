//106481 2003-04-04 13:20:02 Accepted 1326 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
/*
#include<fstream.h>
ifstream cin("in.txt");
ofstream cout("out.txt");
*/
int main()
{
	int n;
	int left;
	int card[21];
	int count=0;
	while(cin>>n)
	{
		cin>>left;
		int i;
		for(i=0;i<20;i++)
			cin>>card[i];
		count++;
		int total=n;
		int flag[51];
		for(i=1;i<=n;i++)	flag[i]=0;int pt=0;
		while(1)
		{
		
		

			if(total==left)	break;
			int curcount=0;
//			cout<<card[pt]<<"----"<<endl;
			for(i=1;i<=n;i++)
			{
				if(flag[i])	continue;
				curcount++;
				if(curcount==card[pt]){flag[i]=1;total--;curcount=0;}
				if(total==left)	break;
			}
//			cout<<endl;
			pt++;
			pt%=20;
		}
		cout<<"Selection #"<<count<<endl;
		total=0;
		for(i=1;i<=n;i++)
		{
			if(total==left-1)	break;
			if(!flag[i]){	cout<<i<<" ";total++;}
		}
		for(int j=i;j<=n;j++)
			if(!flag[j]){	cout<<j<<endl;break;}
		cout<<endl;
	}
	return 0;
}

