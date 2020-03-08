//343873 2003-11-09 21:40:22 Accepted 1702 C++ 00:00.00 396K just for play 
#include<stdio.h>
#include<string.h>

char inp[25][100];
int main()
{
//	freopen("1702.in","r",stdin);
//	freopen("1702.out","w",stdout);
	int cnt=0;
	int i,j,t;
	char	pos[100];
	gets(pos);
	while(1)
	{		
		if(strcmp(pos,"*")==0)	break;
		cnt=0;
		while(gets(inp[cnt]))
		{
			cnt++;
			if(inp[cnt-1][0]=='<'||inp[cnt-1][0]=='='||inp[cnt-1][0]=='>'||inp[cnt-1][0]=='*')	break;
		}
		cnt--;
		int wcnt=strlen(pos);
		int width[100];
		memset(width,0,sizeof(width));
		int tcnt[25][100];
		memset(tcnt,0,sizeof(tcnt));
		for(i=0;i<cnt;i++)
		{
			int len=strlen(inp[i]);
			int pt=0;
			for(j=0;j<len;j++)
			{
				if(inp[i][j]=='&')
				{
					if(tcnt[i][pt]>width[pt])	width[pt]=tcnt[i][pt];
					pt++;
				}
				else	tcnt[i][pt]++;
			}			
			if(tcnt[i][pt]>width[pt])	width[pt]=tcnt[i][pt];
		}
		printf("@");
		for(i=0;i<wcnt;i++)
		{
			if(i!=0)	printf("-");
			for(j=0;j<width[i]+2;j++)
				printf("-");
		}
		printf("@\n");
		for(i=0;i<cnt;i++)
		{
			
			printf("|");			
			int begs,ends;
			int pt=0;
			for(j=0;j<wcnt;j++)
			{
				printf(" ");	
				if(pos[j]=='<')
				{
					begs=0;ends=width[j]-tcnt[i][j];
				}else	if(pos[j]=='='){				
					begs=(width[j]-tcnt[i][j])/2;
					ends=(width[j]-tcnt[i][j]+1)/2;
				}else{
					begs=width[j]-tcnt[i][j];
					ends=0;
				}
				for(t=0;t<begs;t++)
					printf(" ");
				while(pt<strlen(inp[i])&&inp[i][pt]!='&')
					printf("%c",inp[i][pt++]);
				pt++;
				for(t=0;t<ends+1;t++)
					printf(" ");
				printf("|");

			}
			printf("\n");
			if(i==0)
			{	printf("|");			
				for(j=0;j<wcnt;j++)
				{
					if(j!=0)	printf("+");
					for(t=0;t<width[j]+2;t++)
						printf("-");
				}
				printf("|");
				printf("\n");
			}
		}
		printf("@");
		for(i=0;i<wcnt;i++)
		{
			if(i!=0)	printf("-");
			for(j=0;j<width[i]+2;j++)
				printf("-");
		}
		printf("@\n");
		
		strcpy(pos,inp[cnt]);
	}
	return 0;
}



			
		


