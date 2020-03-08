//348289 2003-11-13 10:53:28 Wrong Answer 1732 C++ 00:00.05 2832K just for play 
//348299 2003-11-13 11:01:25 Accepted 1732 C++ 00:00.04 2832K just for play 
#include<stdio.h>
#include<string.h>

int val[500001];
bool occur[500001];
int tn;
int n;

bool val_search(int num[],int lev)
{

	int i,j,pt=-1,tt;
	
	if(lev==tn-1)
		return true;
	
	for(i=0;i<n;i++)
	{
		if(occur[i])	continue;
		if(pt!=-1&&val[i]==val[pt])	continue;
		num[lev]=val[i];
		int tcnt=0;tt=0;
		for(j=lev;j>=0;j--)
		{
			tcnt+=num[j];
			bool find=true;
			for(;tt<n;tt++)
			{
				if(val[tt]>tcnt){find=false;	break;}
				if(occur[tt])	continue;
				if(val[tt]==tcnt){occur[tt]=true;break;}
			}
			if(tt==n)	find=false;
			if(!find)	break;
		}
		if(j==-1)
		{
			pt=i;
			if(val_search(num,lev+1))	return true;
		}
		int end=j;tt=0;tcnt=0;
		for(j=lev;j>end;j--)
		{

			tcnt+=num[j];
			for(;tt<n;tt++)
				if(val[tt]==tcnt&&occur[tt]){occur[tt]=false;break;}
		}

	}
	return false;
}
		


int main()
{

	int i,j,t;
/*
	freopen("1732.in","w",stdout);
	printf("%d\n",1000*999/2);
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<1001-i;j++)	printf("%d ",i);
		printf("\n");
	}
	return 0;
*/
//	freopen("1732.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		
		for(i=0;i<n;i++)
			scanf("%d",&val[i]);		
		for(tn=1;;tn++)
			if(tn*(tn-1)==2*n)	break;
		
		memset(occur,false,sizeof(occur));
		int num[1001];
		if(val_search(num,0))
		{
			int res=1;
			for(i=0;i<tn-1;i++)
				res*=num[i];
			printf("%d\n",res);
		}else	printf("No solution\n");
	}
	return 0;
}
