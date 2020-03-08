#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char str[12][110];
int cnt[12][30][30];

void init()
{
	scanf("%s" , str[0]);
	scanf("%d" , &n);
	for(int i=1; i<=n; i++)
		scanf("%s" , str[i]);
}

/************ defination
<formula> ::= [<number>] <sequence> { '+' [<number>] <sequence> } 
<sequence> ::= <element> [<number>] { <element> [<number>] } 
<element> ::= <chem> | '(' <sequence> ')' 
<chem> ::= <uppercase_letter> [ <lowercase_letter> ] 
<uppercase_letter> ::= 'A'..'Z' 
<lowercase_letter> ::= 'a'..'z' 
<number> ::= '1'..'9' { '0'..'9' } 
*/

inline int find_next(int id , int p)
{
	int cnt = 0;
	for(;;p++)
	{
		if(str[id][p] == '(') cnt++;
		if(str[id][p] == ')') cnt--;
		if(cnt == 0) return p;
	}
}

void sequence(int id , int p , int r , int w)
{	
	char c1 , c2;
	int m , k , w2;

	while(p < r)
	{
		if(str[id][p] == '(')
		{			
			m = find_next(id , p);			
			k = m + 1;
			
			if(k < r && isdigit(str[id][k]))
			{
				w2 = 0;
				while(k < r && isdigit(str[id][k]))
				{
					w2 = w2 * 10 + str[id][k] - '0';
					k++;
				}
			}
			else w2 = 1;

			sequence(id , p+1 , m , w * w2);
			p = k;
		}
		else{
			c1 = str[id][p++] - 'A';
			if(islower(str[id][p]))	c2 = str[id][p++] - 'a';		
			else c2 = 26;
			
			if(p < r && isdigit(str[id][p]))
			{
				w2 = 0;
				while(p < r && isdigit(str[id][p]))
				{
					w2 = w2 * 10 + str[id][p] - '0';
					p++;
				}
			}
			else w2 = 1;

			cnt[id][c1][c2] += w * w2;
		}
	}
}

void with_num_sequence(int id , int p , int r)
{
	if(isdigit(str[id][p]))
	{
		int w = 0;
		while(p < r && isdigit(str[id][p]))
		{
			w = w * 10 + str[id][p] - '0';
			p++;
		}
		sequence(id , p , r , w);
	}
	else sequence(id , p , r , 1);
}

void formula(int id , int p , int r)
{
	int m;
	for(m = p; m<r; m++)
	{
		if(str[id][m] == '+')
		{
			with_num_sequence(id , p , m);
			p = m + 1;
		}
	}
	with_num_sequence(id , p , r);	
}

void solve()
{
	int i;

	memset(cnt , 0 , sizeof(cnt));
	for(i=0; i<=n; i++)
	{
		formula(i , 0 , strlen(str[i]));
	}
	
	bool flag;
	char c1, c2;

	for(i=1; i<=n; i++)
	{
		flag = 1;
		for(c1=0; c1<26; c1++)
			for(c2=0; c2<=26; c2++)
				if(cnt[0][c1][c2] != cnt[i][c1][c2]) 
					flag = 0;
		printf("%s%c=%s\n" , str[0] , flag ? '=' : '!' , str[i]);
	}
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T , t;
	scanf("%d" , &T);
	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		init();
		solve();
	}
	return 0;
}