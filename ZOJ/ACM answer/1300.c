#include <stdio.h>
#include <string.h>
int main()
{
	int a[33][33];
	char b[1000];
	int cas;
	int x,y,p,t;
	int i,j,k,l=1;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d%*c",&x,&y);
		gets(b);
		for(i=1;i<33;i++)
		{
			for(j=1;j<33;j++)
			{
				a[i][j]=0;
			}
		}
		k=1;
		for(i=0;i<strlen(b)-1;i++)
		{
			if(b[i]=='E') {a[x+1][y]=1;a[x+1][y+1]=2;x++;}
			else if(b[i]=='N') {a[x+1][y+1]=1;a[x][y+1]=2;y++;}
			else if(b[i]=='W') {a[x][y+1]=1;a[x][y]=2;x--;}
			else {a[x][y]=1;a[x+1][y]=2;y--;}
		}
		p=0;
		for(i=1;i<33&&p==0;i++)
		{
			for(j=1;j<33;j++)
			{
				if(a[i][j]!=0) {p=1;t=a[i][j];break;}
			}
		}
		printf("Bitmap #%d\n",l++);		
		for(i=32;i>0;i--)
		{
			for(j=1;j<33;j++)
			{
				if(a[j][i]!=t) printf(".");
				else printf("X");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

		