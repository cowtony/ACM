#include <stdio.h>
#include <string.h>
int main()
{
	char a[12][12],c;
	int b[12][12];
	int i,j,step,pointx,pointy;
	int row,column,start,p,p2;
	while(1)
	{
		scanf("%d%d%d%*c",&row,&column,&start);
		if(row==0&&column==0&&start==0) break;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				scanf("%c",&a[i][j]);
			}
			scanf("%*c");
		}
		for(i=0;i<=row+1;i++)
		{
			for(j=0;j<=column+1;j++)
			{
				b[i][j]=0;
			}
		}
		step=1;
		pointx=1;
		pointy=start;
		c=a[pointx][pointy];
		p=0;
		while(1)
		{
			if(b[pointx][pointy]!=0) {p2=step;p=2;break;}
			b[pointx][pointy]=step++;
			if(c=='E')
			{
				c=a[pointx][++pointy];
				if(pointy>column) {p=1;break;}
			}
			else if(c=='W')
			{
				c=a[pointx][--pointy];
				if(pointy<1) {p=1;break;}
			}
			else if(c=='S')
			{
				c=a[++pointx][pointy];
				if(pointx>row) {p=1;break;}
			}
			else if(c=='N')
			{
				c=a[--pointx][pointy];
				if(pointx<1) {p=1;break;}
			}
		}
		if(p==1) printf("%d step(s) to exit\n",step-1);
		else if(p==2) printf("%d step(s) before a loop of %d step(s)\n",b[pointx][pointy]-1,p2-b[pointx][pointy]);
	}
	return 0;
}





