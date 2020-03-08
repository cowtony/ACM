#include<stdio.h>
#include<string.h>

int shield[20];
const int MaxNum=1024;

void initial()
{
	int cur=1,i;
	for(i=0;i<=19;i++)
	{
		shield[i]=cur;
		cur=cur<<1;
	}
//	printf("%d\n",shield[19]);
}

int main()
{
	int nn,i,j,t;
	int can_pick[21],visit[MaxNum];
	initial();
	scanf("%d",&nn);
	for(t=1;t<=nn;t++)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%d",&can_pick[i]);
		memset(visit,0xff,sizeof(visit));
		
	}
	return 0;
}
		