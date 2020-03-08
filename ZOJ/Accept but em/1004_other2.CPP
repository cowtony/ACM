//126481 2003-04-17 22:07:30 Accepted 1577 C++ 00:00.08 380K just for play 
#include<stdio.h>

int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		if(x>y||y%x!=0)
		{
			printf("0\n");
			continue;
		}
		int cnt=0;
		int tt=y/x;
		int i=2;
		while(tt>1)
		{
			if(tt%i==0)
			{
				do{
					tt/=i;
				}while(tt%i==0);
				cnt++;
			}
			
			i++;
		}
		printf("%d\n",1<<cnt);
	}
	return 0;
}