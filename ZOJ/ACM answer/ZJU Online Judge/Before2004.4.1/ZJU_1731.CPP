#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

#define LEN 10001

int n;
struct task{
	int p , d;
};
task List[LEN];

bool operator < (const task& a , const task& b){
	return a.p > b.p;
}

int prev[LEN];

int find_bot(int k){
	if (k == prev[k]){
		return k;
	}
	prev[k] = find_bot(prev[k]);
	return prev[k];
}

void solve(){
	int i , k;
	for(i = 0 ; i < LEN ; i++)
		prev[i] = i;
	int ret = 0;

	for(i = 0; i < n; i++){
		k = find_bot(List[i].d);
		if( k == 0 ) continue;
		ret += List[i].p;
		prev[k] = prev[k - 1];
	}

	printf("%d\n" , ret);
}

int main(){
	//freopen("d.in" , "r" , stdin);
	int i;
	while(cin >> n){
		for(i=0; i<n; i++)
			scanf("%d %d" , &List[i].p , &List[i].d);
		sort(&List[0] , &List[n]);

		solve();
	}
	
	return 0;
}
