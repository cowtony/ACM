//116518 2003-04-11 19:42:50 Accepted 1052 C++ 00:00.00 448K just for play 
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

struct node_type
{
	
	int change[26];
	bool out[26];
	void initial()
	{
		int i;
		for(i=0;i<26;i++)
		{
			change[i]=0;out[i]=false;
		}
	
	}
};

node_type table[51];
vector<int>success[51];

int n;

void downflow(int pt,int k)
{
	int i;
	for(i=0;i<success[pt].size();i++)
	{
		int tt=success[pt][i];
		if(table[tt].out[k]==true)	continue;
		if(table[tt].change[k]==-1)	continue;
		table[tt].out[k]=true;
		downflow(tt,k);
	}

}


int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;int t;
	scanf("%d",&nn);
	for(t=0;t<nn;t++)
	{
		int i,j;
		scanf("%d",&n);
		if(t)	printf("\n");
		for(i=1;i<=n;i++)	table[i].initial();
		for(i=1;i<=n;i++)	success[i].clear();
		
		char str[27];
		for(i=1;i<=n;i++)
		{
			scanf("%s",str);
			if(!(strcmp(str,".")==0))
			{
				for(j=0;j<(int)strlen(str);j++)
					table[i].change[str[j]-'A']=1;
			}
			scanf("%s",str);
			if(!(strcmp(str,".")==0))
			{
				for(j=0;j<(int)strlen(str);j++)
					table[i].change[str[j]-'A']=-1;
			}
		}
		int fir,sec;
		while(scanf("%d%d",&fir,&sec))
		{
			if(fir==0&&sec==0)	break;
			success[fir].push_back(sec);
			
		
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<26;j++)
			{
				if(table[i].change[j]==1)
				{
					table[i].out[j]=true;
					downflow(i,j);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf(":");
			for(j=0;j<26;j++)
				if(table[i].out[j]==true)	printf("%c",j+'A');
			printf(":\n");
			
		}
	}
	return 0;
}


		
		
			


