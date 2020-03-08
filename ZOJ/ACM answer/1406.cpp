#include <iostream>

int load[26][26];
int flag[26];
int tal[26];

int prim(int n)
{
	flag[0]=1;
	int temp1=0;
	int cost=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(load[temp1][j])
			{
				if( !tal[j] || load[temp1][j]<tal[j] )
				{
					tal[j] = load[temp1][j];
				}
			}
		}
		int temp2 = 200;
		int t;
		for(int j=0; j<n; j++)
		{
			if(tal[j] < temp2&&!flag[j]&&tal[j])
			{
				temp2 = tal[j];
				t = j;
			}
		}
		flag[t] = 1;
		cost += temp2;
		temp1=t;
	}
	return cost;
}


int main()
{
	int loadnum;
	int i,j;
	char s[5],str[5];
	int con,cost;
	while(scanf("%d",&loadnum)&&loadnum)
	{
		memset(flag,0,sizeof(flag));
		memset(load,0,sizeof(load));
		memset(tal,0,sizeof(tal));
		for(i=0;i<loadnum-1;i++)
		{
			scanf("%s%d",s,&con);
			for(j=0;j<con;j++)
			{
				scanf("%s%d",str,&cost);
				load[s[0]-65][str[0]-65]=load[str[0]-65][s[0]-65]=cost;
			}
		}
		printf("%d\n",prim(loadnum));
	}
	return 0;
}
