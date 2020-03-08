#include <iostream>
#include <deque>
using namespace std;

int main()
{
	bool flag[1005];
	bool have[1005];
	int cas=1;
	while(1)
	{
		
		deque <int> ai[1001];
		int a, b;
		int max=0;
		cin >> a;
		if(a==0)
			return 0;
		if(cas!=1)
			cout << endl;
		memset(have, false, sizeof(have));
		have[a] = true;
		cin >> b;
		have[b] = true;
		if(a>max)
			max = a;
		if(b>max)
			max = b;
		ai[a].push_back(b);
		ai[b].push_back(a);
		while(cin >> a && a)
		{
			cin >> b;
			ai[a].push_back(b);
			ai[b].push_back(a);
			if(a>max)
				max = a;
			if(b>max)
				max = b;
			have[a] = true;
			have[b] = true;
		}
		bool found = false;
		cout << "Network #" << cas++ << endl;
		for(int i=1; i<=max; i++)
		{
			int count=0;
			if(!have[i])
				continue;
			memset(flag, false, sizeof(bool) * (max+2));
			for(int j=1; j<=max; j++)
			{
				if(j==i)
					continue;
				if(flag[j])
					continue;
				if(!have[j])
					continue;
				count++;
				deque <int> temp(1, j);
				flag[j] = true;
				while(!temp.empty())
				{
					int tt = temp.front();
					temp.pop_front();
					for(int ind=0; ind<ai[tt].size(); ind++)
					{
						if(ai[tt][ind] == i)
							continue;
						if(flag[ai[tt][ind]] == false)
						{
							flag[ai[tt][ind]] = true;
							temp.push_back(ai[tt][ind]);
						}
					}
				}
			}
			if(count>1)
			{
				cout << "  SPF node " << i << " leaves " << count << " subnets" << endl;
				found = true;
			}
		}
		if(!found)
		{
			cout << "  No SPF nodes" << endl;
		}
	}
	return 0;
}