#include <iostream>
using namespace std;

int main()
{
	int cas;
	int n, i;
	int c;
	int sto;
	scanf("%d", &cas);
	while(cas--)
	{
		int count = 0;
		scanf("%d",&n);
		scanf("%d", &c);
		if(c>1) count++;
		for(i=1; i<n; i++)
		{
			scanf("%d", &sto);
			c^=sto;
			if(sto>1) count++;
		}
		if(c==0) 
		{
			if(count == 0) printf("1\n");
			else printf("2\n");
		}
		else
		{
			if(count == 0) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}