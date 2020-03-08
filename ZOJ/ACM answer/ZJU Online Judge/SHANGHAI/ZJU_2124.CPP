#include <stdio.h>
#include <math.h>

double k;
int mark;

void solve()
{
	double root;
	for(int p=32; p; p--)
	{
		root = floor(pow(k , 1.0 / p) + 1e-5);
		if(pow(root , p) == k && (mark == 0 || p % 2 == mark))
		{
			printf("%d\n" , p);
			break;
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%lf" , &k);
		if(k == 0) break;
		if(k < 0)
		{
			k = -k;
			mark = 1;
		}
		else mark = 0;
		solve();
	}

	return 0;
}