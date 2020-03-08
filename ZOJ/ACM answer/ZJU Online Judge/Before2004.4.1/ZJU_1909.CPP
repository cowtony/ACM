#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n; 
int f[21] , s[21];
int len;
bool mark[21];

bool search(int k , int p , int tot){
	if(k == 4)	return true;
	if(tot == len) return search(k + 1 , 0 , 0);
	if(tot + s[p] < len) return false;
	for(; p<n; p++)
		if(!mark[p] && tot + f[p] <= len){
			mark[p] = 1;
			if(search(k , p + 1 , tot + f[p])) return true;
			mark[p] = 0;
		}
	return false;	
}

bool greater(const int& a, const int& b){
	return a > b;
}


int main(){	
	//freopen("in.txt" , "r" , stdin);

	int T;
	int i;

	for(scanf("%d" , &T); T; T--){
		scanf("%d" , &n);
		for(i=0; i<n; i++) scanf("%d" , f + i);
		sort(f , f + n , greater);		
		s[n] = 0;
		for(i=n-1; i>=0; i--)
			s[i] = s[i + 1] + f[i];

		if (s[0] % 4 != 0){
			printf("no\n");
		}
		else {
			len = s[0] / 4;
			memset(mark , 0 , sizeof(mark));
			if(search(0 , 0 , 0)) printf("yes\n");
			else printf("no\n");
		}		
	}	
	
	return 0;
}
