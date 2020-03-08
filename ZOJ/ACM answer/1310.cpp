//113837 2003-04-09 23:17:05 Time Limit Exceeded 1310 C++ 00:01.00 488K Century Ghost 
//113875 2003-04-09 23:49:05 Wrong Answer 1310 C++ 00:00.09 464K Century Ghost 
//114118 2003-04-10 11:59:04 Wrong Answer 1310 C++ 00:00.06 468K just for play 
//114215 2003-04-10 12:34:31 Accepted 1310 C++ 00:00.05 468K just for play 

//using bfs
#include<stdio.h>
#include<list>
#include<string.h>

using namespace std;
struct node_type
{
	int x,y;
	int time;
	int face;

	
};

list<node_type>gen_list;
int row,col;int state[53][53];
bool visit[51][51][4];
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int beg_x,beg_y,end_x,end_y;


int get_dir(char* str)
{
	if(strcmp(str,"north")==0)	return 0;
	if(strcmp(str,"east")==0)	return 1;
	if(strcmp(str,"south")==0)	return 2;
	if(strcmp(str,"west")==0)	return 3;
	return -1;
}

inline int can_advance(int x,int y)
{
	return (!state[x][y]&&!state[x][y+1]&&!state[x+1][y]&&!state[x+1][y+1]);
}


	
int search()
{

	while(!gen_list.empty())
	{
		node_type temp=gen_list.front();
		gen_list.pop_front();
		node_type result;
	
		result.x=temp.x;result.y=temp.y;result.time=temp.time+1;
		result.face=temp.face+1;
		if(result.face>3)	result.face=0;
		if(!visit[result.x][result.y][result.face])
		{
			gen_list.push_back(result);
			visit[result.x][result.y][result.face]=true;
		}
		result.face=temp.face-1;
		if(result.face<0)	result.face=3;
		if(!visit[result.x][result.y][result.face])
		{
			gen_list.push_back(result);
			visit[result.x][result.y][result.face]=true;
		}		
		int dirpt=temp.face;
		int pt;
		for(pt=1;pt<=3;pt++)
		{			
			result.face=dirpt;
			int nextx=temp.x+pt*move[dirpt][0];
			int nexty=temp.y+pt*move[dirpt][1];		
			if(nextx>0&&nextx<row&&nexty>0&&nexty<col)	//take care
			{
				if(visit[nextx][nexty][dirpt])	continue;
				if(!can_advance(nextx,nexty))	break;
				result.x=nextx;
				result.y=nexty;
				if(nextx==end_x&&nexty==end_y)	return result.time;
				gen_list.push_back(result);		
				visit[result.x][result.y][result.face]=true;
			}
			else	break;
		}

	}
	return -1;
}
			

		
		


	

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(scanf("%d%d",&row,&col))
	{
		if(row==0&&col==0)	break;
		memset(visit,0,sizeof(visit));
		memset(state,0,sizeof(state));
		int i,j;
		for(i=1;i<=row;i++)
			for(j=1;j<=col;j++)
				scanf("%d",&state[i][j]);
		
		
		char str[6];
		scanf("%d%d%d%d%s",&beg_x,&beg_y,&end_x,&end_y,str);
		if(beg_x==end_x&&beg_y==end_y)	
		{
			printf("0\n");continue;
		}
		if(!can_advance(end_x,end_y))
		{
			printf("-1\n");continue;
		}
		gen_list.clear();		
		node_type temp;
		temp.x=beg_x;temp.y=beg_y;
		temp.face=get_dir(str);
		temp.time=0;
		visit[temp.x][temp.y][temp.face]=true;
		gen_list.push_back(temp);
		int total_time=search();
		printf("%d\n",total_time);
	}
	return 0;
}

