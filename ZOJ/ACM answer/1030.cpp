#include<stdio.h>

struct POINT
{
	int seq;
	int x,y;
	int deg;
	int adj[201];	
	void input()
	{
		scanf("%d",&seq);
		scanf("%d %d",&x,&y);
		scanf("%d ",&deg);
		int i;
		for(i=0;i<deg;i++)	scanf("%d",&adj[i]);
	}

};
POINT vet[201];
int PtN,CicSize;
int Total;

int find_seq(int t)
{
	int i;
	for(i=0;i<PtN;i++)	
		if(vet[i].seq==t)	return i;
}

void find_point(int n)
{
	int i;
	for(i=0;i<vet[n].deg;i++)
		vet[n].adj[i]=find_seq(vet[n].adj[i]);
}


void search(int cur,int set[],int lev)
{
	if(lev==CicSize)



int main()
{
	freopen("1030.in","r",stdin);
//	freopen("1030.out","w",stdout);
	int nn,i,j,t;
	scanf("%d",&nn);
	while(nn--)
	{
		scanf("%d",&PtN);
		for(i=0;i<PtN;i++)	vet[i].input();
		scanf("%d",&CicSize);
		for(i=0;i<PtN;i++)	find_point(i);	
		Total=0;
		int set[202];
		for(i=0;i<PtN;i++)
		{	
			set[0]=i;
			search(i,set,1);
		}
	}
	return 0;
}


		
		
	

			
	
