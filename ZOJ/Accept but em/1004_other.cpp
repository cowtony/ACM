//1022 2003-05-24 14:09:59 Accepted 1004 C++ 00:00:10 456K just for play 
#include<iostream.h>
//#include<stdio.h>
#include<string.h>

int main()
{
//	freopen("1004.in","r",stdin);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int money;
		char tstr[10];
		int tnum;
		int use_m[100],prefer[100];
		cin>>money>>tstr;
		int tn;int k;int n=0;
		int i,j;
		cin>>tn;
		for(i=0;i<tn;i++)
		{
			cin>>tstr>>k;			
			for(j=0;j<k;j++)
			{
				cin>>tnum>>tstr;
				cin>>tnum>>tstr;
				use_m[n++]=tnum;
			}
		}
		tn=0;
		for(i=0;i<n;i++)
			cin>>prefer[tn++];
		int val[5001];		
		memset(val,0,sizeof(val));
		
		for(i=0;i<n;i++)
		{
			
			for(j=money;j>=0;j--)
			{
				if(j-use_m[i]>=0)
				{
					if(val[j]<val[j-use_m[i]]+prefer[i])
						val[j]=val[j-use_m[i]]+prefer[i];
				}
			}
			
		}
		int max=-1;int selpt;
		for(i=0;i<=money;i++)
			if(val[i]>max){selpt=i;max=val[i];}
		cout<<selpt<<" "<<max<<endl;
	}
	return 0;
}

			

