#include <stdio.h>

int main()
{	
	int n , m;
	while(scanf("%d%d" , &n , &m) , n || m)
	{
		if( m > n ) puts("0");
		else if(m == 0 || m == n) puts("1");
		else if(m == 1 || m == n-1) printf("%d\n" , n);
		else
		{
			double ret = 1;
			int i,j;
			for(i=n-m+1,j=1; i<=n; i++,j++)
			{
				ret *= i;
				if(j<=m) ret /= j;
			}
			
			printf("%.0lf\n" , ret);
		}
	}	
	
	return 0;
}
