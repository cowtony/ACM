//278159 2003-08-31 16:41:59 Runtime Error SIGSEGV 1520 C++ 00:00.03 2684K just for play 
//278175 2003-08-31 17:03:27 Accepted 1520 C++ 00:00.01 636K just for play 
#include<stdio.h>
#include<string.h>


int M,L,N;
int val[5001];
int occur[50001];
int cur[5001];
int cnt;
int use[5001];

void output(int num,int& tcnt)
{
	if(use[num]<0){printf("%d ",tcnt);	return;}
	tcnt++;
	output(num-val[use[num]],tcnt);
	printf("%d ",use[num]+1);
}

int main()
{
//	freopen("1520.in","r",stdin);
	while(scanf("%d %d",&M,&L)!=EOF)
	{
		int i,j,tt;
		if(M==0&&L==0)	break;
		scanf("%d",&N);
		for(i=0;i<N;i++)	scanf("%d",&val[i]);
		int total=0;
		for(i=0;i<N;i++)	total+=val[i];
		if(total>M+L)
		{
			printf("Impossible to distribute\n");
			continue;
		}
		if(M==0)
		{
			printf("0\n");
			continue;
		}
		memset(occur,false,sizeof(occur));			
		cnt=1;
		use[0]=-1;
		occur[0]=true;
		cur[0]=0;
		
		for(i=0;i<N;i++)
		{
			int tcnt=cnt;
			for(j=0;j<cnt;j++)
			{
				tt=cur[j]+val[i];
				if(!occur[tt])
				{					
					occur[tt]=true;
					use[tt]=i;
					cur[tcnt++]=tt;
					if(tt<=M&&total-tt<=L)	break;
				}
			}
			if(j<cnt)	break;
			cnt=tcnt;
		}
		if(i==N)		
			printf("Impossible to distribute\n");
		else
		{
			int tcnt=0;
			output(tt,tcnt);
			printf("\n");
		}
	}
	return 0;
}
			
					
