#include <cstdio>
#include <memory>
#include <queue>
#include <iostream>
using namespace std;
char Asteroids[101][101][101];//
int as[101][101][101];
int N;

struct coordinate
{
	int column;
	int row;
	int slice;

	void operator = (coordinate p)
	{column = p.column;row = p.row; slice = p.slice;	}

	bool operator == (coordinate p)
	{	return column == p.column&& row == p.row && slice == p.slice;}
	
	coordinate operator + (coordinate p)
	{
		coordinate temp;
		temp.column = column + p.column;
		temp.row = row + p.row;
		temp.slice = slice + p.slice;
		return temp;
	}

};
coordinate first,last;



const coordinate xyz[8] ={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

void read()
{
	int i,j;

	for( i = 0 ; i < N ; i++)
		for( j = 0 ; j < N; j++)
				scanf("%s",Asteroids[i][j]); //i slice; j : row ; k : column;

		    scanf("%d%d%d",&first.column,&first.row,&first.slice);
			scanf("%d%d%d",&last.column,&last.row,&last.slice);
			char waste2[5];
			cin>>waste2;
}

inline int valid(coordinate p)
{
	if(p.column >= 0 && p.row >= 0 && p.slice >=0 &&p.column < N && p.row <N && p.slice < N 
		&& as[p.slice][p.row][p.column] ==0&& (int)Asteroids[p.slice][p.row][p.column] =='O' )
			return true;
	return false;

}

void bfs()
{
	int i ;
	coordinate temp;
	queue<coordinate>p;
	p.push(first);
	while(!p.empty())
	{
		temp = p.front();
		coordinate temp1;
		p.pop();
		for( i = 0 ; i < 6 ; i++)
		{
			temp1 = temp + xyz[i];
			if(valid(temp1))
			{
				p.push(temp1);
				as[temp1.slice][temp1.row][temp1.column] = as[temp.slice][temp.row][temp.column] + 1; 
				if(temp1 == last)
					return ;
			}
		}
	}
}

int main()
{
	char waste[6];
	
	//freopen("1.txt","r",stdin);
	while(scanf("%s%d",waste,&N)!=EOF)
	{
		memset(as,0,sizeof(as));
		read();
		if( first == last)
			printf("%d 0\n",N);
		else 
		{
			bfs();
			if(as[last.slice][last.row][last.column] !=0 )
				printf("%d %d\n",N,as[last.slice][last.row][last.column] );
			else 
				printf("NO ROUTE\n");
		}
		
	}
	return 0 ;
}