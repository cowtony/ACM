//100264 2003-03-27 21:44:50 Accepted 1221 C++ 00:00.00 440K Century Ghost 
#include<iostream.h>
#include<string.h>
int flag[21][21];
int value[21][21];

void calvalue()
{
	int i,j,k;
	for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
			if(flag[i][j])	value[i][j]=1;
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++)
			for(k=j+1;k<=20;k++)			
				if(value[j][i]!=-1&&value[k][i]!=-1)				
				{
					if(value[j][k]==-1||value[j][i]+value[k][i]<value[j][k])
					{
						value[j][k]=value[j][i]+value[k][i];
						value[k][j]=value[j][k];
					}
				}
	}

}
				

	
int main()
{
	int n;int count=0;
	while(cin>>n)
	{
		int i,j;int temp;
		count++;
		memset(flag,0,sizeof(flag));
		for(i=1;i<=20;i++)
			for(j=1;j<=20;j++)
				value[i][j]=-1;
		for(i=1;i<=20;i++)	value[i][i]=0;
		
		for(i=0;i<n;i++)
		{	cin>>temp;flag[1][temp]=1;flag[temp][1]=1;}
		for(i=2;i<20;i++)
		{
			cin>>n;
			for(j=0;j<n;j++)
			{	cin>>temp;flag[i][temp]=1;flag[temp][i]=1;}
		}
		calvalue();
		cin>>n;
		cout<<"Test Set #"<<count<<endl;
		int from,to;
		for(i=0;i<n;i++)
		{
			cin>>from>>to;
			cout<<from<<" to "<<to<<": "<<value[from][to]<<endl;
		}
		cout<<endl;
	}
	return 0;
}


	