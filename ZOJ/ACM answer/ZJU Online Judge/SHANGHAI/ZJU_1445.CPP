#include <stdio.h>
#include <string.h>

/////////////////////////////////// BigNum

#define MAXLEN 180
struct BigNum{
	int l;
	int c[MAXLEN + 1];
};

void Assign_int(BigNum& a , int k){
	memset(a.c , 0 , sizeof(a.c));
	a.l = 0;
	while(k > 0){
		a.c[++a.l] = k % 10;
		k /= 10;
	}
}

void Assign_str(BigNum& a , char* s){
	memset(a.c , 0 , sizeof(a.c));
	a.l = strlen(s);
	for(int i=a.l; i; i--){
		a.c[i] = (*s++) - '0';
	}
}

short comp(BigNum& a , BigNum& b){
	// return value :  a < b(-1) a = b(0) a > b(1)
	if(a.l < b.l) return -1;
	if(a.l > b.l) return 1;
	for(int i=a.l; i; i--){
		if(a.c[i] < b.c[i]) return -1;
		if(a.c[i] > b.c[i]) return 1;
	}
	return 0;
}

void add(BigNum& a , const BigNum& b){
	// BigNum a += b
	if(a.l < b.l) a.l = b.l;
	for(int i=1; i<=a.l; i++){
		a.c[i] += b.c[i];
		a.c[i+1] += a.c[i] / 10;
		a.c[i] %= 10;
	}
	if(a.c[a.l+1]) a.l ++;		
}

void minus(BigNum& a , const BigNum& b){
	// BigNum a -= b
	// 这里默认a > b
	for(int i=1; i<=a.l; i++){
		a.c[i] -= b.c[i];
		if(a.c[i] < 0){
			a.c[i+1]--;
			a.c[i] += 10;
		}
	}
	if(a.l && !a.c[a.l]) a.l--;
}

void mul_int(BigNum& a , int k){
	// BigNum a *= int(k)
	for(int i=1; i<=a.l; i++){
		a.c[i] = a.c[i] * k + a.c[i-1] / 10;
		a.c[i-1] %= 10;
	}
	while(a.c[a.l] >= 10){
		a.c[a.l + 1] = a.c[a.l] / 10;
		a.c[a.l] %= 10;
		++a.l;
	}
}

void multiply(BigNum& c , const BigNum& a , const BigNum& b){
	// BigNum c = a * b
	memset(c.c , 0 , sizeof(c.c));
	c.l = a.l + b.l - 1;
	int i , j;
	for(i=1; i<=a.l; i++)
		for(j=1; j<=b.l; j++)
			c.c[i+j-1] += a.c[i] * b.c[j];
	for(i=1; i<=c.l; i++){
		c.c[i+1] += c.c[i] / 10;
		c.c[i] %= 10;
	}
	while(c.c[c.l+1]){
		++c.l;
		c.c[c.l + 1] = c.c[c.l] / 10;
		c.c[c.l] %= 10;
	}
}

void div_int(BigNum& a , int k){
	int i , c = 0;
	for(i=a.l; i>0; i--){
		a.c[i] += c * 10;
		c = a.c[i] % k;
		a.c[i] /= k;
	}

	while(a.l > 1 && a.c[a.l] == 0) a.l--;
}

void C(int n , int m , BigNum& ret){
	int i;
	Assign_int(ret , 1);
	for(i=n-m+1; i<=n; i++)
		mul_int(ret , i);
	for(i=1; i<=m; i++)
		div_int(ret , i);
}

void print(const BigNum& a){
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	putchar('\n');
}

/////////////////////////////////// BigNum

int n , m;
short L[110] , R[110];
short deg[110];
short bone[110];
BigNum value[100];

void init(){
	scanf("%d %d" , &n , &m);
	int i , a , b;

	memset(L , 0 , sizeof(L));
	memset(R , 0 , sizeof(R));
	memset(deg , 0 , sizeof(deg));


	for(i=0; i<n; i++){
		scanf("%d %d" , &a , &b);
		L[i] = a; R[i] = b;
		deg[a] ++ , deg[b]++;
		bone[i] = 1;
		Assign_int(value[i] , 1);
	}
}

void solve(){
	int i , j;
	BigNum tmp , t2;
	while(n > 1){
		// 并联
		for(i=0; n>1 && i<n; i++)
			for(j=i+1; j<n; j++)
				if(L[i] == L[j] && R[i] == R[j]){
					// Merge Bone[i] , Bone[j]
					--deg[L[i]] , --deg[R[i]];
					bone[i] += bone[j];
					multiply(tmp , value[i] , value[j]);
					C(bone[i] , bone[j] , t2);
					multiply(value[i] , tmp , t2);
					
					n--;
					value[j] = value[n];
					bone[j] = bone[n];
					L[j] = L[n]; R[j] = R[n];
					break;
				}
		// 串联
		for(i=0; i<n; i++)
			if(deg[R[i]] == 2){
				for(j=0; j<n; j++)
					if(L[j] == R[i]){
						R[i] = R[j];
						bone[i] += bone[j];
						multiply(tmp , value[i] , value[j]);
						value[i] = tmp;
						
						n--;
						value[j] = value[n];
						bone[j] = bone[n];
						L[j] = L[n]; R[j] = R[n];
						break;
					}
			}		
	}

	print(value[0]);
}

int main(){
	int T;
	scanf("%d" , &T);
	while(T--){
		init();
		solve();
	}
	
	return 0;
}
