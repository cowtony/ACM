#include <stdio.h>
#include <string.h>

#define max_len 1010
struct BigInt
{
	int l , c[max_len];
}; 

char s1[max_len] , s2[max_len] , op;
BigInt a , b , c , tmp;

void assign_int(BigInt& a , char* s)
{
	a.l = strlen(s);
	memset(a.c , 0 , sizeof(a.c));
	for(int i=1; i<=a.l; i++)
	{
		a.c[i] = s[a.l-i] - '0';
	}
}

void init()
{
	char ch;
	char *s = s1;
	while(1)
	{
		ch = getchar();
		if(ch == '+' || ch == '-' || ch == '*') break;
		*s = ch; *s++;
	}
	*s = 0;

	op = ch;

	s = s2;
	while(1)
	{
		ch = getchar();
		if(ch == '\n') break;
		*s = ch; *s++;
	}
	*s = 0;

	assign_int(a , s1);
	assign_int(b , s2);
}

int maxlen;

inline int max(int a , int b)
{
	return a > b ? a : b;
}

void add(BigInt& c , const BigInt& a , const BigInt& b)
{
	c.l = max(a.l , b.l);
	memset(c.c , 0 , sizeof(c.c));
	for(int i=1; i<=c.l; i++)
	{
		c.c[i] += a.c[i] + b.c[i];
		c.c[i+1] = c.c[i] / 10;
		c.c[i] %= 10;
	}
	if(c.c[c.l + 1])
	{
		c.l++;
	}
}

void minus(BigInt& c , const BigInt& a , const BigInt& b)
{
	c.l = a.l;
	memset(c.c , 0 , sizeof(c.c));
	int i;
	for(i=1; i<=c.l; i++)
	{
		c.c[i] += (a.c[i] - b.c[i]);
		if(c.c[i] < 0)
		{
			c.c[i] += 10;
			c.c[i+1]--;
		}
	}
	while(c.l > 1 && c.c[c.l] == 0)
	{
		c.l--;
	}
}

void multiply(BigInt& c , const BigInt& a , const BigInt& b)
{
	memset(c.c , 0 , sizeof(c.c));
	c.l = a.l + b.l - 1;
	int i , j;
	for(i=1; i<=a.l; i++)
		for(j=1; j<=b.l; j++)
		{
			c.c[i+j-1] += a.c[i] * b.c[j];
		}
	for(i=1; i<=c.l; i++)
	{
		c.c[i+1] += c.c[i] / 10;
		c.c[i] %= 10;
	}
	while(c.c[c.l+1])
	{
		c.l++;
		c.c[c.l+1] = c.c[c.l] / 10;
		c.c[c.l] %= 10;
	}
	while(c.l > 1 && c.c[c.l] == 0)
	{
		c.l--;
	}
}

void multiply_int(BigInt& c , const BigInt& a , const int k)
{
	memset(c.c , 0 , sizeof(c.c));
	c.l = a.l;
	int i;
	for(i=1; i<=a.l; i++)
	{
		c.c[i] += a.c[i] * k;
		c.c[i+1] = c.c[i] / 10;
		c.c[i] %= 10;
	}
	while(c.c[c.l+1])
	{
		c.l++;
		c.c[c.l+1] = c.c[c.l] / 10;
		c.c[c.l] %= 10;
	}
	while(c.l > 1 && c.c[c.l] == 0)
	{
		c.l--;
	}
}

void print_without_op(BigInt& a)
{
	int i;
	for(i=maxlen-a.l; i>0; i--) putchar(' ');
	for(i=a.l; i>0; i--) printf("%d" , a.c[i]);
	putchar('\n');
}

void print_with_op(BigInt& a)
{
	int i;
	for(i=maxlen-a.l; i>1; i--) putchar(' ');
	putchar(op);
	for(i=a.l; i>0; i--) printf("%d" , a.c[i]);
	putchar('\n');
}

void solve_add()
{
	add(c , a , b);
	maxlen = max(max(a.l , b.l + 1) , c.l);
	print_without_op(a);
	print_with_op(b);
	
	int curt_len = max(b.l+1 , c.l) , i;
	for(i=maxlen-curt_len; i; i--) putchar(' ');
	for(i=0; i<curt_len; i++) putchar('-');

	putchar('\n');
	print_without_op(c);
}

void solve_minus()
{
	minus(c , a , b);
	maxlen = max(a.l , b.l+1);
	print_without_op(a);
	print_with_op(b);

	int curt_len = max(b.l+1 , c.l) , i;
	for(i=maxlen-curt_len; i; i--) putchar(' ');
	for(i=0; i<curt_len; i++) putchar('-');

	putchar('\n');
	print_without_op(c);
}

void solve_multiply_0()
{
	multiply(c , a , b);
	maxlen = max(c.l , max(a.l , b.l+1));
	print_without_op(a);
	print_with_op(b);	

	int curt_len = max(b.l+1 , c.l) , i;
	for(i=maxlen-curt_len; i; i--) putchar(' ');
	for(i=0; i<curt_len; i++) putchar('-');

	putchar('\n');
	print_without_op(c);
}

void solve_multiply()
{
	multiply(c , a , b);
	multiply_int(tmp , a , b.c[1]);
	maxlen = max(max(a.l , b.l+1) , c.l);
	
	print_without_op(a);
	print_with_op(b);

	int curt_len = max(tmp.l , b.l+1);
	int i;

	for(i=maxlen-curt_len; i; i--) putchar(' ');
	for(i=0; i<curt_len; i++) putchar('-');
	putchar('\n');

	for(i=1; i<=b.l; i++)
	{
		multiply_int(tmp , a , b.c[i]);
		print_without_op(tmp);
		maxlen--;
	}

	maxlen = max(max(a.l , b.l+1) , c.l);
	for(i=maxlen-c.l; i; i--) putchar(' ');
	for(i=0; i<c.l; i++) putchar('-');
	putchar('\n');
	print_without_op(c);
}

int main()
{
//	freopen("arith.in.txt" , "r" , stdin);
//	freopen("myout.txt" , "w" , stdout);
	
	int T;
	scanf("%d\n" , &T);

	while(T--)
	{
		init();
		if(op == '+') solve_add();
		if(op == '-') solve_minus();
		if(op == '*')
		{
			if(b.l == 1) solve_multiply_0();
			else solve_multiply();
		}
		putchar('\n');
	}
	
	return 0;
}
