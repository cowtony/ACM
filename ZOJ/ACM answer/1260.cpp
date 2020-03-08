//182301 2003-06-28 11:01:56 Wrong Answer 1260 C++ 00:00.01 420K just for play 
//182323 2003-06-28 11:18:20 Accepted 1260 C++ 00:00.01 420K just for play 
#include<stdio.h>
#include<string.h>

const int infinite=100000000;
int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		scanf("%d",&m);
		int i,j,t;
		int line[101][101];
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)	line[i][j]=infinite;
		for(i=0;i<=n;i++)	line[i][i]=0;
		int beg,cnt,num;char temp[3];
		for(i=0;i<m;i++)
		{
			scanf("%d %d %s %d",&beg,&cnt,temp,&num);
			if(strcmp(temp,"gt")==0)			
				line[beg+cnt][beg-1]=-num-1;
			else line[beg-1][beg+cnt]=num-1;
		}
		
		int val[101];
		for(i=0;i<=n;i++)	val[i]=0;
		bool success=true;
		for(t=0;t<n;t++)
			for(i=0;i<=n;i++)
				for(j=0;j<=n;j++)				
					if(val[i]>val[j]+line[j][i])
							val[i]=val[j]+line[j][i];			
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				if(val[i]>val[j]+line[j][i])
				{success=false;break;}
			if(!success)	break;
		}		
		if(!success)
			printf("successful conspiracy\n");
		else printf("lamentable kingdom\n");
	}
	return 0;
}


