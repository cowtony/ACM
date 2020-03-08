//394426 2003-12-11 22:53:59 Accepted 1693 C++ 00:00.01 420K just for play 
#include<stdio.h>

struct	ROOM{int dist,cur,tot,left,nbr[101];}room[101];

void	Addedge(int from,int to)
{
	room[from].nbr[room[from].cur++]=to;
	room[to].nbr[room[to].cur++]=from;
	room[from].left--;
	room[to].left--;
}
void bubblesort(int cv[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int pt=i;
		for(j=i+1;j<n;j++)
			if(cv[j]<cv[pt])	pt=j;

		if(i!=pt){j=cv[i];cv[i]=cv[pt];cv[pt]=j;}
	}
}
int main()
{
//	freopen("1693_smh.in","r",stdin);
//	freopen("1693.out","w",stdout);
	int n;

	scanf("%d",&n);
	
	while(n--)
	{
		int num;
		scanf("%d",&num);
		room[0].dist=0;
		room[0].left=num;
		room[0].cur=0;
		int i,j;
		int cr=0;
		while(1)
		{
			scanf("%d",&num);
			if(num==0)	break;
			if(num>0)
			{
				cr++;
				room[cr].cur=0;
				room[cr].left=num;
				int cp=cr-1;
				while(cp>=0&&room[cp].left<=0)	cp--;
				room[cr].dist=room[cp].dist+1;
				Addedge(cr,cp);
			}
			else
			{
				int cp=cr,dd,to;
				while(cp>=0&&room[cp].left<=0)	cp--;
				dd=room[cp].dist+num;
				to=cp-1;
				while(to>=0)
				{
					if(room[to].left<=0||room[to].dist!=dd)
						to--;
					else	break;
				}	
				Addedge(cp,to);
			}
					
		}
		for(i=0;i<=cr;i++)
		{
			printf("%d",i+1);
			bubblesort(room[i].nbr,room[i].cur);
			for(j=0;j<room[i].cur;j++)
				printf("% d",room[i].nbr[j]+1);
			printf("\n");

		}
	}
	return 0;
}