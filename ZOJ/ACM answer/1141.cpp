#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	int p1,p2;
	int i,j;
	while(scanf("%d",&n) != EOF)
	{
		int *con = new int[n+1];
		int *temp = new int[n+1];
		for(i=0;i<=n;i++)
		{
			con[i]=0;
			temp[i]=0;
		}
		for(i=0; i<n; i++)
		{
			int parent, sonnum, son;
			scanf("%d:(%d)",&parent,&sonnum);
			for(j=0; j<sonnum; j++)
			{
				scanf("%d", &son);
				con[son] = parent;
			}
		}
		scanf("%d",&m);
		vector <int> per;
		for(i=0; i<m; i++)
		{
			char c;
			while(scanf("%c",&c)&&c!='(');
			scanf("%d,%d)",&p1,&p2);
			per.erase(per.begin(), per.end());
			while(p1)
			{
				per.push_back(p1);
				p1=con[p1];
			}
			while(p2)
			{
				if(find(per.begin(), per.end(),p2) != per.end())
				{
					temp[p2]++;
					break;
				}
				p2=con[p2];
			}
		}
		for(i=1; i<=n; i++)
		{
			if(temp[i])
			{
				printf("%d:%d\n", i, temp[i]);
			}
		}
		delete [] con;
		delete [] temp;
	}
	return 0;
}
