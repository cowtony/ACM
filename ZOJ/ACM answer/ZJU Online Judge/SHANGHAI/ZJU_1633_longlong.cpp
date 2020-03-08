#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

long long f[100];
int len;
void calc(){
	f[0] = 4;  f[1] = 3;
	for(len = 2; ; len ++){
		f[len] = f[len-1] + f[len-2];
		if(f[len] < 0) break;
	}
}

int main(){
	long long n;
	int p;
	calc();
	while(cin >> n){
		p = len;
		while(p >= 2){
			if(n <= f[p-1]) p--;
			else{				
				n -= f[p-1];
				p-=2;
			}
		}

		if(p==1){
			if(n == 1 || n == 3) puts("T");
			else puts(".");
		}
		else{
			if(n == 1 || n == 4) puts("^");
			else puts("_");
		}		
	}		

	return 0;
}
