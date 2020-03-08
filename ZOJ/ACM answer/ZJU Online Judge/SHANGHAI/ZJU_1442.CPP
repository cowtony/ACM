#include <stdio.h>
#include <string.h>

#define MAXLEN 50
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
	while(a.c[a.l+1]) a.l ++;		
}

void minus(BigNum& a , const BigNum& b){
	// BigNum a -= b
	// ÕâÀïÄ¬ÈÏa > b
	for(int i=1; i<=a.l; i++){
		a.c[i] -= b.c[i];
		if(a.c[i] < 0){
			a.c[i+1]--;
			a.c[i] += 10;
		}
	}
	while(a.l && !a.c[a.l]) a.l--;
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

void print(const BigNum& a){
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	if(a.l == 0) putchar('0');
	putchar('\n');
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
	if(m > n){
		ret.c[1] = 0; return;
	}
	for(i=n-m+1; i<=n; i++)
		mul_int(ret , i);
	for(i=1; i<=m; i++)
		div_int(ret , i);
}

/////////////////////////////////////////////////////////////////

int n , m , s;
int L[8];
BigNum a , b , t;

void solve(){
	if(m < 0 || m > s){
		puts("0"); return;
	}

	C(m + n - 1 , n - 1 , a);
	Assign_int(b , 0);

	int stat , cnt , mp , i;
	
	for(stat=((1<<n)-1); stat>0; stat--){
		mp = m; cnt = 0;
		for(i=0; i<n; i++)
			if(stat & (1<<i)){
				cnt++;
				mp = mp - L[i] - 1;
			}
		if(cnt % 2 == 0){
			C(mp - 1 + n , n - 1 , t);
			add(a , t);
		}
		else{
			C(mp - 1 + n , n - 1 , t);
			add(b , t);
		}
	}

	minus(a , b);

	print(a);	
}

int main(){	
	int T , k , i;
	scanf("%d" , &T);
	while(T--){
		scanf("%d %d" , &n , &m);
		for(i=s=0; i<n; i++){
			scanf("%d %d" , &k , &L[i]);
			m -= k;
			L[i] -= k;
			s+=L[i];
		}

		solve();
	}

	return 0;
}
