#include <stdio.h>
#include <string.h>

#define maxn 100100

int n;
struct elem{
	int v;
	int idx;
} list[maxn] , tmp[maxn];
int rank[maxn];

double cnt;

void merge_sort(int p , int r){
	if(p + 1 >= r) return;

	int m = (p + r) / 2;
	merge_sort(p , m);
	merge_sort(m , r);

	//merge
	int i , j , t;
	for(t=p; t<r; t++)
		tmp[t] = list[t];
	i = p; j = m;
	for(t=p; t<r; t++){
		if((i < m) && (j == r || tmp[i].v < tmp[j].v))
		{
			list[t] = tmp[i++];
		}
		else{
			cnt += m - i;
			list[t] = tmp[j++];
		}
	}
}

void solve(){
	cnt = 0;
	merge_sort(0 , n);

	int i , t;
	for(i=0; i<n; i++)
		rank[list[i].idx] = i;

	int cnt2 = 0;
	for(i=0; i<n; i++){
		while(rank[i] != i){
			t = rank[rank[i]];
			rank[rank[i]] = rank[i];
			rank[i] = t;
			++cnt2;
		}
	}

	printf("%d\n%.0lf\n" ,cnt2, cnt);
}

int main(){
//	freopen("in.txt" , "r" , stdin);
	int i;
	while(scanf("%d" , &n) != EOF){
		for(i=0; i<n; i++){
			scanf("%d" , &list[i].v);
			list[i].idx = i;
		}
		solve();
	}	

	return 0;
}
