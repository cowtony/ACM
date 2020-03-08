//161489 2003-05-29 23:19:11 Wrong Answer 1137 C++ 00:04.39 4316K just for play 
//161681 2003-05-30 12:15:42 Accepted 1137 C++ 00:05.05 5112K just for play 
#include<stdio.h>
#include<string.h>

const int MAXN=1000;

int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, k;
//	memset(match1, 0xff, sizeof(int)*MAXN);
//	memset(match2, 0xff, sizeof(int)*MAXN);
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		memset(t, 0xff, sizeof(int)*MAXN);
		for (s[p=q=0]=i; p<=q&&match1[i]<0; p++){
			for (k=s[p], j=0; j<n&&match1[i]<0; j++){
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j];
					t[j]=k;
					if (s[q]<0){
						for (p=j; p>=0; j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
					}
				}
			}
		}
	}
	return ret;
}

int boymat[MAXN],girlmat[MAXN],map[MAXN][MAXN];
int tmat[2*MAXN][100];
int cnt[2*MAXN];
int map_to[2*MAXN];
int boy_cnt,girl_cnt;	
int visit[2*MAXN];

void dfs(int pt,int flag)
{
	int i;			
	for(i=0;i<cnt[pt];i++)
	{
		int tt=tmat[pt][i];
		if(map_to[tmat[pt][i]]<0)
		{
			if(flag==0)	map_to[tt]=girl_cnt++;
			else	map_to[tt]=boy_cnt++;
		}
		if(flag==0)
			map[map_to[pt]][map_to[tt]]=1;
		else	map[map_to[tt]][map_to[pt]]=1;
	}
	visit[pt]=1;
	for(i=0;i<cnt[pt];i++)
		if(!visit[tmat[pt][i]])	dfs(tmat[pt][i],1-flag);
}



int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		memset(map,0,sizeof(map));
		memset(boymat,0xff,sizeof(boymat));
		memset(girlmat,0xff,sizeof(girlmat));
		memset(visit,0,sizeof(visit));
		memset(map_to,0xff,sizeof(map_to));
		int i,j;
		boy_cnt=0,girl_cnt=0;
		char temp[10];int from,tt;
		for(i=0;i<n;i++)
		{
			scanf("%s",temp);
			from=tt=0;

			for(j=0;j<(int)strlen(temp)-1;j++)	from=from*10+temp[j]-'0';
			scanf("%s",temp);
			for(j=1;j<(int)strlen(temp)-1;j++)	tt=tt*10+temp[j]-'0';
			cnt[from]=tt;
			for(j=0;j<tt;j++)	scanf("%d",&tmat[from][j]);			
		}
		int total=0;
		for(i=0;i<n;i++)
			if(cnt[i]==0){total++;visit[i]=1;}
		for(i=0;i<n;i++)
		{
			if(!visit[i])
			{
				visit[i]=1;
				map_to[i]=boy_cnt++;
				dfs(i,0);
			}
		}
		
/*
		for(i=0;i<boy_cnt;i++)
		{
			for(j=0;j<girl_cnt;j++)
				printf("%d ",map[i][j]);
			printf("\n");
		}
*/
		tt=hungary(boy_cnt,girl_cnt,map,boymat,girlmat);
		total=boy_cnt+girl_cnt+total-tt;
//		printf("%d=======\n",tt);
		printf("%d\n",total);		
	}
	return 0;
}

