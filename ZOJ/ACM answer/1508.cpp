//186475 2003-07-02 12:55:34 Wrong Answer 1508 C++ 00:00.70 2984K just for play 
//192124 2003-07-06 23:25:06 Accepted 1508 C++ 00:00.72 2984K just for play 
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

struct line_type
{
	int to,v;
	line_type(int t_to,int t_v)
	{
		to=t_to;
		v=t_v;
	}

};

int main()
{
//	freopen("1508.in","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,t;
		vector<line_type> line[50002];
		int a,b,c;int max=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(b>max)	max=b;
			line_type temp(a,-c);
			line[b+1].push_back(temp);
		}	
		int val[50002];max++;
		for(i=1;i<=max;i++)
		{
			line_type temp(i-1,0);
			line[i].push_back(temp);
		}
		memset(val,0,sizeof(val));
		for(i=max;i>=0;i--)
		{
			int t_to,t_v;
			for(j=0;j<line[i].size();j++)
			{
				t_to=line[i][j].to;
				t_v=line[i][j].v;
				if(val[t_to]>val[i]+t_v)
				{
					val[t_to]=val[i]+t_v;
					int cur=val[t_to]+1;
					for(t=t_to+1;;t++)
					{
						if(val[t]>cur)	val[t]=cur;
						else	break;
						cur++;
					}
				}
			}
		}
		printf("%d\n",-val[0]);
	}
	return 0;
}





