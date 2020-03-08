#include <stdio.h>
#include <string.h>

int k , a , b;

#define MAXLEN 200
struct BigNum{
	int l;
	int c[MAXLEN + 1];
};

BigNum A , W;

void assign_int(BigNum& a , int k){
	memset(a.c , 0 , sizeof(a.c));
	a.l = 0;
	while(k > 0){
		a.c[++a.l] = k % 10;
		k /= 10;
	}
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

void print(const BigNum& a){
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	putchar('\n');
}

void solve()
{
	int p = a / b , i , j;
	assign_int(A , 1);
	assign_int(W , 1);

	for(i=1; i<p; i++)
	{
		for(j=0; j<b; j++)
		{
			mul_int(W , k);
			if(W.l > 100)
			{
				puts("is not an integer with less than 100 digits.");
				return;
			}
		}
		add(A , W);
		if(A.l > 100)
		{
			puts("is not an integer with less than 100 digits.");
			return;
		}
	}

	print(A);
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d%d%d" , &k , &a , &b) > 0)
	{
		printf("(%d^%d-1)/(%d^%d-1) " , k , a , k , b);
		if(k == 1 || a % b != 0) puts("is not an integer with less than 100 digits.");
		else solve();
	}

	return 0;
}