//183096 2003-06-29 01:07:43 Time Limit Exceeded 1264 C++ 00:01.00 432K just for play 
//183285 2003-06-29 11:17:31 Time Limit Exceeded 1264 C++ 00:01.00 444K just for play 
#include<stdio.h>
#include<string.h>

struct block
{
	int val[4];
};
int row,col;
block input[40];
int poss_block[40][4][40];
int cnt[40][4];
int compat[40][40][4];
bool visit[40];
int has_put[40];
int same[40][40];
int same_cnt[40];
	
int ch_to_int(char ch)
{
	if(ch=='F')	return 0;
	else if(ch=='I')	return -1;
	else	return 1;
}

bool block_same(int fir,int sec)
{
	int i;
	for(i=0;i<4;i++)
		if(input[fir].val[i]!=input[sec].val[i])	return 0;
	return 1;
}
void cal_connect()
{
	memset(cnt,0,sizeof(cnt));
	memset(compat,0,sizeof(compat));	
	memset(same_cnt,0,sizeof(same_cnt));
	int i,j,t;

	for(i=0;i<row*col;i++)
		for(j=i;j<row*col;j++)
			if(block_same(i,j))
			{
				same[i][same_cnt[i]++]=j;
				same[j][same_cnt[j]++]=i;				
			}
	for(i=0;i<4;i++)
	{
		int tt;
		switch(i)
		{
		case 0:	tt=2;break;
		case 1: tt=3;break;
		case 2: tt=0;break;
		case 3: tt=2;break;
		}
				
		for(j=0;j<row*col;j++)
			for(t=0;t<row*col;t++)
			{
				if(j==t)	continue;
				if(input[j].val[i]!=0&&input[j].val[i]+input[t].val[tt]==0)
				{
					compat[j][t][i]=1;					
					poss_block[j][i][cnt[j][i]++]=t;
					
				}
			}
	}
	
}

int cursive_visit(int lev)
{
//	if(lev>0)	printf("%d ---- %d \n",lev,has_put[lev-1]);
	int i,j;
	if(lev==row*col)	return 1;
	int tryed[40];
	memset(tryed,0,sizeof(tryed));
	if(lev<col)
	{
		if(lev==0)
		{
			for(i=0;i<row*col;i++)
			{
				if(tryed[i])	continue;
				if(input[i].val[0]!=0||input[i].val[3]!=0)	continue;				
				for(j=0;j<same_cnt[i];j++)
					tryed[same[i][j]]=1;
				visit[i]=1;
				has_put[lev]=i;
				if(cursive_visit(lev+1))	return 1;
				visit[i]=0;
			}
		}
		else
		{
			int pt=has_put[lev-1];
			for(i=0;i<cnt[pt][1];i++)
			{
				int tt=poss_block[pt][1][i];
				if(tryed[tt])	continue;
				if(visit[tt]||input[tt].val[0]!=0)	continue;
				if((lev+1)%col==0&&input[tt].val[1]!=0)	continue;
				
				for(j=0;j<same_cnt[tt];j++)
					tryed[same[tt][j]]=1;
				
				visit[tt]=1;
				has_put[lev]=tt;
				if(cursive_visit(lev+1))	return 1;
				visit[tt]=0;
			}
		}
	}
	else
	{
		if(lev%col==0)
		{
			int pt=has_put[lev-col];
			for(i=0;i<cnt[pt][2];i++)
			{
				int tt=poss_block[pt][2][i];
				if(visit[tt]||input[tt].val[3]!=0)	continue;
				if(lev>=(row-1)*col&&input[tt].val[2]!=0)	continue;
				if(tryed[tt])	continue;
				for(j=0;j<same_cnt[tt];j++)
					tryed[same[tt][j]]=1;
				
				visit[tt]=1;
				has_put[lev]=tt;
				if(cursive_visit(lev+1))	return 1;
				visit[tt]=0;
			}
		}
		else
		{
			int pt=has_put[lev-col];
			for(i=0;i<cnt[pt][2];i++)
			{
				int tt=poss_block[pt][2][i];
				if(visit[tt])	continue;
				if(tryed[tt])	continue;
				if(!compat[has_put[lev-1]][tt][1])	continue;								
				if((lev+1)%col==0&&input[tt].val[1]!=0)	continue;
				if(lev>=(row-1)*col&&input[tt].val[2]!=0)	continue;				
				for(j=0;j<same_cnt[tt];j++)
					tryed[same[tt][j]]=1;
				
				visit[tt]=1;
				has_put[lev]=tt;
				if(cursive_visit(lev+1))	return 1;
				visit[tt]=0;
			}
		}
	}
	return 0;
}
			

char int_to_ch(int t)
{
	if(t==0)	return 'F';
	if(t==1)	return 'O';
	return 'I';
}


int can_put()
{
	memset(visit,0,sizeof(visit));
	if(cursive_visit(0))	return 1;
	return 0;
}
	
int main()
{

	freopen("1264.in","r",stdin);
//	freopen("1264.out","w",stdout);	

	while(scanf("%d %d",&row,&col)!=EOF)
	{
		if(row==0&&col==0)	break;
		
//		printf("%d %d\n",row,col);
		int i,j,t;
		char t_str[5];
		for(i=0;i<row*col;i++)
		{
			scanf("%s",t_str);
			for(j=0;j<4;j++)
				input[i].val[j]=ch_to_int(t_str[j]);			
		}
/*		
		printf("%d %d=============\n",row,col);
		for(i=0;i<row*col;i++)
		{
			for(j=0;j<4;j++)
				printf("%c",int_to_ch(input[i].val[j]));
			printf("\n");
		}
*/
//		printf("-----------\n");
		cal_connect();
/*
		for(i=0;i<row*col;i++)
		{
			printf("%d ------- \n",i);
			for(j=0;j<4;j++)
			{
				printf(" %d   ",j);
				for(t=0;t<cnt[i][j];t++)
					printf("%d ",poss_block[i][j][t]);
				printf("\n");
			}
		}
*/
		if(can_put())
			printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}


