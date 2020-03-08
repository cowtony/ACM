/*
  按位存储十进制高精度库
    - Failed Bamboo
	       2004-2-6
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 110
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

void print(const BigNum& a){
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	putchar('\n');
}

BigNum f[600];
BigNum a , b , tmp;

int main(){	
	int i , c;

	Assign_int(f[0] , 1);
	Assign_int(f[1] , 1);
	for(i=2; ; i++)
	{
		f[i] = f[i-1];
		add(f[i] , f[i-2]);
		if(f[i].l > 101) break;
	}
	c = i;

	char s1[110] , s2[110];
	while(scanf("%s%s" , s1 , s2))
	{
		if(strcmp(s1 , "0") == 0 && strcmp(s2 , "0") == 0)
		{
			break;
		}
		Assign_str(a , s1);
		Assign_str(b , s2);
		/*
		if(comp(a , b) > 0)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		*/

		int cnt = 0;
		for(i=1; i<=c; i++)
		{
			if(comp(f[i] , b) > 0) break;
			if(comp(a , f[i]) <= 0) cnt++;
		}
		printf("%d\n" , cnt);
	}
		

	return 0;
}
