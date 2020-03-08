#include <stdio.h>
#include <string.h>

int n;
int limit;

int list[100];
bool valid[201];
bool tv[20][201];

bool search(int low , int cnt)
{
	if(valid[n])
	{
		list[cnt] = n;
		for(int i=0; i<cnt; i++) printf("%d " , list[i]);
		printf("%d\n" , list[cnt]);

		return 1;
	}
	if(cnt + 1 == limit) return 0;

	int tmp =0 , k = list[cnt-1];
	while(k < n)
	{
		k <<= 1;
		tmp++;
	}
	if(cnt + tmp > limit) return 0;

	int i , j;
	for(i=n-1; i>=low; i--)
		if(valid[i])
		{
			list[cnt] = i;
			memcpy(tv[cnt] , valid , n + 1);
			for(j=0; j<cnt; j++)
				valid[list[j] + i] = 1;	
			valid[i<<1] = 1;
			if(search(i + 1 , cnt + 1)) return 1;
			memcpy(valid , tv[cnt] , n + 1);
		}
	
	return 0;
}

void solve()
{
	list[0] = 1; list[1] = 2;
	memset(valid , 0 , sizeof(valid));
	valid[1] = valid[2] = valid[3] = valid[4] = 1;		 

	int tlimit , k = n;
	tlimit = 0;

	while(k)
	{
		tlimit++;
		k>>=1;
	}
	if(tlimit < 3) limit = 3;

	for(limit = tlimit; ; limit++)
	{
		if(search(3 , 2)) break;
	}
}

int main()
{
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