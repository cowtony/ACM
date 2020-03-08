#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[10001];
	int flag[10001];
	int flag2[10001];
	int i, j, k, t;
	while(scanf("%d%*c", &n) && n)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			flag[i] = 0;
		}
		t = 0;
		memset(flag, 0, n*sizeof(int));
		for(i=0; i<n-2; i++)
		{
			flag[a[i]] = 1;
			for(j=0; j<n; j++)
			{
				flag2[j] = flag[j];
			}
			for(j=i+1; j<n-1; j++)
			{
				flag2[a[j]] = 1;
				int temp = 2 * a[j] - a[i];
				if(temp >=n || temp<0) continue;
				if(flag2[temp] == 0) {t=1; break;}
			}
			if(t) break;
		}
		if(t) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}