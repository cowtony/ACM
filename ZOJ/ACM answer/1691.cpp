//404698 2003-12-17 01:02:13 Accepted 1691 C++ 00:01.64 384K just for play 
#include<stdio.h>
#include<string.h>

int score[4][4];
char name[4][4];int to_decide;
int	pos[4]={6,11,16,21};
int rank[4];

void get_name(char str[])
{
	int i,j;
	for(j=0;j<4;j++)
	{
		for(i=pos[j];i<pos[j]+3;i++)	name[j][i-pos[j]]=str[i];
		if(str[pos[j]-1]=='*')		to_decide=j;
		name[j][3]='\0';
	}

}

double cal_tt(int tn)
{
	if(tn==0)	return 1;
	double t=1;
	int i;
	for(i=1;i<=tn;i++)	t*=(double)i;
	return t;
}

double cal_p(int cur)
{
	if(cur>8)	return 0;
	double res=cal_tt(8)*1.0/(cal_tt(cur)*cal_tt(8-cur));
	int i;
	for(i=1;i<=cur;i++)
		res*=0.25;
	for(i=1;i<=8-cur;i++)
		res*=0.75;
	return res;
}

void cal_cur_rank(int pt[],int rcnt,int retr[])
{

	int i,j;
	int point[4],diff[4],goal[4];
	memset(point,0,sizeof(point));
	memset(diff,0,sizeof(diff));
	memset(goal,0,sizeof(goal));
	for(i=0;i<rcnt;i++)
		for(j=0;j<rcnt;j++)
		{
			if(i==j)	continue;
			if(score[pt[i]][pt[j]]>score[pt[j]][pt[i]])	point[i]+=3;
			else	if(score[pt[i]][pt[j]]<score[pt[j]][pt[i]]);
			else	point[i]+=1;
			diff[i]+=score[pt[i]][pt[j]]-score[pt[j]][pt[i]];
			goal[i]+=score[pt[i]][pt[j]];
		}

	int p[4];
	for(i=0;i<rcnt;i++)	p[i]=i;
	for(i=0;i<rcnt;i++)
	{
		int sel=i;
		for(j=i+1;j<rcnt;j++)
		{
			if(point[p[j]]>point[p[sel]]||
				(point[p[j]]==point[p[sel]]&&diff[p[j]]>diff[p[sel]])||
				(point[p[j]]==point[p[sel]]&&diff[p[j]]==diff[p[sel]]&&goal[p[j]]>goal[p[sel]])
				)
					sel=j;
		}
		if(sel!=i){int tt=p[i];p[i]=p[sel];p[sel]=tt;}
	}

	int beg=-1;
	for(i=0;i<=rcnt;i++)
	{
		if(beg==-1)
		{
			beg=i;
		}
		else	
		{
			if(i<rcnt&&point[p[i]]==point[p[beg]]&&diff[p[i]]==diff[p[beg]]&&goal[p[i]]==goal[p[beg]]);
			else
			{
				if(beg==i-1)
				{
					retr[p[i-1]]=i;
					
				}
				else
				{
					int to_rank[4],tocnt=i-beg;
					for(j=0;j<tocnt;j++)	to_rank[j]=pt[p[beg+j]];
					int retrank[4];
					if(tocnt<rcnt)
						cal_cur_rank(to_rank,tocnt,retrank);
					else
						for(j=0;j<rcnt;j++)	retrank[j]=1;
					for(j=0;j<tocnt;j++)						
							retr[p[beg+j]]=beg+retrank[j];

				}
				beg=i;
			}
		}
	}

}
				
	

	
void cal_rank()
{
	int i;
	for(i=0;i<4;i++)	rank[i]=-1;
	int	to_rank[4],rcnt=4;
	for(i=0;i<4;i++)	to_rank[i]=i;
//	int rank[4];
	cal_cur_rank(to_rank,rcnt,rank);
		
}

int get_seq(char tname[])
{
	int i;
	for(i=0;i<4;i++)	
		if(strcmp(tname,name[i])==0)	return i;
	
		return -1;
}

int main()
{
//	freopen("1691.in","r",stdin);
//	freopen("1691.out","w",stdout);
	int n,i,j,t,k;
	scanf("%d",&n);
	while(n--)
	{
		char str[50],tname[4];		
		scanf("%s",str);
		get_name(str);
		for(i=0;i<4;i++)
		{			
			scanf("%s",str);
			for(j=1;j<4;j++)	tname[j-1]=str[j];
			tname[3]='\0';
			int pt=get_seq(tname);
			for(j=0;j<4;j++)
			{
				if(str[pos[j]+1]=='_')	continue;
				if(str[pos[j]]=='_')					
					score[pt][j]=score[j][pt]=-1;
				else
				{
					score[pt][j]=str[pos[j]]-'0';
					score[j][pt]=str[pos[j]+2]-'0';
				}
				
			}
		}
		int* chan[4];int pt=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(i==j||score[i][j]>=0)	continue;
				chan[pt]=&score[i][j];
				pt++;
			}
		double sp=0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				for(t=0;t<9;t++)
					for(k=0;k<9;k++)
					{
						
						*chan[0]=i;*chan[1]=j;*chan[2]=t;*chan[3]=k;
						int ii,jj;
						cal_rank();
						if(rank[to_decide]==1||rank[to_decide]==2)
						{
							double	tp=cal_p(i)*cal_p(j)*cal_p(t)*cal_p(k);
							int ii,tcnt=0;
							for(ii=0;ii<4;ii++)
								if(rank[ii]==rank[to_decide])	tcnt++;
							double t_sp;
							if(tcnt==1||rank[to_decide]==2)
								t_sp=1.0/tcnt;
							else	t_sp=2.0/tcnt;

							sp+=tp*t_sp;
						}
					}

		printf("%.7lf\n",sp);
	}
	return 0;
}
