#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n;
char list[1024];

bool read_line()
{
	char ch = getchar();
	if(ch == -1) return 0;
	
	n = 0;
	
	while(ch != '\n')
	{
		if(isalpha(ch))
		{
			list[n++] = toupper(ch);
		}
		ch = getchar();
	}
	list[n] = 0;
	
	return 1;
}

struct palind
{
	int len;
	char s[200];
	bool valid;
} lx[50] , ly[50];	//odd len , even len
int cx , cy;

struct str
{
	char s[400];
} f[100];

int cmp(const void* a , const void* b)
{
	return strcmp(((palind*)a)->s , ((palind*)b)->s);
}

int cmp1(const void* a,  const void* b)
{
	return strcmp(((str*)a)->s , ((str*)b)->s);
}

void doit(palind l[] , int c)
{
	qsort((void *)l , c , sizeof(palind) , cmp);
	int i , j;
	for(i=0; i<c-1; i++)
	{
		if(l[i].len > l[i+1].len) l[i].valid = 1;
		else
		{
			for(j=0; j<l[i].len; j++)
			{
				if(l[i].s[j] != l[i+1].s[j]) break;				
			}
			l[i].valid = (j<l[i].len);
		}
	}
	l[c-1].valid = 1;
}

void solve()
{
	int i , j , p , r;

	cx = 0;
	for(i=0; i<n; i++)
	{
		lx[cx].len = 1; lx[cx].s[0] = list[i];
		for(p = i - 1 , r = i + 1; p>=0 && r<n; p-- , r++)
		{
			if(list[p] != list[r]) break;
			lx[cx].s[lx[cx].len++] = list[p];
		}		
		if(p < r - 2) cx++;
		lx[cx].s[lx[cx].len] = 0;
	}
	
	cy = 0;
	for(i=0; i<n; i++)
	{
		ly[cy].len = 0;
		for(p=i-1 , r=i; p>=0 && r<n; p--,r++)
		{
			if(list[p] != list[r]) break;
			ly[cy].s[ly[cy].len++] = list[p];
		}
		if(p < r - 1) cy++;
		ly[cy].s[ly[cy].len] = 0;
	}

	doit(lx , cx);
	doit(ly , cy);

	int len = 0;

	for(i=0; i<cx; i++)
		if(lx[i].valid)
		{
			for(j=0; j<lx[i].len; j++)
			{
				f[len].s[lx[i].len + j - 1] = f[len].s[lx[i].len - j - 1] = lx[i].s[j];
			}
			f[len].s[lx[i].len * 2 - 1] = 0;
			len++;
		}
	for(i=0; i<cy; i++)
		if(ly[i].valid && ly[i].len > 1)
		{
			for(j=0; j<ly[i].len; j++)
			{
				f[len].s[ly[i].len + j] = f[len].s[ly[i].len - j - 1] = ly[i].s[j];
			}
			f[len].s[ly[i].len * 2] = 0;
			len++;
		}
		
	qsort((void *)f , len , sizeof(str) , cmp1);

	for(i=0; i<len; i++)
	{
		if(i) putchar(' ');
		printf("%s" , f[i].s);
	}
	putchar('\n');
}

int main()
{
//	freopen("palin.txt" , "r" , stdin);

	while(read_line())
	{
		solve();
	}
	
	return 0;
}
