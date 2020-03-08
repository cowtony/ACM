#include <stdio.h>
#include <string.h>

int M,N;
int topM,depM,tarM; //最高等级 最低等级 酋长等级

struct Listtype{
	int t,v; //替代品的编号和"优惠价格"
};

struct data{
	int p,l,x; // 物品的价格 主人的地位等级 替代品总数	
	Listtype List[101]; //替代品列表
};

data G[101];
int Best;

int Low[100];

inline int min(int a,int b){
	return(a < b ? a : b);
}

int Top,Dep;// 等级上下界

int dp(int v){ 
	if(Low[v] < 0){
		Low[v] = G[v].p;
		for(int i=0; i<G[v].x; i++)
			if((G[G[v].List[i].t].l <= Top) && (G[G[v].List[i].t].l >= Dep)){
				Low[v] = min(Low[v],dp(G[v].List[i].t) + G[v].List[i].v);
			}
	}

	return Low[v];
}

void solve(){
	//方法 ：确定等级上下界多次dp
	for(int top = min(topM,tarM + M); top>=tarM; top--){		
		memset(Low,255,sizeof(Low)); Top = top; Dep = top - M;
		Best = min(Best,dp(1));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
	while(scanf("%d %d",&M,&N) > 0)
    {
        int i,j;
        for(topM=-1,depM=1000000,i=1; i<=N; i++){
            scanf("%d %d %d",&G[i].p,&G[i].l,&G[i].x);
            if(G[i].l > topM) topM = G[i].l;
            if(G[i].l < depM) depM = G[i].l;
            for(j=0; j<G[i].x; j++) scanf("%d %d",&G[i].List[j].t,&G[i].List[j].v);		
        }
        tarM = G[1].l;

        Best = G[1].p;
        solve();
        printf("%d\n",Best);
	}
	return 0;
}