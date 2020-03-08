#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
	bool flag[13][13];
	double ai[13][2];
	int bi[13];
	int cas=1;
	int n;
	while(cin >> n && n)
	{
		memset(flag, false, sizeof(flag));
		memset(bi, 0, sizeof(bi));
		for(int i=0; i<n; i++)
		{
			cin >> ai[i][0] >> ai[i][1];
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i==j)
					continue;
				if(sqrt( (ai[i][0]-ai[j][0])*(ai[i][0]-ai[j][0]) + (ai[i][1]-ai[j][1])*(ai[i][1]-ai[j][1])) - 20.0 < 1e-10)
				{
					flag[i][j] = true;
					flag[j][i] = true;
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++)
		{
			if(bi[i] !=0)
				continue;
			deque <int> temp;
			temp.push_back(i);
			while(!temp.empty())
			{
				bool ff[14];
				memset(ff, 0, sizeof(ff));
				int out=temp.front();
				temp.pop_front();
				for(int j=0; j<n; j++)
				{
					if(flag[out][j] == true)
					{
						if(bi[j] == 0)
						{
							temp.push_back(j);
							
						}
						else
						{
							ff[bi[j]] = true;
						}
					}
				}
				for(int j=1; j<14; j++)
				{
					if(!ff[j])
					{
						bi[out] = j;
						if(j>ans)
							ans=j;
						break;
					}
				}
			}
		}
		printf("The towers in case %d can be covered in %d frequencies.\n", cas++, ans);
	}
	return 0;
}