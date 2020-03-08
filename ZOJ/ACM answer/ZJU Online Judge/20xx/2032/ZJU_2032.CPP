#include <stdio.h>
#include <string.h>

///////////////////////////////////////////////BigNum

#define MAXLEN 100
struct BigNum{
	int l;
	int c[MAXLEN + 1];
};

void assign_int(BigNum& a , int k){
	memset(a.c , 0 , sizeof(a.c));
	a.l = 0;
	while(k > 0){
		a.c[++a.l] = k % 10;
		k /= 10;
	}
}

void assign_str(BigNum& a , char* s){
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

void print(int k , const BigNum& a){
	if(a.l == 0 || a.l == 1 && a.c[1] == 0) return;
	printf("%d " , k);
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	putchar('\n');
}

////////////////////////////////////////////End of BigNum

int m , n;
int list[3][11][2];

void init()
{
	int i , j , t;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			scanf("%d%d" , &list[i][j][0] , &list[i][j][1]);
			if(list[i][j][0] > list[i][j][1])
			{
				t = list[i][j][0];
				list[i][j][0] = list[i][j][1];
				list[i][j][1] = t;
			}
		}
}

BigNum a , b , c , b2;

inline int min(int a , int b){ return a < b ? a : b ; }
inline int max(int a , int b){ return a > b ? a : b ; }

void solve()
{
	if(n == 1)
	{
		assign_int(a , 1);
		for(int i=0; i<m; i++)
			mul_int(a , list[0][i][1] - list[0][i][0]);
		print(1 , a);
	}
	else if(n == 2)
	{
		assign_int(a , 0);
		int p , i , r;
		for(p=0; p<2; p++)
		{
			assign_int(b , 1);
			for(i=0; i<m; i++)
				mul_int(b , list[p][i][1] - list[p][i][0]);
			add(a,b);
		}
		assign_int(b , 1);
		for(i=0; i<m; i++)
		{
			p = max(list[0][i][0] , list[1][i][0]);
			r = min(list[0][i][1] , list[1][i][1]);
			if(r <= p) break;
			mul_int(b , r - p);
		}
		if(i == m)
		{
			
			minus(a , b); minus(a , b); print(1 , a);
			print(2 , b);
		}
		else
		{
			
			print(1 , a);
		}
	}
	else
	{
		assign_int(a , 0);
		int p , i , j , r , k;
		for(p=0; p<3; p++)
		{
			assign_int(b , 1);
			for(i=0; i<m; i++)
				mul_int(b , list[p][i][1] - list[p][i][0]);
			add(a,b);
		}

		bool flag = 0;
		assign_int(b2 , 0);

		for(i=0; i<2; i++)
			for(j=i+1; j<3; j++)
			{
				assign_int(b , 1);
				for(k=0; k<m; k++)
				{
					p = max(list[i][k][0] , list[j][k][0]);
					r = min(list[i][k][1] , list[j][k][1]);
					if(r <= p) break;
					mul_int(b , r - p);
				}
				if(k == m)
				{
					flag = 1;
					add(b2 , b);
				}
			}
		
		if(!flag)
		{		
			print(1 , a);
		}
		else
		{
			assign_int(c , 1);
			for(i=0; i<m; i++)
			{
				p = max(list[0][i][0] , max(list[1][i][0] , list[2][i][0]));
				r = min(list[0][i][1] , min(list[1][i][1] , list[2][i][1]));
				if(r <= p) break;
				mul_int(c , r - p);
			}
			if(i == m)
			{
				b = c; mul_int(b , 3); minus(b2 , b);
				minus(a , b); b = b2; mul_int(b , 2); minus(a , b);
				print(1 , a);
				print(2 , b2);
 				print(3 , c);
			}
			else
			{
				minus(a , b2); print(1 , a);
				print(2 , b2);
			}
		}
	}	
}

int main()
{
	while(scanf("%d%d" , &m , &n) , m)
	{
		init();
		solve();
	}
	
	return 0;
}