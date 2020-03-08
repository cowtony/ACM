#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct node
{
	deque <int> great;
	deque <int> less;
}a[100];

void eras(int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		a[i].great.erase(a[i].great.begin(),a[i].great.end());
		a[i].less.erase(a[i].less.begin(), a[i].less.end());
	}
}

bool search(int m, int n)
{
	deque <int> big;
	deque <int> sma;
	int i, j;
	for(i=0; i<a[m].great.size(); i++)
	{
		if(find(big.begin(), big.end(), a[m].great[i]) == big.end())
		{
			big.push_back(a[m].great[i]);
		}
	}
	for(i=0; i<a[m].less.size(); i++)
	{
		if(find(sma.begin(), sma.end(), a[m].less[i]) == sma.end())
		{
			sma.push_back(a[m].less[i]);
		}
	}
	int index = 0;
	while(index < big.size())
	{
		for(i=0; i<a[big[index]].great.size(); i++)
		{
			if(find(big.begin(), big.end(), a[big[index]].great[i]) == big.end())
			{
				big.push_back(a[big[index]].great[i]);
			}
		}
		index++;
	}
	index = 0;
	while(index <sma.size())
	{
		for(i=0; i<a[sma[index]].less.size(); i++)
		{
			if(find(sma.begin(), sma.end(), a[sma[index]].less[i]) == sma.end())
			{
				sma.push_back(a[sma[index]].less[i]);
			}
		}
		index++;
	}
	if(big.size() >n/2 || sma.size() > n/2) return true;
	else return false;
}

int main()
{
	int cas;
	int n, t;
	int b,s;
	cin >> cas;
	while(cas--)
	{
		cin >> n >> t;
		eras(n);
		for(int i=0; i<t; i++)
		{
			cin >> b >> s;
			a[b].less.push_back(s);
			a[s].great.push_back(b);
		}
		int ans = 0;
		for(int i=1; i<=n; i++)
		{
			bool tr = search(i, n);
			if(tr) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

