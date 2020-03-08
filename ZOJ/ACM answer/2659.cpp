#include <iostream>
#include <vector>
using namespace std;

void inter(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

int main()
{
	int a[6][2];
	int i,j;
	while(scanf("%d%d",&a[0][0],&a[0][1])!=EOF)
	{
		if(a[0][0]>a[0][1]) 
		{
			inter(a[0][0],a[0][1]);
		}
		for(i=1; i<6; i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			if(a[i][0]>a[i][1]) inter(a[i][0],a[i][1]);
		}
		for(i=0; i<6; i++)
		{
			for(j=i+1; j<6; j++)
			{
				if(a[i][0]>a[j][0])
				{
					inter(a[i][0],a[j][0]);
					inter(a[i][1],a[j][1]);
				}
				else if(a[i][0]==a[j][0]&&a[i][1]>a[j][1])
				{
					inter(a[i][0],a[j][0]);
					inter(a[i][1],a[j][1]);
				}
			}
		}
		int t=0;
		if(a[0][0]!=a[1][0]||a[0][1]!=a[1][1]) t=1;
		if(a[2][0]!=a[3][0]||a[2][1]!=a[3][1]) t=1;
		if(a[4][0]!=a[5][0]||a[4][1]!=a[5][1]) t=1;
		if(t) {printf("IMPOSSIBLE\n");continue;}
		t=0;
		if(a[0][0]==a[2][0]||a[0][0]==a[2][1]) t=1;
		if(a[0][1]==a[2][0]||a[0][1]==a[2][1]) t=1;
		if(!t) {printf("IMPOSSIBLE\n");continue;}
		t=0;
		if(a[0][0]==a[4][0]||a[0][0]==a[4][1]) t=1;
		if(a[0][1]==a[4][0]||a[0][1]==a[4][1]) t=1;
		if(!t) {printf("IMPOSSIBLE\n");continue;}
		t=0;
		if(a[4][0]==a[2][0]||a[4][0]==a[2][1]) t=1;
		if(a[4][1]==a[2][0]||a[4][1]==a[2][1]) t=1;
		if(!t) {printf("IMPOSSIBLE\n");continue;}
		vector <int> svec;
		vector <int>::iterator iter;
		for(i=0; i<6; i++)
		{
			for(j=0; j<2; j++)
			{
				t=0;
				for(iter=svec.begin(); iter!=svec.end(); iter++)
				{
					if(*iter==a[i][j]) {t=1;break;}
				}
				if(!t) svec.push_back(a[i][j]);
			}
		}
		if(svec.size()>3)  {printf("IMPOSSIBLE\n");continue;}
		else printf("POSSIBLE\n");
	}
	return 0;
}
