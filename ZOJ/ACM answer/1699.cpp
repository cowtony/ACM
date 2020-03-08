//324413 2003-10-24 19:33:09 Time Limit Exceeded 1699 C++ 00:01.00 384K just for  play
//324416 2003-10-24 19:38:29 Accepted 1699 C++ 00:00.00 380K just for play 

#include<stdio.h>
#include<string.h>

int main()
{
//	freopen("1699.in","r",stdin);
	int n,b,d,i;
	char board[100];
	char move[4];
	int pos[4];
	while(scanf("%d %d %d",&n,&b,&d)!=EOF)
	{
		if(n==0)	break;
		scanf("%s",board);
		int winner=-1;
		int st=0;
		int pt=0;
		int len=strlen(board);
		
		
		for(i=0;i<n;i++)	pos[i]=-1;
		while(d--)
		{
			scanf("%s",move);
			if(winner>=0)	continue;
			int cur=pt%n;
			pt++;
			if(strlen(move)==2)
			{
				int cnt=0;
				for(i=pos[cur]+1;i<len;i++)
				{
					if(board[i]==move[0])	cnt++;
					if(cnt==2)	break;
				}
				if(i>=len-1)	{winner=cur;st=pt;}
				else	pos[cur]=i;
			}
			else
			{
				for(i=pos[cur]+1;i<len;i++)
				{if(board[i]==move[0])	break;}
				if(i>=len-1){winner=cur;st=pt;}
				else	pos[cur]=i;
			}
		}
		if(winner>=0)
		{
			printf("Player %d won after %d cards.\n",winner+1,st);
		}
		else	printf("No player won after %d cards.\n",pt);
	}
	return 0;
}

				




