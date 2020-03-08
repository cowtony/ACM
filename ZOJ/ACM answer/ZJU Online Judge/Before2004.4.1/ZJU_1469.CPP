#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//typedef unsigned long;

struct sol{
	long A , B;
} list[1000];
int cnt;

long n;

bool operator < (const sol& a , const sol& b){
	return a.A < b.A;
}

int len(long k){
	int ret = 0;
	while(k > 0){
		ret ++;
		k /= 10;		
	}
	return ret ? ret : 1;
}

void solve(){
	cnt = 0;
	long base = 1;
	long A , B , C;
	for( ; base <= n; base *= 10 ){
		for(B=0; B<10; B++){
			if(B * base > n) break;
			C = n % base;
			if(C % 2 == 0){
				C /= 2;
				A = (n - C * 2 - B * base) / base;
				if(A % 11 == 0){
					A /= 11;										
					list[cnt].A = A * base * 10 + B * base + C;
					list[cnt].B = A * base + C;
					if(list[cnt].A + list[cnt].B == n && list[cnt].A > list[cnt].B)
						cnt++;
				}
			}

			C = n % base + base;
			if(C % 2 == 0){
				C /= 2;
				A = (n - C * 2 - B * base) / base;
				if(A % 11 == 0){
					A /= 11;					
					list[cnt].A = A * base * 10 + B * base + C;
					list[cnt].B = A * base + C;
					if(list[cnt].A + list[cnt].B == n && list[cnt].A > list[cnt].B)
						cnt++;
				}
			}
		}
	}

	int i , pcnt = cnt;
	sort(list , list + cnt);	
	for(i=0; i<cnt; i++){
		if(i > 0 && list[i].A == list[i-1].A && list[i].B == list[i-1].B) --pcnt;
	}
	printf("%d\n" , pcnt);
	for(i=0; i<cnt; i++){
		if(i > 0 && list[i].A == list[i-1].A && list[i].B == list[i-1].B) continue;
		printf("%d + " , list[i].A);
		base = len(list[i].A) - 1 - len(list[i].B);		
		for(;base >0; base--) putchar('0');
		printf("%d = %d\n" , list[i].B , n);		
	}
}

int main(){	
	int T;
	scanf("%d" , &T);
	while(T--){
		scanf("%ld" , &n);
		if(n < 10) printf("0\n");
		else solve();
		if(T) putchar('\n');
	}

	
	return 0;
}
