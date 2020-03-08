//89753 2003-03-16 11:07:26 Accepted 1501 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
#include<string.h>

int twopower[9]={1,2,4,8,16,32,64,128,256};
int input[129];
int high[129],low[129];
int main()
{	
	int n;int flag=0;
	while(cin>>n)
	{
		if(n==0)	break;
		if(flag)	cout<<endl;
		flag=1;
		int total=0;int i;
		for(i=0;i<n;i++)
			total+=twopower[i];
		for(i=0;i<total;i++)	cin>>input[i];
		memset(high,0,sizeof(high));
		memset(low,0,sizeof(low));
		high[input[total-1]]=1;low[input[total-1]]=1;
		for(i=total-2;i>=0;i--)
		{	int pt;
			if(high[input[i]]==0)
			{
				if(i%2==0)	pt=i+1;
				else	pt=i-1;
				high[input[i]]=high[input[pt]]+1;
			}
		}
		for(i=1;i<=twopower[n];i++)
		{
			int pt;
			if(high[i]==0)
			{
				if(i%2==0)	pt=i-1;
				else	pt=i+1;
				high[i]=high[pt]+1;
			}
		}
		int lev[128];int temp_total=0;int j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<twopower[n-1-i];j++)
				lev[temp_total+j]=n-1-i;
			temp_total+=twopower[n-1-i];
		}
		for(i=total-2;i>=0;i--)		
			if(!low[input[i]])	low[input[i]]=twopower[n]-twopower[n-lev[i]]+1;
		for(i=1;i<=twopower[n];i++)	
			if(!low[i])	low[i]=twopower[n];
		int tt;
		cin>>tt;int person;
		for(i=0;i<tt;i++)
		{
			cin>>person;
			cout<<"Player "<<person<<" can be ranked as high as "<<
				high[person]<<" or as low as "<<low[person]<<"."<<endl;
		}
	
	}
	return 0;
}
				


