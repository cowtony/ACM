#include <stdio.h>
#include <string.h>

char s[300];

int find_right(int p)
{
	int cnt = 0;
	for(;;p++)
	{
		if(s[p] == '(') cnt++;
		else if(s[p] == ')') cnt--;
		if(!cnt) return p;
	}
}

int find_op(int p , int r)
{
	int ret = -1;
	for(; p<r; p++)
	{
		if(s[p] == '(') p = find_right(p);
		else if(s[p] == '+' || s[p] == '-') ret = p;
		else if ((s[p] == '*' || s[p] == '/') && (ret < 0 || s[ret] == '*' || s[ret] == '/')) ret = p;
	}
	return ret;
}

void print(int p , int r , int op)
{
	if(p + 1 == r)
	{
		putchar(s[p]); return;
	}
/*	if(s[p] == '(' && find_right(p) + 1 == r)
	{
		print(p + 1 , r - 1 , find_op(p + 1 , r - 1));
		return;
	}
*/

	// left side
	if(s[p] == '(' && find_right(p) + 1 == op)
	{		
		int lr = op;
		for(p++,lr--;s[p]=='('&&find_right(p)+1==lr;p++,lr--){}
		int nop = find_op(p , lr);

		if(nop >= 0 && (s[op] == '*' || s[op] == '/') && (s[nop] == '+' || s[nop] == '-'))
		{
			putchar('(');
			print(p , lr , nop);
			putchar(')');
		}
		else print(p , lr , nop);
	}
	else print(p , op , find_op(p , op));
	
	
	// mid op
	putchar(s[op]);

	// right side
	if(s[op + 1] == '(' && find_right(op + 1) + 1 == r)
	{	
		char peop = s[op];
		op++;
		for(op++,r--;s[op]=='('&&find_right(op)+1==r;op++,r--){}
		int nop = find_op(op , r);

		if(nop >= 0 && (peop == '/' || ((peop == '*' || peop == '-') && (s[nop] == '+' || s[nop] == '-'))))
		{
			putchar('(');
			print(op, r, nop);
			putchar(')');
		}
		else print(op , r , nop);
	}
	else print(op + 1 , r , find_op(op + 1 , r));
}

int main()
{
//	freopen("expr.in.txt" , "r" , stdin);
//	freopen("myout.txt" , "w" , stdout);

	int T , p , r;
	scanf("%d" , &T);

	while(T--)
	{
		scanf("%s" , s);
		p = 0; r = strlen(s);
		for(;s[p]=='(' && find_right(p) + 1 == r;p++,r--){}
		print(p , r , find_op(p , r));
		putchar('\n');
	}

	return 0;
}