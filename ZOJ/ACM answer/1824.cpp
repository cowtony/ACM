#include <stdio.h>
#include <string.h>
int main()
{
	char st[60][60];
	int i,t;
	char a[1000];
	int row,col;
	int px,py;
	int der;
	while(1)
	{
		if(scanf("%d%d%*c",&row,&col)==EOF) break;
		der=1;
		for(i=0;i<row;i++)
			gets(st[i]);
		scanf("%d%d%*c",&px,&py);
		px--;
		py--;
		t=1;
		while(t)
		{
			gets(a);
			for(i=0;i<strlen(a);i++)
			{
				if(a[i]=='Q') {t=0;break;}
				if(a[i]=='R')
				{
					der+=1;
					if(der==5) der=1;
				}
				else if(a[i]=='L')
				{
					der-=1;
					if(der==0) der=4;
				}
				else if(a[i]=='F')
				{
					if(der==1)
					{
						if(px>0)
						{
							if(st[px-1][py]==' ') px--;
						}
					}
					else if(der==2)
					{
						if(py<col-1)
						{
							if(st[px][py+1]==' ') py++;
						}
					}
					else if(der==3)
					{
						if(px<row-1)
						{
							if(st[px+1][py]==' ') px++;
						}
					}
					else
					{
						if(py>0)
						{
							if(st[px][py-1]==' ') py--;
						}
					}
				}
			}
		}
		printf("%d %d ",px+1,py+1);
		if(der==1) printf("N\n");
		else if(der==2) printf("E\n");
		else if(der==3) printf("S\n");
		else printf("W\n");
	}
	return 0;
}

						


