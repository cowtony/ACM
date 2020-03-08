#include <iostream>
using namespace std;

int main()
{
	int a[200001][2];
	int i;
	int n;
	int Stan, Ollie;
	while(scanf("%d", &n) && n)
	{
		Stan = Ollie = 0;
		int len = (n+1)/2;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &a[i][0], &a[i][1]);
		}
		for(i=0; i<n; i++)
		{
			if(a[i][0] > a[len-1][0] && a[i][1] > a[len-1][1]) Stan++;
			else if(a[i][0] < a[len-1][0] && a[i][1] < a[len-1][1]) Stan++;
			else if(a[i][0] > a[len-1][0] && a[i][1] < a[len-1][1]) Ollie++;
			else if(a[i][0] < a[len-1][0] && a[i][1] > a[len-1][1]) Ollie++;
		}
		printf("%d %d\n", Stan, Ollie);
	}
	return 0;
}
	