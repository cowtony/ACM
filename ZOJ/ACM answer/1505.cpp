//260923 2003-08-16 23:35:22 Wrong Answer 1505 C++ 00:00.05 16868K just for play 
//260951 2003-08-17 00:06:13 Time Limit Exceeded 1505 C++ 00:10.00 28608K just for play 

/*

  just search -> TLE

*/


#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

bool visit[64][64][64][64];
bool cur_visit[64][64][64][64];

struct STATUS
{
	int board[4][2];
	int lev;
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
void change_seq(STATUS cur_state)
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

bool has_visit(const STATUS& cur_state)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;	
	return visit[a[0]][a[1]][a[2]][a[3]];
}
void set_visit(const STATUS& cur_state)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;	
	visit[a[0]][a[1]][a[2]][a[3]]=true;
}
void reset_visit(const STATUS& cur_state)
{
	int a[4],i,j;
	for(i=0;i<4;i++)
		a[i]=8*(cur_state.board[i][0]-1)+cur_state.board[i][1]-1;	
	visit[a[0]][a[1]][a[2]][a[3]]=false;
}

bool board_search()
{
	if(has_visit(end_state))	return true;
	queue<STATUS> seq;
	
	seq.push(init_state);	
	while(!seq.empty())
	{
		STATUS cur_state=seq.front();
		int i,j;
/*
		for(i=0;i<4;i++)
			printf("%d %d  --   ",cur_state.board[i][0],cur_state.board[i][1]);
		printf("\n");
*/
		seq.pop();		
		
		for(i=0;i<4;i++)
		{
			int curx=cur_state.board[i][0];int cury=cur_state.board[i][1];
			STATUS next_state;
			for(j=0;j<4;j++)
			{
				int nextx=curx+move[j][0],nexty=cury+move[j][1];
				if(nextx<1||nextx>8||nexty<1||nexty>8)	continue;
				next_state=cur_state;
				if(!check_occupy(next_state,nextx,nexty))
				{
					next_state.board[i][0]=nextx,next_state.board[i][1]=nexty;
				}
				else
				{
					int nextx=curx+move[j+4][0],nexty=cury+move[j+4][1];
					if(nextx<1||nextx>8||nexty<1||nexty>8)	continue;
					next_state=cur_state;
					if(!check_occupy(next_state,nextx,nexty))
						next_state.board[i][0]=nextx,next_state.board[i][1]=nexty;
					else continue;
				}				
				change_seq(next_state);
				if(has_visit(next_state))	continue;
				set_visit(next_state);
				if(has_visit(end_state))	return true;
				next_state.lev=cur_state.lev+1;
				if(next_state.lev<4)	seq.push(next_state);
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
		memset(visit,false,sizeof(visit));
		memset(cur_visit,false,sizeof(cur_visit));
		scanf("%d",&init_state.board[0][1]);
		int i,j;
		for(i=1;i<4;i++)
		{scanf("%d %d",&init_state.board[i][0],&init_state.board[i][1]);}
		for(i=0;i<4;i++)
		{scanf("%d %d",&end_state.board[i][0],&end_state.board[i][1]);}
		change_seq(init_state);
		change_seq(end_state);
		set_visit(init_state);
		change_seq(end_state);

		init_state.lev=0;
		if(board_search()||ano_board_search())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}



