//262367 2003-08-17 23:31:45 Wrong Answer 1506 C++ 00:00.00 456K just for play 
#include<iostream.h>
#include<stdio.h>
#include<string.h>
	char cell[101][101];
	int Line,Cole;
	int Ex,Ey;
bool end[101][101];
bool visit[101][101];
void FindEntrance(int& x,int& y,int& orgx,int& orgy)
{
	int i,j;
	for(i=1;i<Line-1;i++)
	{
		for(j=0;j<Cole;j++)
		{
			if(cell[i][j]=='#')	break;
			if(cell[i][j]=='.'&&cell[i-1][j]=='#'&&cell[i+1][j]=='#')	
			{x=i;y=j;orgx=i;orgy=j-1;return;}
		}
		for(j=Cole-1;j>=0;j--)
		{
			if(cell[i][j]=='#')	break;
			if(cell[i][j]=='.'&&cell[i-1][j]=='#'&&cell[i+1][j]=='#')	
			{x=i;y=j;orgx=i;orgy=j+1;return;}
		}
	}
	for(i=1;i<Cole-1;i++)
	{
		for(j=0;j<Line;j++)
		{
			if(cell[j][i]=='#')	break;
			if(cell[j][i]=='.'&&cell[j][i-1]=='#'&&cell[j][i+1]=='#')
			{x=j;y=i;orgx=j-1;orgy=i;return;}
		}
		for(j=Line-1;j>=0;j--)
		{
			if(cell[j][i]=='#')	break;
			if(cell[j][i]=='.'&&cell[j][i-1]=='#'&&cell[j][i+1]=='#')
			{x=j;y=i;orgx=j+1;orgy=i;return;}
		}
	}
}
bool FindCoutYard(int curx,int cury,int orgx,int orgy)
{
	if(curx!=Ex&&cury!=Ey)
	{
		if(curx==orgx)
		{
			if((cell[curx-1][cury]=='.'&&cell[orgx-1][orgy]=='.')||
				(cell[curx+1][cury]=='.'&&cell[orgx+1][orgy]=='.'))
				return true;
		}
		else
		{
			if((cell[curx][cury-1]=='.'&&cell[orgx][orgy-1]=='.')||
				(cell[curx][cury+1]=='.'&&cell[orgx][orgy+1]=='.'))
				return true;
		}
	}
	return false;
}




bool Move(int curx,int cury,int orgx,int orgy)
{
//	printf("%d - %d\n",curx,cury);
	if(visit[curx][cury])	return false;
	visit[curx][cury]=true;
	if(FindCoutYard(curx,cury,orgx,orgy))	return true;	
	int nextx,nexty;
	nextx=curx-(cury-orgy);nexty=cury+(curx-orgx);
//	printf("1   %d  %d\n",nextx,nexty);
	if(cell[nextx][nexty]=='.')
	{
		
		return Move(nextx,nexty,curx,cury);
	}
	else
	{
		
		nextx=curx+(curx-orgx);nexty=cury+(cury-orgy);
//		printf("2   %d  %d ---\n",nextx,nexty);
		if(cell[nextx][nexty]=='.')
		{
			
			return Move(nextx,nexty,curx,cury);
		}
		else 
		{
			nextx=curx+(cury-orgy);nexty=cury-(curx-orgx);
//			printf("3   %d  %d  == \n",nextx,nexty);
			if(cell[nextx][nexty]=='.')
			{
				
				return Move(nextx,nexty,curx,cury);
			}
			else{	return false;}
		}
	}
}
	


int main()
{
	freopen("1506.in","r",stdin);
//	freopen("1506.out","w",stdout);
	while(cin>>Line>>Cole)
	{
		int i,j;
		for(i=0;i<Line;i++)
			for(j=0;j<Cole;j++)
				cin>>cell[i][j];
		memset(visit,false,sizeof(visit));
		memset(end,false,sizeof(end));
		int  orgx,orgy;
		FindEntrance(Ex,Ey,orgx,orgy);
//		cout<<Ex<<"  "<<Ey<<"\n";
		
		if(Move(Ex,Ey,orgx,orgy))
			cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	return 0;
}
		


