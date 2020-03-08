//114337 2003-04-10 13:23:29 Time Limit Exceeded 1384 C++ 00:10.00 828K just for play 
#include<vector>
#include<string.h>
#include<stdio.h>
#include<list>
using namespace std;

const int maxnum=10010;
vector<int>success[maxnum];
vector<int>result;
int total_visit[maxnum];
int temp_visit[maxnum];
int n,m;


int visit(int fir,int sec)
{
	int i;
	for(i=0;i<success[fir].size();i++)
		if(success[fir][i]==sec)	return 1;
	return 0;
}
void exchange(int& fir,int& sec)
{
	int temp=fir;
	fir=sec;
	sec=temp;
}
void search(int sec)
{
	list<int>temp_list;int cur;
	temp_list.push_back(sec);
	while(!temp_list.empty())
	{
		int t;

		cur=temp_list.front();
		printf("%d---->%d----link\n",sec,cur);
		temp_list.pop_front();
		int i;
		for(i=0;i<success[cur].size();i++)
		{
			int tt=success[cur][i];
			if(temp_visit[tt])	continue;
			temp_visit[tt]=1;
			temp_list.push_back(tt);
		}
	}
}

int sel_first(int pt)
{
	int len=success[pt].size();
	if(len==2)
	{
		if(total_visit[success[pt][0]])	return success[pt][1];
		else	return success[pt][0];
	}
	int i;
	for(i=0;i<len-1;i++)
	{
		printf("%d-----%d \n ",pt,success[pt][i]);
		if(total_visit[success[pt][i]])	continue;
		memset(temp_visit,0,sizeof(temp_visit));
		temp_visit[pt]=1;
		temp_visit[success[pt][i]]=1;
		search(success[pt][i]);
		int j;
		for(j=0;j<len;j++)
		{
			if(j==i)	continue;
			if(!temp_visit[success[pt][j]])	break;
		}
		if(j==len)	return success[pt][i];
	}
	return success[pt][len-1];
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;
	scanf("%d",&nn);
	
	while(nn--)
	{
		
		scanf("%d%d",&n,&m);
		result.clear();
		memset(total_visit,0,sizeof(total_visit));
		int i;int fir,sec;
		for(i=1;i<=n;i++)	success[i].clear();
		
		for(i=0;i<(m+n);i++)
		{
		
			scanf("%d%d",&fir,&sec);
		
			
			success[fir].push_back (sec);
			success[sec].push_back (fir);
		}
		result.push_back(1);int pt=1;
		total_visit[1]=1;
		
		for(i=1;i<n;i++)
		{
			int tt=sel_first(pt);
//			printf("%d------->%d\n",pt,tt);
			result.push_back (tt);
			total_visit[tt]=1;
			pt=tt;
		}
		printf("1");
		if(result[1]<result[n-1])
		{
			for(i=1;i<n;i++)
				printf(" %d",result[i]);
		}
		else
		{
			for(i=n-1;i>=1;i--)
				printf(" %d",result[i]);
		}
		printf("\n");

	}
	return 0;
}


						




