//1212 2003-06-07 15:34:48 Wrong Answer 1006 C++ 00:00:03 380K just for play 
//1263 2003-06-07 15:43:15 Wrong Answer 1006 C++ 00:00:02 380K just for play 
#include<stdio.h>
#include<string.h>

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int father[16];
		memset(father,0xff,sizeof(father));
		int i,t;
		for(i=0;i<m;i++)
		{
			int min,max;
			scanf("%d %d",&min,&max);
			if(min>max){t=min;min=max;max=t;}
			int mint=min,maxt=max;			
			while(mint!=-1)
			{
				maxt=max;				
				while(maxt!=-1&&maxt!=mint)				
					maxt=father[maxt];				
				if(maxt==mint)
				{
					father[max]=min;
					if(mint!=min)	father[min]=mint;
					break;
				}				
				mint=father[mint];
				
			}
			if(mint==-1)
			{
				father[max]=min;
				father[min]=-1;
			}
		}

//		for(i=1;i<=n;i++)
//			printf("%d  --  %d\n",i,father[i]);
		for(i=2;i<=n;i++)
			if(father[i]!=i-1)	break;
		if(i<=n)	printf("NO\n");
		else	printf("YES\n");
	}
	return 0;
}



