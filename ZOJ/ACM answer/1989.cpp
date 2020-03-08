//474016 2004-02-17 20:57:23 Accepted 1989 C++ 00:00.43 1656K just for play 
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;


struct PEOPLE
{
	int id;
	int sa;
	int hg;
};
PEOPLE peo[30001];
int m;
int bos[30001];
int sub[30001];

int my_cmp(const void* fir,const void* sec)
{
	if((*(PEOPLE*)fir).sa>(*(PEOPLE*)sec).sa)	return 1;
	return -1;
}
void cal_boss()
{
	int i;
	bos[m-1]=-1;
	for(i=m-2;i>=0;i--)
	{
		int pt=i+1;
		while(1)
		{
			if(peo[pt].hg>=peo[i].hg)	break;
			pt=bos[pt];
			if(pt<0)	break;
		}
		bos[i]=pt;
	}
	memset(sub,0,sizeof(sub));
	for(i=0;i<m;i++)
	{
		if(bos[i]==-1)	continue;
		sub[bos[i]]+=sub[i]+1;
	}
}

int main()
{
//	freopen("1989.in","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int q;
		scanf("%d %d",&m,&q);
		int i,j,t;
		for(i=0;i<m;i++)
			scanf("%d %d %d",&peo[i].id,&peo[i].sa,&peo[i].hg);
		qsort(peo,m,sizeof(peo[0]),my_cmp);
		map<int,int>mm;
		mm.clear();
		for(i=0;i<m;i++)
			mm[peo[i].id]=i;
		cal_boss();
		while(q--)
		{
			int tnum;
			scanf("%d",&tnum);
			int pt=mm[tnum];
			if(bos[pt]==-1)	printf("0 ");
			else	printf("%d ",peo[bos[pt]].id);
			printf("%d\n",sub[pt]);
		}
	}
	return 0;
}