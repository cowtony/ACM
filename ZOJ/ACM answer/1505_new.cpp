//261936 2003-08-17 17:04:39 Memory Limit Exceeded 1505 C++ 00:00.00 33200K just for play 
//261950 2003-08-17 17:10:44 Wrong Answer 1505 C++ 00:00.34 16824K just for play 
//262264 2003-08-17 21:30:13 Accepted 1505 C++ 00:00.42 16824K just for play 
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

char visit[64][64][64][64];


struct STATUS
{
	int board[4][2];
	int lev;
	void output()
	{
		int i,j;
		for(i=0;i<4;i++)
			printf("%d  %d  --  ",board[i][0],board[i][1]);
		printf("--------------\n");
	}
};
STATUS init_state,end_state;
int move[8][2]={{-1,0},{0,-1},{1,0},{0,1},{-2,0},{0,-2},{2,0},{0,2}};

bool check_occupy(STATUS cur_state,int x,int y)
{
	int i;
	for(i=0;i<4;i++)
		if(cur_state.board[i][0]==x&&cur_state.board[i][1]==y)	return true;
	return false;
}
void change_seq(STATUS& cur_state)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;
	for(i=0;i<3;i++)
	{
		int pt=i;
		for(j=i+1;j<4;j++)
			if(a[j]>a[pt])	pt=j;
		if(i!=pt)
		{
			int t=a[i];a[i]=pt;a[pt]=t;
			t=cur_state.board[i][0];cur_state.board[i][0]=cur_state.board[pt][0];
			cur_state.board[pt][0]=t;
			t=cur_state.board[i][1];cur_state.board[i][1]=cur_state.board[pt][1];
			cur_state.board[pt][1]=t;
		}
	}
}

bool has_visit(const STATUS& cur_state,int t)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;	
	if(t==0&&visit[a[0]][a[1]][a[2]][a[3]]==0)	return true;
	if(t==1&&visit[a[0]][a[1]][a[2]][a[3]]==1)	return true;
	return false;
	
}
void set_visit(const STATUS& cur_state,int t)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;	
	if(t==0)	visit[a[0]][a[1]][a[2]][a[3]]=0;
	if(t==1)	visit[a[0]][a[1]][a[2]][a[3]]=1;
	
}

bool board_search()
{
	
	queue<STATUS> seq[2];
	init_state.lev=end_state.lev=0;
	change_seq(init_state);
	change_seq(end_state);
	set_visit(init_state,0);
	set_visit(end_state,1);
	seq[0].push(init_state);	
	seq[1].push(end_state);
	if(has_visit(init_state,1))	return true;
	if(has_visit(end_state,0))	return true;
	
	int i,j,t,k;STATUS cur_state,next_state;
	int nextx,nexty,curx,cury;
	for(i=0;i<4;i++)
	{
		
		for(j=0;j<2;j++)
		{	
			while(!seq[j].empty())
			{
				cur_state=seq[j].front();
				if(cur_state.lev!=i)	break;
		//		printf("%d %d =>",i,j);
		//		cur_state.output();
				seq[j].pop();
				for(t=0;t<4;t++)
				{
					curx=cur_state.board[t][0],cury=cur_state.board[t][1];
					for(k=0;k<4;k++)
					{
						nextx=curx+move[k][0],nexty=cury+move[k][1];
						if(nextx<1||nextx>8||nexty<1||nexty>8)	continue;
						next_state=cur_state;
						if(!check_occupy(cur_state,nextx,nexty))
						{
							next_state.board[t][0]=nextx,next_state.board[t][1]=nexty;
						}
						else
						{
							nextx=curx+move[k+4][0];nexty=cury+move[k+4][1];
							if(nextx<1||nextx>8||nexty<1||nexty>8)	continue;
							if(!check_occupy(cur_state,nextx,nexty))
							{
								next_state.board[t][0]=nextx,next_state.board[t][1]=nexty;
							}
							else continue;
						}
						change_seq(next_state);
						if(has_visit(next_state,j))	continue;						
						if(has_visit(next_state,1-j))	return true;
						set_visit(next_state,j);
						next_state.lev=cur_state.lev+1;
						seq[j].push(next_state);
					}
				}
			}
		}
	}
	return false;
}

								

				
int main()
{
//	freopen("1505.in","r",stdin);
//	freopen("1505.out","w",stdout);
	while(scanf("%d",&init_state.board[0][0])!=EOF)
	{
		memset(visit,0xff,sizeof(visit));		
		scanf("%d",&init_state.board[0][1]);
		int i,j;
		for(i=1;i<4;i++)
		{scanf("%d %d",&init_state.board[i][0],&init_state.board[i][1]);}
		for(i=0;i<4;i++)
		{scanf("%d %d",&end_state.board[i][0],&end_state.board[i][1]);}
		if(board_search())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}



