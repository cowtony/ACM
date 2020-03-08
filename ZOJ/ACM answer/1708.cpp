//336367 2003-11-04 12:30:47 Accepted 1708 C++ 00:00.00 376K just for play 
#include<stdio.h>
#include<string.h>

int main()
{
//	freopen("1708.in","r",stdin);
	int row,col,curcol;
	char grid[11][11];
	while(scanf("%d %d %d",&row,&col,&curcol)!=EOF)
	{
		if(row==0&&col==0&&curcol==0)	break;
		int i;
		for(i=1;i<=row;i++)	
			scanf("%s",grid[i]);
		int enter[11][11];
		memset(enter,0,sizeof(enter));
		int curx=1,cury=curcol;
		
		int pt=1;
		while(1)
		{
			if(curx<1||curx>row||cury<1||cury>col)	break;
			if(enter[curx][cury]>0)	break;
			enter[curx][cury]=pt;			
			pt++;
			switch(grid[curx][cury-1])
			{
			case 'W':cury--;break;
			case 'E':cury++;break;
			case 'N':curx--;break;
			case 'S':curx++;break;
			}		
		}
		if(curx<1||curx>row||cury<1||cury>col)
			printf("%d step(s) to exit\n",pt-1);
		else
			printf("%d step(s) before a loop of %d step(s)\n",enter[curx][cury]-1,pt-enter[curx][cury]);
	}
	return 0;
}

		

			

