//346123 2003-11-11 19:41:04 Accepted 1703 C++ 00:00.16 4284K just for play 

#include<stdio.h>
#include<string.h>

int occur[1000000];

char board[4][5];
char org_board[4][5];

int get_num()
{
	int i,j;
	int t=1;
	int res=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(org_board[i][j]!='.')	continue;
			if(board[i][j]=='.');
			else if(board[i][j]=='x')	res=res+t;
			else	res=res+t*2;
			t*=3;
		}
	return res;
}


bool finish(char ch)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(board[i][j]!=ch)	break;
		if(j==4)	return true;
		for(j=0;j<4;j++)
			if(board[j][i]!=ch)	break;
		if(j==4)	return true;
	}
	for(i=0;i<4;i++)
		if(board[i][i]!=ch)	break;
	if(i==4)	return true;
	for(i=0;i<4;i++)
		if(board[i][3-i]!=ch)	break;
	if(i==4)	return true;
	return false;
}
		

bool board_search(int x,int y ,int lev)
{
	
	int i,j;
	bool has_put=false;
	bool tres;
/*
	for(i=0;i<lev;i++)	printf("   ");
	printf("%d %d\n",x,y);
*/
	if(lev%2==0)	board[x][y]='x';
	else	board[x][y]='o';
	int tnum=get_num();
	
	if(occur[tnum]!=0)
	{
		if(occur[tnum]==-1)	{tres=false;goto respos;}
		else{tres=true;goto respos;}
	}
	if(lev%2==0&&finish('x')){tres=true;goto respos;}
	else if(lev%2==1&&finish('o')){tres=false;goto respos;}
	
	if(lev%2==0)	tres=true;
	else	tres=false;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(board[i][j]=='.')
			{
				has_put=true;
				if(lev%2==0)
				{
					if(!board_search(i,j,lev+1)){	tres=false;goto respos;}
				}
				else{
					if(board_search(i,j,lev+1)){tres=true;goto respos;}
				}
			}
		}
	if(!has_put)	tres=false;
respos:
/*
	for(i=0;i<lev;i++)	printf("   ");
	if(tres)	printf("true\n");
	else	printf("false\n");
*/
	if(tres)	occur[tnum]=1;
	else	occur[tnum]=-1;
	board[x][y]='.';
	return tres;
}
			

		


			
	

int main()
{
//	freopen("1703.in","r",stdin);
//	freopen("1703.out","w",stdout);
	char head[2];
	
	while(scanf("%s",head)!=EOF)
	{
		if(head[0]!='?')	break;
		
		memset(occur,0,sizeof(occur));	
		int i,j;
		for(i=0;i<4;i++)
			scanf("%s",board[i]);
		for(i=0;i<4;i++)
			strcpy(org_board[i],board[i]);
		
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(board[i][j]=='.')
				{
					if(board_search(i,j,0))
						break;
				}
			}
			if(j<4)	break;
		}
		if(i<4)
			printf("(%d,%d)\n",i,j);
		else	printf("#####\n");
	}
	return 0;
}