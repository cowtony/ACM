#include <stdio.h>
#include <string.h>
int main()
{
	int cas;
	char s1[102][102];
	char s2[102][102];
	int i,j,k;
	int r,c,n;
	scanf("%d%*c",&cas);
	while(cas--)
	{
		scanf("%d %d %d%*c",&r,&c,&n);
		for(i=1;i<=r;i++)
			gets(s1[i]);
		for(i=r;i>=1;i--)
		{
			for(j=c;j>=1;j--)
			{
				s1[i][j]=s1[i][j-1];
			}
		}
		for(i=0;i<c+2;i++)
		{
			s1[0][i]='0';
			s1[r+1][i]='0';

			s2[0][i]='0';
			s2[r+1][i]='0';
		}
		for(i=0;i<r+2;i++)
		{
			s1[i][0]='0';
			s1[i][c+1]='0';

			s2[i][0]='0';
			s2[i][c+1]='0';
		}
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				for(j=1;j<=r;j++)
				{
					for(k=1;k<=c;k++)
					{
						if(s1[j][k]=='R')
						{
							if(s1[j-1][k]=='P'||s1[j+1][k]=='P'||s1[j][k-1]=='P'||s1[j][k+1]=='P') s2[j][k]='P';
							else s2[j][k]='R';
						}
						else if(s1[j][k]=='P')
						{
							if(s1[j-1][k]=='S'||s1[j+1][k]=='S'||s1[j][k-1]=='S'||s1[j][k+1]=='S') s2[j][k]='S';
							else s2[j][k]='P';
						}
						else 
						{
							if(s1[j-1][k]=='R'||s1[j+1][k]=='R'||s1[j][k-1]=='R'||s1[j][k+1]=='R') s2[j][k]='R';
							else s2[j][k]='S';
						}
					}
				}
			}
			else
			{
				for(j=1;j<=r;j++)
				{
					for(k=1;k<=c;k++)
					{
						if(s2[j][k]=='R')
						{
							if(s2[j-1][k]=='P'||s2[j+1][k]=='P'||s2[j][k-1]=='P'||s2[j][k+1]=='P') s1[j][k]='P';
							else s1[j][k]='R';
						}
						else if(s2[j][k]=='P')
						{
							if(s2[j-1][k]=='S'||s2[j+1][k]=='S'||s2[j][k-1]=='S'||s2[j][k+1]=='S') s1[j][k]='S';
							else s1[j][k]='P';
						}
						else 
						{
							if(s2[j-1][k]=='R'||s2[j+1][k]=='R'||s2[j][k-1]=='R'||s2[j][k+1]=='R') s1[j][k]='R';
							else s1[j][k]='S';
						}
					}
				}
			}
		}
		if(n%2==0)
		{
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					printf("%c",s1[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					printf("%c",s2[i][j]);
				}
				printf("\n");
			}
		}
	if(cas>0)  printf("\n");
	}
	return 0;
}
		