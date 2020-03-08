#include <iostream>
using namespace std;

int main()
{
	int a[10001];
	int i, j;
	int n, m;
	int t1, t2;
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		int count = 0;
		cin >> n >> m;
		memset(a, 0, (n+1)*sizeof(int));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &t1, &t2);
			a[t1]++;
			count += 2* (a[t1]-1);
			a[t2]++;
			count += 2* (a[t2]-1);
		}
		count += 2 * m;
		printf("%d\n", count);
		if(cas) printf("\n");
	}
	return 0;
}