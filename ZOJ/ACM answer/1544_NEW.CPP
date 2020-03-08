//147956 2003-05-11 18:07:57 Accepted 1544 C++ 00:00.01 580K just for play 



#include<stdio.h>
#include<string.h>

const double epsilon=1e-10;
struct currency{int to;double rate,com;};

currency input[101][101];
int total[101];
double val[101];
int n;
int visit[101];

int dfs(int root)
{
	visit[root]=1;
	double t_val;
	int dest;
	int i;
	for(i=0;i<total[root];i++)
	{
		t_val=(val[root]-input[root][i].com)*input[root][i].rate;
		dest=input[root][i].to;
		if(visit[dest])
			if(t_val>val[dest]+epsilon)	return 1;
		if(t_val>val[dest])
		{
			val[dest]=t_val;
			if(dfs(dest))	return 1;
		}
	}
	visit[root]=0;
	return 0;
}
int main()
{
	int m,s;double v;
	while(scanf("%d%d%d%lf",&n,&m,&s,&v)!=EOF)
	{
		int i;
		memset(total,0,sizeof(total));
		for(i=0;i<m;i++)
		{
			int t_fir,t_sec;double r_fir,c_fir,r_sec,c_sec;
			scanf("%d%d%lf%lf%lf%lf",&t_fir,&t_sec,&r_fir,&c_fir,&r_sec,&c_sec);
			int tt=total[t_fir];
			input[t_fir][tt].to=t_sec;input[t_fir][tt].rate=r_fir;
			input[t_fir][tt].com=c_fir;
			total[t_fir]++;
			tt=total[t_sec];
			input[t_sec][tt].to=t_fir;input[t_sec][tt].rate=r_sec;
			input[t_sec][tt].com=c_sec;
			total[t_sec]++;
		}
		memset(visit,0,sizeof(visit));
		for(i=1;i<=n;i++)	val[i]=0.0;
		val[s]=v;
		if(dfs(s))
			printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}


			
