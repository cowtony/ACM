#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char lab[101];
int list[101];

void init()
{
	for(int i=0; i<n; i++)
		scanf("%d" , list + i);
}

void solve()
{
	int delta;
	int s0 , s1;
	int i , j;

	s0 = s1 = 0;
	for(i=0; i<n/2; i++)
	{
		lab[i] = 0;
		s0 += list[i];
	}
	for(;i<n; i++)
	{
		lab[i] = 1;
		s1 += list[i];
	}

	delta = s0 - s1;

	bool modify = 1;

	while(modify)
	{
		modify = 0;

		for(i=0; i<n; i++)
			if(lab[i] == 0)
			{
				for(j=0; j<n; j++)
					if(lab[j] == 1)
					{
						if(abs(delta + list[j] * 2 - list[i] * 2) < abs(delta))
						{
							modify = 1;
							lab[i] = 1; lab[j] = 0;
							s0 = s0 + list[j] - list[i];
							s1 = s1 + list[i] - list[j];
							delta = s0 - s1;
							goto next;
						}
					}
			}
		next :	;
	}

	if(s0 > s1)
	{
		int t = s0; s0 = s1; s1 = t;
	}

	printf("%d %d\n" , s0 , s1);
}

int main()
{
	while(scanf("%d" , &n) > 0)
	{
		init();
		solve();
	}

	return 0;
}