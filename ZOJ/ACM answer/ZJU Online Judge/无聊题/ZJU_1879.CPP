#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool app[3001];
int n;
int curt , prev;

int main()
{	
	int i;
	bool flag;
	while(scanf("%d" , &n) > 0 && n)
	{
		scanf("%d" , &prev);
		memset(app , 0 , sizeof(app));
		flag = 1;
		for(i=1; i<n; i++)
		{
			scanf("%d" , &curt);
			if(curt == prev || abs(curt - prev) >= n || app[abs(curt - prev)])
			{
				flag = 0;
			}
			app[abs(prev - curt)] = 1;
			prev = curt;
		}
		if(flag) puts("Jolly");
		else puts("Not jolly");		
	}	
	
	return 0;
}
