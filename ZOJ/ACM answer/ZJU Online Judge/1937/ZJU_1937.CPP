#include <stdio.h>
#include <string.h>

int n;
int limit;

int list[100];
bool valid[20][201];
bool spit[20][201];

void calc(int cnt)
{
	int i , j;
	memset(valid[cnt] , 0 , n + 1);
	for(i=0; i<cnt; i++)
		for(j=i; j<cnt; j++)
			valid[cnt][list[i] + list[j]] = 1;
}

bool search(int low , int cnt)
{
	calc(cnt);
	if(valid[cnt][n])
	{
		list[cnt] = n;
		for(int i=0; i<cnt; i++) printf("%d " , list[i]);
		printf("%d\n" , list[cnt]);

		return 1;
	}
	if(cnt + 1 == limit) return 0;

	/*
	int i;
	for(i=n-1; i>=low; i--)
		if(valid[cnt][i])
		{		
			list[cnt] = i;
			if(search(i + 1 , cnt + 1)) return 1;		
		}
	*/
	int i , j , k;
	memset(spit[cnt] , 0 , n);		 
	for(i=cnt-1; i>=0; i--)
		for(j=i; j>=0; j--)
		{
			k = list[i] + list[j];			
			if(k < n && k >= low)
			{
				if(spit[cnt][k]) continue;
				spit[cnt][k] = 1;
				list[cnt] = k;
				if(search(k+1 , cnt+1)) return 1;
			}
		}

	return 0;
}

void solve()
{
	list[0] = 1; list[1] = 2;

	for(limit = tlimit; ; limit++)
	{
		if(search(3 , 2)) break;
	}
}

int main()
{
	freopen("tmp/myout.txt" , "w" , stdout);
	while(scanf("%d" , &n) , n)
	{
		if(n == 1)
		{
			puts("1");
		}
		else if(n == 2)
		{
			puts("1 2");
		}
		else solve();
	}

	return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char buf[200];
	freopen("tmp/myout.txt" , "r" , stdin);
	while(gets(buf) > 0)
	{
		puts(buf);
	}	
	return 0;
}
*/