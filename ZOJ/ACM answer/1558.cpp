#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	int cas;
	int a[6];
	int con[1001];
	cin >> cas;
	while(cas--)
	{
		memset(con, 0, sizeof(con));
		for(int i=0; i<6; i++)
		{
			cin >> a[i];
		}
		deque <int> coins;
		for(int j=0; j<6; j++)
		{
			coins.push_back(a[j]);
			con[a[j]] = 1;
		}
		while(!coins.empty())
		{
			int temp = coins.front();
			coins.pop_front();
			for(int j=0; j<6; j++)
			{
				if(temp+a[j] <=1000 && con[temp+a[j]] == 0)
				{
					con[temp+a[j]] = con[temp]+1;
					coins.push_back(temp+a[j]);
				}
				if(temp-a[j] >0 && con[temp-a[j]] == 0)
				{
					con[temp-a[j]] = con[temp] + 1;
					coins.push_back(temp-a[j]);
				}
			}
		}
		int total = 0;
		int max= 0;
		for(int i=1; i<=100; i++)
		{
			if(max < con[i])
				max = con[i];
			total += con[i];
		}
		printf("%.2lf %d\n", (double)total/100.0, max);
	}
	return 0;
}