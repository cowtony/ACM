#include<stdio.h>
#include<string.h>

struct block
{
	int val[4];
};

int row,col,total;
block input[40];
int poss[4][40];
int poss_cnt[4];
int poss_right[40][40];
int poss_right_cnt[40];
int compact_ver[40][40];
int compact_hor[40][40];
int corner[4];
int visit[40];
int has_put[40];

int ch_to_int(char ch)
{
	if(ch=='F')	return 0;
	else if(ch=='I')	return -1;
	else	return 1;
}

int initialize()
{
	memset(poss_cnt,0,sizeof(poss_cnt));
	memset(poss_right_cnt,0,sizeof(poss_right_cnt));
	memset(compact_ver,0,sizeof(compact_ver));
	memset(compact_hor,0,sizeof(compact_hor));
	int i,j,t;
	for(i=0;i<4;i++)	corner[i]=-1;
	for(i=0;i<total;i++)
	{
		if(input[i].val[0]==0&&input[i].val[3]==0)
		{
			if(corner[0]>=0)	return -1;
			corner[0]=i;
		}
		else if(input[i].val[0]==0&&input[i].val[1]==0)
		{
			if(corner[1]>=0)	return -1;
			corner[1]=i;
		}
		else if(input[i].val[1]==0&&input[i].val[2]==0)
		{
			if(corner[2]>=0)	return -1;
			corner[2]=i;
		}
		else if(input[i].val[2]==0&&input[i].val[3]==0)
		{
			if(corner[3]>=0)	return -1;
			corner[3]=i;
		}
	}
	for(i=0;i<4;i++)
		if(corner[i]==-1)	return -1;
	for(t=0;t<4;t++)
		for(i=0;i<total;i++)
			if(input[i].val[t]==0)
				poss[t][poss_cnt[t]++]=i;
	if(poss_cnt[0]!=col||poss_cnt[1]!=row||poss_cnt[2]!=col||poss_cnt[3]!=row)
		return -1;
	for(i=0;i<total;i++)
		for(j=0;j<total;j++)
			if(i!=j)
				if(input[i].val[1]!=0&&input[i].val[1]+input[j].val[3]==0)
					poss_right[i][poss_right_cnt[i]++]=j;
	for(i=0;i<total;i++)
		for(j=0;j<total;j++)
			if(i!=j)
			{
				if(input[i].val[0]+input[j].val[2]==0)
					compact_ver[i][j]=1;
				if(input[i].val[3]+input[j].val[1]==0)
					compact_hor[i][j]=1;
			}
	return 1;
}

int put_block(int lev)
{
	if(lev>=total)	return 1;
	int i;
	
	if(lev<col)
	{
		if(lev==col-1)
		{
			if(compact_hor[corner[1]][has_put[lev-1]])
			{
				has_put[lev]=corner[1];
				return put_block(lev+1);
			}
		}
		else
		{
			for(i=0;i<poss_cnt[0];i++)
			{
				int tt=poss[0][i];
				if(visit[tt]||!compact_hor[tt][has_put[lev-1]])	continue;
				visit[tt]=1;
				has_put[lev]=tt;
				if(put_block(lev+1))	return 1;
				visit[tt]=0;
			}
		}
	}
	else	if(lev>=(row-1)*col)
	{
		if(lev%col==0)
		{
			if(compact_ver[corner[3]][has_put[lev-col]])
			{
				has_put[lev]=corner[3];
				return put_block(lev+1);
			}
		}
		else if((lev+1)%col==0)
		{
			if(compact_hor[corner[2]][has_put[lev-1]]&&compact_ver[corner[3]][has_put[lev-col]])			
				return 1;
		}
		else
		{
			for(i=0;i<poss_cnt[2];i++)
			{
				int tt=poss[2][i];
				if(visit[tt]||!compact_hor[tt][has_put[lev-1]]||!compact_ver[tt][has_put[lev-col]])	continue;
				visit[tt]=1;
				has_put[lev]=tt;
				if(put_block(lev+1))	return 1;
				visit[tt]=0;
			}
		}
	}
	else
	{
		if(lev%col==0)
		{
			for(i=0;i<poss_cnt[3];i++)
			{
				int tt=poss[3][i];
				if(visit[tt]||!compact_ver[tt][has_put[lev-col]])	continue;
				visit[tt]=1;
				has_put[lev]=tt;
				if(put_block(lev+1))	return 1;
				visit[tt]=0;
			}
		}
		else if((lev+1)%col==0)
		{
			for(i=0;i<poss_cnt[1];i++)
			{
				int tt=poss[1][i];
				if(visit[tt]||!compact_ver[tt][has_put[lev-col]]||!compact_hor[tt][has_put[lev-1]])	continue;
				visit[tt]=1;
				has_put[lev]=tt;
				if(put_block(lev+1))	return 1;
				visit[tt]=0;		
			}
		}
		else
		{
			int pt=has_put[lev-1];
			for(i=0;i<poss_right_cnt[pt];i++)
			{
				int tt=poss_right[pt][i];
				if(visit[tt]||!compact_hor[tt][has_put[lev-1]]||!compact_ver[tt][has_put[lev-col]])	continue;
				visit[tt]=1;
				has_put[lev]=tt;
				if(put_block(lev+1))	return 1;
				visit[tt]=0;
			}
		}
	}
	return 0;
}

int main()
{

//	freopen("1264.in","r",stdin);
//	freopen("1264.out","w",stdout);	

	while(scanf("%d %d",&row,&col)!=EOF)
	{
		if(row==0&&col==0)	break;
		total=row*col;
		int i,j;
		char t_str[5];
		for(i=0;i<total;i++)
		{
			scanf("%s",t_str);
			for(j=0;j<4;j++)
				input[i].val[j]=ch_to_int(t_str[j]);			
		}
		if(total==1)
		{
			if(input[0].val[0]==0&&input[0].val[1]==0&&
				input[0].val[2]==0&&input[0].val[3]==0)
				printf("YES\n");
			else	printf("NO\n");
			continue;
		}
		if(initialize()<0)	
		{
			printf("NO\n");continue;
		}
		memset(visit,0,sizeof(visit));
		for(i=0;i<4;i++)	visit[corner[i]]=1;
		has_put[0]=corner[0];
		if(put_block(1))		
			printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
