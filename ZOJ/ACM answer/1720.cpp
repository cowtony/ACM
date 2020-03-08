//336407 2003-11-04 13:12:20 Wrong Answer 1720 C++ 00:00.00 376K just for play 
//336419 2003-11-04 13:20:52 Accepted 1720 C++ 00:00.00 376K just for play 
	#include<stdio.h>
	


	int main()
	{
		int n[9];
		while(scanf("%d",&n[8])!=EOF)
		{
			int i;
			for(i=7;i>=0;i--)
				scanf("%d",&n[i]);
			bool first=true;
			for(i=8;i>=0;i--)
			{
				if(n[i]==0)	continue;
				if(first)
				{
					if(n[i]<0)	printf("-");
					
				}
				else 
				{
					if(n[i]<0)	printf(" - ");
					else	printf(" + ");				
				}
					
				int ta=n[i];
				if(ta<0)	ta=-ta;
					
				if(i>=1)
				{
					if(ta!=1)	printf("%d",ta);
					printf("x");
					if(i>1)	printf("^%d",i);
				}
				else	printf("%d",ta);
				first=false;
			}
			if(first)	printf("0");
			printf("\n");
		}
		return 0;
	}

				
